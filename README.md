# GocatorProfileDistance

Gocator profile distance tool using Gocator Gdk.
<br>
<br>
1.Put the project folder in the folder caller "14524-4.6.7.126_SOFTWARE_GDK".
\<br>
2.Open generate.py in the GdkProfileDistance folder, and change the "GocatorProfileDistance" in the following two lines to your project folder name, such as "GocatorProfileDistance-master".
\<br>
```
generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance-master', 'Gdk.xml'), ['MsvcChooser'], ['Win32', 'Win64', 'Sensor'])generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance-master', 'Gdk.xml'), ['Ccs6Mk', 'WrWbMk'], ['C64x', 'Arm7'])
```
3.Run generate.py.
