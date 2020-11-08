#!/usr/bin/env python
#setup script used by distutils

#Copyright 2002 by Michael Koch <konqueror@gmx.de>
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


from distutils.core import setup

setup(name="Atlas-Python",
	version="0.3.0",
	description="Python Atlas library powered by aloril atlas <aloril@iki.fi>",
	author="tomek89",
	author_email="tomekatomek123456789@gmail.com",
	url="http://www.worldforge.org/dev/eng/protocols/",
	packages=['atlas', 'atlas.transport', 'atlas.transport.TCP', 'atlas.codecs', 'atlas.util'],
	package_dir={'atlas':'atlas'}
)
