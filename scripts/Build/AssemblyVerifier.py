import os
import fnmatch
import sys
import xml.etree.ElementTree

def IsItemDeclared(itemName, assemblyName, itemList):
	for currentItem in itemList:
		if currentItem[0] == itemName and currentItem[2] == assemblyName:
			return True
	
	return False

def CheckItemInclusion(sourceLocations, itemList):
	included = set()
	excluded = set()
	completeSet = set()
	currentAssembly = ""
	commentCount = 0
	
	for currentItem in itemList:
		completeSet.add(currentItem[0] + " " + currentItem[2])

	for currentSrc in GetFilesFromLocations(sourceLocations, ['*lib.c', '*asm.c', '*app.c']):
		commentCount = 0
		fileHandle = open(currentSrc, 'r')
		lines = fileHandle.readlines()
		
		for currentLine in lines:
			if currentLine.find('/*') > -1:
				commentCount += 1
			if currentLine.find('*/') > -1:
				commentCount -= 1
			if commentCount == 0: 
				if currentLine.find('kBeginAssembly') > -1 and currentLine.replace(' ', '').find('//kBeginAssembly') < 0:
					currentAssembly = currentLine.split('(')[1].split(',')[0]
				elif currentLine.find('kAddType') > -1 and currentLine.replace(' ', '').find('//kAddType') < 0:
					currentType = currentLine.split('(')[1].split(')')[0]
					if not IsItemDeclared(currentType, currentAssembly, itemList):
						excluded.add(currentType + " " + currentAssembly)
					else:
						included.add(currentType + " " + currentAssembly)
		
		fileHandle.close()
	#traverse source locations looking for source files with names that match the specified assembly
	if len(excluded) > 0 or len(completeSet - included) > 0:
		for currentItem in excluded:
			itemName = currentItem.split(' ')[0]
			assemblyPrefix = currentItem.split(' ')[1]
			print(itemName + ": warning: This type was mentioned in the assembly definition, but has no declaration (assembly prefix: " + assemblyPrefix  + ").")
		diffSet = completeSet - included
		for currentItem in diffSet:
			itemName = currentItem.split(' ')[0]
			assemblyPrefix = currentItem.split(' ')[1]
			print(itemName + ": warning: This type was declared, but not added to the assembly definition (assembly prefix: " + assemblyPrefix + ").")


def CollateItems(headerLocations, itemList):
	commentCount = 0

	for currentHeader in GetFilesFromLocations(headerLocations, ['*.h']):
		commentCount = 0
		fileHandle = open(currentHeader, 'r')
		lines = fileHandle.readlines()
		
		for currentLine in lines:
			if currentLine.find('/*') >= 0:
				commentCount += 1
			if currentLine.find('*/') >= 0:
				commentCount -= 1
			if commentCount == 0:
				if currentLine.find('kDeclare') > -1 and currentLine.replace(' ', '').find('//kDeclare') < 0 and (currentLine.find('Interface') > -1 or currentLine.find('Class') > -1 or currentLine.find('Class') > -1 or currentLine.find('Value') > -1):
					parameters = currentLine.split('(')[1].split(')')[0].split(',')
					
					assemblyName = parameters[0].strip()
					itemName = parameters[1].strip()
					parentItem = parameters[2].strip() if len(parameters) == 3 else ""
					itemEntry = [itemName, parentItem, assemblyName]
					itemList += [itemEntry]
		
		fileHandle.close()		
				#collect overridden function declarations? - anything with V after the underscore? 

def GetFilesFromLocations(locations, suffixes):
	for location in locations:
		if os.path.isdir(location):
			files = GetDirectoryFiles(location)
		else:
			files = GetProjectFiles(location)
		for filename in files:
			for suffix in suffixes:
				if fnmatch.fnmatch(filename, suffix):
					yield filename

def GetProjectFiles(location):
	directory = os.path.dirname(location)
	project = xml.etree.ElementTree.parse(location)
	root = project.find("./Sources") 
	for filename in ParseSourceTag(root):
		yield os.path.normpath(os.path.join(directory, filename))

def ParseSourceTag(item):
	for child in item:
		if child.tag == "Source":
			yield child.text
		elif child.tag == "SourceGroup":
			for filename in ParseSourceTag(child):
				yield filename

def GetDirectoryFiles(location):
	for root, dirnames, filenames in os.walk(location):
		for filename in filenames:
			yield os.path.join(root, filename)

if __name__ == "__main__":
	itemList = []
	
	if len(sys.argv) == 2:
		srcLocations = [sys.argv[1]]
		CollateItems(srcLocations, itemList)
		#print("The following classes, values, and interfaces were declared: ", itemList)
		#ConfirmOverriddenFunctionSpecification(srcLocations, itemList)	#traverse source files to confirm that they have been specified properly in kBeginClass
		#confirm that they have an associated <class name>Class struct?
		CheckItemInclusion(srcLocations, itemList)
	else:
		print("The directory to check against must be specified to execute this script.")
