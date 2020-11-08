from __future__ import print_function
#various analysis/attribute filling for atlas objects

#Copyright (C) 2000 by Aloril
#Copyright (C) 2002 by AIR-IX SUUNNITTELU/Ahiplan Oy

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


from builtins import str
from builtins import range
from future.utils import raise_
from builtins import object
import string
from types import *
import atlas
from atlas.typemap import get_atlas_type
import typesx

class Analyse(object):
    """fill attributes"""
    def __init__(self, objects):
        self.objects = objects
        self.id_dict = {}

    def syntax_error(self, msg, obj):
        #info = obj.specification_file
        #raise SyntaxError, "%s at %s:%s" % (msg, info.filename, info.lineno)
        raise_(SyntaxError, "%s for %s" % (msg, obj))

    def check_fill(self):
        """fill missing attributes and check for attribute definitions"""
        self.fill_id_dict()
        self.fill_children()
        atlas.find_parents_children_objects(self.id_dict)
        self.check_type()

    def fill_id_dict(self):
        """fill id_dict with all objects"""
        for obj in self.objects:
            try:
                id = obj.id
            except AttributeError:
                self.syntax_error(
                    "Id attribute is not specified for object", obj)
            if id in self.id_dict:
                self.syntax_error(
                    'Object with "'+id+'"-id already exists', obj)
            self.id_dict[id]=obj

    def fill_children(self):
        for obj in self.objects:
            if not hasattr(obj, "parent"):
##            attr_order = obj.specification_file.attribute_order
##            try:
##                parent_loc = attr_order.index("parents")
##            except ValueError:
                self.syntax_error("Parent attribute missing", obj)
##            attr_order.insert(parent_loc+1, "children")
            obj.children=[]
        for obj in self.objects:
            pid = obj.parent
            if type(pid)==typesx.StringType:
                try:
                    parent_obj = self.id_dict[pid]
                except KeyError:
                    self.syntax_error('Parent "%s" is missing' % pid, obj)
            else:
                parent_obj = pid
            parent_obj.children.append(obj.id)

    def check_type_object(self, obj):
        """recursively check types for all objects"""
        if type(obj)==typesx.ListType or isinstance(obj, atlas.Messages):
            for sub_obj in obj:
                self.check_type_object(sub_obj)
        elif type(obj)==typesx.InstanceType:
            for name, value in list(obj.items()):
                try:
                    type_obj = self.id_dict[name]
                except KeyError:
                    self.syntax_error('Name "'+name+'" is not specified',obj)
                should_be_type = get_atlas_type(value)
                if not type_obj.has_parent(should_be_type):
                    self.syntax_error(
                        'Type doesn\'t match or is not found: "'+name+'"',obj)
                self.check_type_object(value)
                
    def check_type(self):
        self.check_type_object(self.objects)

    

def fill_attributes(objects):
    an = Analyse(objects)
    an.check_fill()
    return an

class Link(object):
    def __init__(self, name):
        self.name = name
        self.direction1 = {}
        self.direction2 = {}
        self.verbose = 0

    def get_dict(self, name, dict):
        return list(dict.get(name, {}).keys())

    def get1(self, name):
        return self.get_dict(name, self.direction1)

    def get2(self, name):
        return self.get_dict(name, self.direction2)

    def add_dict(self, dict, name1, name2):
        dict2 = dict.get(name1, {})
        dict2[name2] = 1
        dict[name1] = dict2

    def add(self, name1, name2):
        self.add_dict(self.direction1, name1, name2)
        self.add_dict(self.direction2, name2, name1)
        if self.verbose:
            print("%s.add_dict: %s <-> %s" % (self.name, name1, name2))

    def copy(self, dest, source):
        if self.verbose:
            print("%s.copy: %s <- %s" % (self.name, dest, source))
        for name2 in list(self.direction1.get(source, {}).keys()):
            self.add(dest, name2)

    def remove_dict(self, name, dict1, dict2):
        entry = dict1.get(name)
        if entry!=None:
            for name2 in list(entry.keys()):
                del dict2[name2][name]
                if not dict2[name2]: del dict2[name2]
                if self.verbose:
                    print("%s.remove_dict: %s <-> %s" % (self.name, name, name2))
            del dict1[name]

    def remove(self, name):
        if self.verbose:
            print("%s.remove: %s" % (self.name, name))
        if name in self.direction1:
            self.remove_dict(name, self.direction1, self.direction2)
        if name in self.direction2:
            self.remove_dict(name, self.direction2, self.direction1)

    #this code not used, but ... it should be ok: if you need it, uncomment it
##    def remove2_dict(self, name1, name2, dict):
##        #print "Link.remove2_dict: %s -> %s" % (name1, name2)
##        del dict[name1][name2]
##        if not dict[name1]: del dict[name1]
            
##    def remove2(self, name1, name2):
##        if self.verbose:
##            print "%s.remove2: %s <-> %s" % (self.name, name1, name2)
##        if not self.direction1.has_key(name1):
##            print "%s.remove2: reversed" % self.name
##            name2, name1 = name2, name1
##        if self.direction1.has_key(name1) and self.direction2.has_key(name2):
##            self.remove2_dict(name1, name2, self.direction1)
##            self.remove2_dict(name2, name1, self.direction2)
##        else:
##            print "%s.remove2: failed" % self.name
            

    def repr_dict(self, name, dict):
        slst = []
        for key, value in list(dict.items()):
            slst.append(key + ": " + str(list(value.keys())))
        return name + "(" + typesx.join(slst, ", ") + ")"
    def __repr__(self):
        return self.name + "(" + self.repr_dict("Direction1", self.direction1) + ", " + \
               self.repr_dict("Direction2", self.direction2) + ")"


