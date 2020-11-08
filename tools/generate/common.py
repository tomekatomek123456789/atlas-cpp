# This file is distributed under the terms of
# the GNU Lesser General Public license (See the file COPYING for details).
# Copyright (C) 2000 Stefanus Du Toit and Aloril
# Copyright (C) 2001-2004 Alistair Riddoch
# Copyright (C) 2011 Erik Ogenvik

from builtins import map
__revision__ = '$Id$'

import sys, os

try:
    import filecmp

    filecmp = filecmp.cmp
except ImportError:
    import cmp

    filecmp = cmp.cmp
sys.path.append("../../Atlas-Python")
from atlas import *
from atlas.codecs import *
from atlas import typesx


def deb(): import pdb; pdb.pm()


copyright_template = \
    """// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 %s.
// Copyright 2001-2005 %s.
// Copyright 2011-2020 Erik Ogenvik.
// Automatically generated using gen_cpp.py. Don't edit directly.
"""

copyright = copyright_template % ("Stefanus Du Toit and Aloril", "Alistair Riddoch")

# objects that will have static attributes
static_objects = ["root", "root_entity", "root_operation"]

# These are only used for description.
descr_attrs = ['children', 'description', 'args_description', 'example',
               'long_description', 'specification', 'specification_file',
               'stamp_inherit', 'interface', 'time_string']

# C++ equivalents of atlas types              
cpp_type = {'map': 'Atlas::Message::MapType',
            'list': 'Atlas::Message::ListType',
            'string': 'std::string',
            'int': 'std::int64_t',
            'float': 'double',
            'RootList': 'std::vector<Root>',
            'string_list': 'std::vector<std::string>',
            'int_list': 'std::vector<std::int64_t>',
            'float_list': 'std::vector<double>',
            'string_list_length': 'std::vector<std::string>',
            'int_list_length': 'std::vector<std::int64_t>',
            'float_list_length': 'std::vector<double>'}

cpp_param_movable = {'map': True,
                     'list': True,
                     'string': True,
                     'int': False,
                     'float': False,
                     'RootList': True,
                     'string_list': True,
                     'int_list': True,
                     'float_list': True,
                     'string_list_length': True,
                     'int_list_length': True,
                     'float_list_length': True}

# Const references
cpp_param_type = {'map': 'const ' + cpp_type['map'] + '&',
                  'list': 'const ' + cpp_type['list'] + '&',
                  'string': 'const ' + cpp_type['string'] + '&',
                  'int': cpp_type['int'],
                  'float': cpp_type['float'],
                  'RootList': 'const ' + cpp_type['RootList'] + '&',
                  'string_list': 'const ' + cpp_type['string_list'] + '&',
                  'int_list': 'const ' + cpp_type['int_list'] + '&',
                  'float_list': 'const ' + cpp_type['float_list'] + '&',
                  'string_list_length': 'const ' + cpp_type['string_list_length'] + '&',
                  'int_list_length': 'const ' + cpp_type['int_list_length'] + '&',
                  'float_list_length': 'const ' + cpp_type['float_list_length'] + '&'}

cpp_param_in_type = {'map': cpp_type['map'],
                     'list': cpp_type['list'],
                     'string': cpp_type['string'],
                     'int': cpp_type['int'],
                     'float': cpp_type['float'],
                     'RootList': cpp_type['RootList'],
                     'string_list': cpp_type['string_list'],
                     'int_list': cpp_type['int_list'],
                     'float_list': cpp_type['float_list'],
                     'string_list_length': cpp_type['string_list_length'],
                     'int_list_length': cpp_type['int_list_length'],
                     'float_list_length': cpp_type['float_list_length']}

# Non-const references
cpp_param_type2 = {'map': cpp_type['map'] + '&',
                   'list': cpp_type['list'] + '&',
                   'string': cpp_type['string'] + '&',
                   'int': cpp_type['int'] + '&',
                   'float': cpp_type['float'] + '&',
                   'RootList': cpp_type['RootList'] + '&',
                   'string_list': cpp_type['string_list'] + '&',
                   'int_list': cpp_type['int_list'] + '&',
                   'float_list': cpp_type['float_list'] + '&',
                   'string_list_length': cpp_type['string_list_length'] + '&',
                   'int_list_length': cpp_type['int_list_length'] + '&',
                   'float_list_length': cpp_type['float_list_length'] + '&'}


def capitalize_only(str):
    return typesx.upper(str[:1]) + str[1:]


# Turns some_thing into SomeThing
def classize(id, data=0):
    if id is None:
        return "BaseObject"
    if type(id) != typesx.StringType: id = id.id
    cid = typesx.join(list(map(capitalize_only, typesx.split(id, '_'))), "")
    if data: return cid + "Data"
    return cid


def doc(indent, text):
    return " " * indent + "/// %s\n" % text


def find_in_parents(obj, attr_name):
    if hasattr(obj, "parent") and hasattr(obj.parent, attr_name):
        return obj.parent
    return None
