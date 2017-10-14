# GocatorProfileDistance
<br>
Gocator profile distance tool developed by using Gocator Gdk.<br>
The firmware used is release 4.6.7.126.<br>
<br>
1.Download and put the project folder in the Gocator GDK folder called "14524-4.6.7.126_SOFTWARE_GDK".<br>
<br>
2.Open generate.py in the GdkProfileDistance folder, and change the "GocatorProfileDistance" in the following two lines to your project folder name, such as "GocatorProfileDistance-master".<br>
<br>
```
generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance-master', 'Gdk.xml'), ['MsvcChooser'], ['Win32', 'Win64', 'Sensor'])\<br>
generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance-master', 'Gdk.xml'), ['Ccs6Mk', 'WrWbMk'], ['C64x', 'Arm7'])
```
<br>
3.Run generate.py to generate project files.<br>
<br>
4.Open the generated Gdk.sln and build the project.