class Resolver(object):
    bidirectional_attributes = {"loc":"contains", "parent":"children"} #currently only "loc" works
    def __init__(self, objects):
        self.verbose = 0
        self.objects = objects #pointer to main dictionary of objects (not maintained by us)
        self.pending = Link("Pending")
        self.depencies = Link("Depencies")
        self.links = Link("Links")

    def check_bidirectiontal(self, obj, attr):
        #CHEAT: only "loc"->"contains" really works
        if attr in self.bidirectional_attributes:
            if self.verbose:
                print("bidirectional_attributes:", obj.id, attr)
            attr_value_lst = getattr(obj, attr)
            if hasattr(attr_value_lst, "items"): attr_value_lst = [attr_value_lst]
            for attr_value in attr_value_lst:
                other = getattr(attr_value, self.bidirectional_attributes[attr])
                for value in other:
                    if type(value)==typesx.StringType:
                        if obj.id==value: return
                    else:
                        if obj.id==value.id: return
                print("... adding to", other, attr_value.id)
                other.append(obj)

    def new_object(self, obj):
        ok_objects = {}
        if self.verbose:
            print("-"*60)
            print("new_object:", obj.id)
        for pointer in self.pending.get1(obj.id):
            if self.verbose:
                print("pointer:", pointer)
            obj2, id = atlas.resolve_pointer2(self.objects, pointer)
            #obj2[id] = obj
            if type(obj2[id])==typesx.StringType:
                obj2[id] = atlas.resolve_pointer(self.objects, obj2[id])
            self.check_bidirectiontal(obj2, id)
            self.links.add(obj.id, pointer)
            other_id_lst = self.depencies.get2(pointer)
            self.depencies.remove(pointer)
            for other_id in other_id_lst:
                if self.verbose:
                    print("other_id:", other_id)
                self.depencies.copy(other_id, obj.id)
                if not self.depencies.get1(other_id):
                    if self.verbose:
                        print("!!", other_id)
                    ok_objects[other_id] = self.objects[other_id]
        self.pending.remove(obj.id)

        if self.depencies.get1(obj.id):
            if self.verbose:
                print("not ok!")
        else:
            if self.verbose:
                print("ok!")
            ok_objects[obj.id] = self.objects[obj.id]
        if self.verbose:
            print("===> ok_objects:", obj.id, list(ok_objects.keys()))
            print("!!!>", self.pending)
            print("???>", self.depencies)
            #print self.links
            print("="*60)
            for i in range(4): print()
            import sys
            sys.stdout.flush()
        return list(ok_objects.values())

    def resolve_attribute(self, obj, attr):
        unresolved = []
        #add object to dictionary of all objects
        base_id = obj.id #atlas.get_base_id(obj.id)
        if self.verbose:
            print("base_id:", base_id)
        if base_id in self.objects:
            obj = self.objects[base_id]
            if self.verbose:
                print("got it")
        else:
            self.objects[base_id] = obj
            if self.verbose:
                print("adding it")
        if not hasattr(obj, attr): return unresolved
        #resolve id
        value = getattr(obj, attr)
        if self.verbose:
            print("going to recursive..")
        return self.resolve_attribute_recursively(obj, value, base_id + "." + attr)

    def resolve_attribute_recursively(self, obj, value, base_id):
        unresolved = []
        if type(value)==typesx.StringType:
            if value=='': return unresolved
            this_id = atlas.get_base_id(base_id)
            other_id = atlas.get_base_id(value)
            if other_id in self.objects:
                #pointer resolved, but all depencies still might not be resolved for this to be ok...
                key = atlas.get_last_part(base_id)
                if type(obj)==typesx.ListType: key = int(key)
                if self.verbose:
                    print("!!", str(obj)[:100], value, base_id, key, atlas.resolve_pointer(self.objects, value))
                self.depencies.copy(this_id, other_id)
                obj[key] = atlas.resolve_pointer(self.objects, value)
                self.check_bidirectiontal(obj, key)
                self.links.add(value, base_id)
                return unresolved
            else:
                #pointer not resolved, record needed info for later resolving:
                if self.verbose:
                    print("??", str(obj)[:70], base_id, this_id, value, other_id)
                unresolved.append(other_id)
                
                #1) add value into "what pointers other_id object can resolve" -dictionary
                self.pending.add(other_id, base_id)
                if self.verbose:
                    print(self.pending)
                
                #2) what pointers need to be resolved for this object
                self.depencies.add(this_id, base_id)
                if self.verbose:
                    print(self.depencies)

                return unresolved
        elif type(value)==typesx.ListType:
            if self.verbose:
                print("list:", base_id)
            for i in range(len(value)):
                value2 = value[i]
                res = self.resolve_attribute_recursively(value, value2, "%s.%s" % (base_id, i))
                if res: unresolved = unresolved + res
            return unresolved
        elif type(value)==typesx.DictType or \
             (type(value)==typesx.InstanceType and hasattr(value, "items") and not hasattr(value, "id")):
            if self.verbose:
                print("dict:", base_id)
            for key, value2 in list(value.items()):
                res = self.resolve_attribute_recursively(value, value2, "%s.%s" % (base_id, key))
                if res: unresolved = unresolved + res
            return unresolved
        #ignore unknown types (like Vector3D)
        if self.verbose:
            print("this type (%s) not handled yet (%s)..." % (type(value), value))
            if type(value)==typesx.InstanceType:
                print("class:", value.__class__, value.__class__.__bases__)
        #raise ValueError, "this type (%s) not handled yet (%s)..." % (type(value), value)
        return unresolved
