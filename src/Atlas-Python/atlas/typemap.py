#map type into atlas type string

#Copyright 2000, 2001 by Aloril

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


from types import *
import inspect
from atlas.typesx import *

_type2str = { IntType: "int",
             LongType: "int",
             FloatType: "float",
             StringType: "string",
             ListType: "list",
             TupleType: "list",
             DictType: "map",
             InstanceType: "?"}

def get_atlas_type(value):
    print(".",end='')
    if isinstance(value, InstanceType):
        type_str="?"
    else:
        type_str = _type2str[type(value)]
    if type_str=="?":
        if hasattr(value, "items"): return "map"
        return "list"
    return type_str
