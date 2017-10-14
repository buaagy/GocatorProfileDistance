#!/usr/bin/python

import os
import sys

def Generate():

    herePath = os.path.dirname(os.path.realpath(__file__))
    workDir = os.path.normpath(os.path.join(herePath, '..', '..'))
    sys.path.append(workDir)

    print('Generating Gdk Sample solution')
    import Platform.scripts.Utils.kGenerator as generator

    generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance', 'Gdk.xml'), ['MsvcChooser'], ['Win32', 'Win64', 'Sensor'])
    generator.WriteSolution(os.path.join(workDir, 'GocatorProfileDistance', 'Gdk.xml'), ['Ccs6Mk', 'WrWbMk'], ['C64x', 'Arm7'])

if __name__ == '__main__':
    Generate()
