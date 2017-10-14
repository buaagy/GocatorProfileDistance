/**
* @file    GdkFile.h
* @brief   Declares the GdkFile class.
*
* Copyright (C) 2017 by LMI Technologies Inc.  All rights reserved.
*/
#ifndef GDK_FILE_H
#define GDK_FILE_H

#include <Gdk/GdkDef.h>

kBeginHeader()

/**
* Read a file
*
* @public               @memberof GdkFile
* @param   path         Path to file. (Must be within user directory eg. user/myFile.txt)
* @param   data         Receives a pointer to a kArray1 containing the data.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFile_Read(const kChar *path, kArray1* data);

/**
* Write a file
*
* Do not write to files too often. (More than a few times per sensor startup)
* Sensor flash memory may be corrupted by excessive writes.
* DO NOT CALL THIS FUNCTION FROM A GDK TOOL_vProcess CALLBACK
*
* @public               @memberof GdkFile
* @param   path         Path to file. (Must be within user directory eg. user/myFile.txt)
* @param   data         Pointer to data to write to file.
* @param   size         Size of data to write to file.
* @return               Operation status.
*/
GdkFx(kStatus) GdkFile_Write(const kChar *path, void* data, kSize size);

/**
* How much flash memory is available to write to.
*
* @public               @memberof GdkFile
* @return               Available (bytes).
*/
GdkFx(k64u) GdkFile_UserStorageFree();

/**
* How much flash memory has been used.
*
* @public               @memberof GdkFile
* @return               Used (bytes).
*/
GdkFx(k64u) GdkFile_UserStorageUsed();

kEndHeader()

#endif 
