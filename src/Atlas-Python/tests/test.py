#test atlas: objects, codecs

#Copyright 2000-2002 by Aloril
#Copyright 2002 by AIR-IX SUUNNITTELU/Ahiplan Oy

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


from past.builtins import execfile
import sys
sys.path.append("..")

def deb(): import pdb; pdb.pm()
execfile("test_atlas.py")
execfile("test_negotiation.py")
#execfile("test_binary.py")
execfile("test_codecs.py")
execfile("test_bridge.py")
execfile("test_glue.py")
execfile("test_server.py")
