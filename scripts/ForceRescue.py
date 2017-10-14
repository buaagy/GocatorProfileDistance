#!/usr/bin/python
# Copyright (C) 2008-2016 by LMI Technologies Inc.  All rights reserved.
# Distributed under the terms of the MIT License.
# Redistributed files must retain the above copyright notice.
#
# Invoke this script without arguments (uses built-in list of ip-addresses)
# python kRescue.py
#
# Alternatively invoke this script with any number of IP-addresses:
# python kRescue.py 10.0.0.1
# python kRescue.py 10.0.0.1 90.0.0.1 192.168.1.1
#

import sys
import socket
import time

def rescue(ipAddressesToBind = []):

    if len(ipAddressesToBind) == 0:
        ipAddressesToBind = [
            '10.0.0.1',
            '90.0.0.1',
            '192.168.1.1',
        ]

    boundSockets = []
    for ipAddressToBind in ipAddressesToBind:

        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        try:
            sock.bind((ipAddressToBind, 0))
        except OSError:
            print('not bound to address: ' + ipAddressToBind)
            pass
        else:
            print('bound to address: ' + ipAddressToBind)
            boundSockets.append(sock)

    if len(boundSockets) == 0:
        raise Exception('Failed to bind to any address')

    message = b'\x99\x46\xD7\x04\xA7\xC1\x66\xC2'
    legacyMessage = 'LMI_RESCUE_REQ'.encode('ascii')

    destAddress = '255.255.255.255'
    destPort = 2016

    while True:

        for boundSocket in boundSockets:
            boundSocket.sendto(message, (destAddress, destPort))
            boundSocket.sendto(legacyMessage, (destAddress, destPort))

        time.sleep(0.1)

if __name__ == '__main__':

    try:
        rescue(sys.argv[1:])
    except Exception as error:
        print(str(error))
        exit(-1)
