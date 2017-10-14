#!/usr/bin/python

import sys
import os
import subprocess
import argparse

def Build(config, cleanTargets, buildTargets):

    herePath = os.path.dirname(os.path.realpath(__file__))
    projectName = herePath.split(os.path.sep)[-1]

    pkgUpdatePath = os.path.join(herePath, '..', '..', 'bin', 'win32', 'GoPkgUpdate.exe')
    gmakePath = os.path.join(herePath, '..', '..', 'Platform', 'extern', 'Make', 'gmake.exe')
    makeGoals = []

    if cleanTargets:
        makeGoals.append('clean')

    if buildTargets:
        makeGoals.append('all')

    subprocess.check_call([gmakePath, '-f', projectName + '-WrWb.mk', 'config=' + config] + makeGoals)
    subprocess.check_call([gmakePath, '-f', projectName + '-Ccs6.mk', 'config=' + config] + makeGoals)

    if buildTargets:
        subprocess.check_call([pkgUpdatePath, projectName])

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Build for ARM and C64x targets.')

    parser.add_argument('config', help='Configuration name.')
    group = parser.add_mutually_exclusive_group()
    group.add_argument('--rebuild', action='store_true', help='Rebuild target files.')
    group.add_argument('--clean', action='store_true', help='Clean target files.')

    args = parser.parse_args()

    cleanTargets = (args.rebuild or args.clean)
    buildTargets = (not args.clean)

    Build(args.config, cleanTargets, buildTargets)
