#!/usr/bin/env python
#simple reference media server

#Copyright 2001 by Aloril

#This library is free software; you can redistribute it and/or
#modify it under the terms of the GNU Lesser General Public
#License as published by the Free Software Foundation; either
#version 2.1 of the License, or (at your option) any later version.

#This library is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#Lesser General Public License for more details.

#You should have received a copy of the GNU Lesser General Public
#License along with this library; if not, write to the Free Software
#Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

import sys
sys.path.append("..")
from atlas.transport.TCP.server import SocketServer, TcpClient
from atlas.transport.connection import args2address
import atlas
from atlas.transport.file import read_and_analyse

"""
Usage elsewhere than Atlas-Python directory:
export PYTHONPATH=where_Atlas-Python_resides
copy atlas.bach to directory you run it or modify filename in code
"""

class MediaServer(SocketServer):
    def setup(self):
        #self.objects = read_and_analyse("media.bach")
        self.objects = read_and_analyse("simple_core.atlas")
        print (len(self.objects), "objects loaded")

class MediaClient(TcpClient):
    def get_op(self, op):
        id = op.arg.id
        obj = self.server.objects.get(id)
        if obj:
            self.reply_operation(op, atlas.Operation("info", obj))
        else:
            self.send_error(op, "no object with id " + id)

if __name__=="__main__":
    s = MediaServer("Simple media server", args2address(sys.argv), MediaClient)
    s.loop()
