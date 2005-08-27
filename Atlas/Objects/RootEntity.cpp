// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2004 Al Riddoch.
// Automatically generated using gen_cpp.py.

#include <Atlas/Objects/RootEntity.h>

using Atlas::Message::Element;
using Atlas::Message::MapType;

namespace Atlas { namespace Objects { namespace Entity { 

int RootEntityData::getAttrClass(const std::string& name) const
{
    if (name == "loc") return ROOT_ENTITY_NO;
    if (name == "pos") return ROOT_ENTITY_NO;
    if (name == "velocity") return ROOT_ENTITY_NO;
    if (name == "contains") return ROOT_ENTITY_NO;
    if (name == "stamp_contains") return ROOT_ENTITY_NO;
    return RootData::getAttrClass(name);
}

const Element RootEntityData::getAttr(const std::string& name) const
    throw (NoSuchAttrException)
{
    if (name == "loc") return getLoc();
    if (name == "pos") return getPosAsList();
    if (name == "velocity") return getVelocityAsList();
    if (name == "contains") return getContainsAsList();
    if (name == "stamp_contains") return getStampContains();
    return RootData::getAttr(name);
}

int RootEntityData::getAttr(const std::string& name, Element & attr) const
{
    if (name == "loc") { attr = getLoc(); return 0; }
    if (name == "pos") { attr = getPosAsList(); return 0; }
    if (name == "velocity") { attr = getVelocityAsList(); return 0; }
    if (name == "contains") { attr = getContainsAsList(); return 0; }
    if (name == "stamp_contains") { attr = getStampContains(); return 0; }
    return RootData::getAttr(name, attr);
}

void RootEntityData::setAttr(const std::string& name, const Element& attr)
{
    if (name == "loc") { setLoc(attr.asString()); return; }
    if (name == "pos") { setPosAsList(attr.asList()); return; }
    if (name == "velocity") { setVelocityAsList(attr.asList()); return; }
    if (name == "contains") { setContainsAsList(attr.asList()); return; }
    if (name == "stamp_contains") { setStampContains(attr.asFloat()); return; }
    RootData::setAttr(name, attr);
}

void RootEntityData::removeAttr(const std::string& name)
{
    if (name == "loc")
        { m_attrFlags &= ~LOC_FLAG; return;}
    if (name == "pos")
        { m_attrFlags &= ~POS_FLAG; return;}
    if (name == "velocity")
        { m_attrFlags &= ~VELOCITY_FLAG; return;}
    if (name == "contains")
        { m_attrFlags &= ~CONTAINS_FLAG; return;}
    if (name == "stamp_contains")
        { m_attrFlags &= ~STAMP_CONTAINS_FLAG; return;}
    RootData::removeAttr(name);
}

inline void RootEntityData::sendLoc(Atlas::Bridge & b) const
{
    if(m_attrFlags & LOC_FLAG) {
        b.mapStringItem("loc", attr_loc);
    }
}

inline void RootEntityData::sendPos(Atlas::Bridge & b) const
{
    if(m_attrFlags & POS_FLAG) {
        b.mapListItem("pos");
        const std::vector<double> & v = attr_pos;
        std::vector<double>::const_iterator I = v.begin();
        for(; I != v.end(); ++I) {
            b.listFloatItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendVelocity(Atlas::Bridge & b) const
{
    if(m_attrFlags & VELOCITY_FLAG) {
        b.mapListItem("velocity");
        const std::vector<double> & v = attr_velocity;
        std::vector<double>::const_iterator I = v.begin();
        for(; I != v.end(); ++I) {
            b.listFloatItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendContains(Atlas::Bridge & b) const
{
    if(m_attrFlags & CONTAINS_FLAG) {
        b.mapListItem("contains");
        const std::list<std::string> & l = attr_contains;
        std::list<std::string>::const_iterator I = l.begin();
        for(; I != l.end(); ++I) {
            b.listStringItem(*I);
        }
        b.listEnd();
    }
}

inline void RootEntityData::sendStampContains(Atlas::Bridge & b) const
{
    if(m_attrFlags & STAMP_CONTAINS_FLAG) {
        b.mapFloatItem("stamp_contains", attr_stamp_contains);
    }
}

void RootEntityData::sendContents(Bridge & b) const
{
    sendLoc(b);
    sendPos(b);
    sendVelocity(b);
    sendContains(b);
    sendStampContains(b);
    RootData::sendContents(b);
}

void RootEntityData::addToMessage(MapType & m) const
{
    RootData::addToMessage(m);
    if(m_attrFlags & LOC_FLAG)
        m["loc"] = attr_loc;
    if(m_attrFlags & POS_FLAG)
        m["pos"] = getPosAsList();
    if(m_attrFlags & VELOCITY_FLAG)
        m["velocity"] = getVelocityAsList();
    if(m_attrFlags & CONTAINS_FLAG)
        m["contains"] = getContainsAsList();
    if(m_attrFlags & STAMP_CONTAINS_FLAG)
        m["stamp_contains"] = attr_stamp_contains;
    return;
}

void RootEntityData::iterate(int& current_class, std::string& attr) const
{
    // If we've already finished this class, chain to the parent
    if(current_class >= 0 && current_class != ROOT_ENTITY_NO) {
        RootData::iterate(current_class, attr);
        return;
    }

    static const char *attr_list[] = {"loc","pos","velocity","contains","stamp_contains",};
    static const unsigned n_attr = sizeof(attr_list) / sizeof(const char*);

    unsigned next_attr = n_attr; // so we chain to the parent if we don't find attr

    if(attr.empty()) // just staring on this class
        next_attr = 0;
    else {
      for(unsigned i = 0; i < n_attr; ++i) {
         if(attr == attr_list[i]) {
             next_attr = i + 1;
             break;
         }
      }
    }

    if(next_attr == n_attr) { // last one on the list
        current_class = -1;
        attr = "";
        RootData::iterate(current_class, attr); // chain to parent
    }
    else {
        current_class = ROOT_ENTITY_NO;
        attr = attr_list[next_attr];
    }
}

RootEntityData::~RootEntityData()
{
}

RootEntityData * RootEntityData::copy() const
{
    RootEntityData * copied = RootEntityData::alloc();
    *copied = *this;
    return copied;
}

bool RootEntityData::instanceOf(int classNo) const
{
    if(ROOT_ENTITY_NO == classNo) return true;
    return RootData::instanceOf(classNo);
}

//freelist related methods specific to this class
RootEntityData *RootEntityData::defaults_RootEntityData = 0;
RootEntityData *RootEntityData::begin_RootEntityData = 0;

RootEntityData *RootEntityData::alloc()
{
    if(begin_RootEntityData) {
        RootEntityData *res = begin_RootEntityData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_RootEntityData = (RootEntityData *)begin_RootEntityData->m_next;
        return res;
    }
    return new RootEntityData(RootEntityData::getDefaultObjectInstance());
}

void RootEntityData::free()
{
    m_next = begin_RootEntityData;
    begin_RootEntityData = this;
}


RootEntityData *RootEntityData::getDefaultObjectInstance()
{
    if (defaults_RootEntityData == 0) {
        defaults_RootEntityData = new RootEntityData;
        defaults_RootEntityData->attr_objtype = "obj";
        defaults_RootEntityData->attr_pos.clear();
        defaults_RootEntityData->attr_pos.push_back(0.0);
        defaults_RootEntityData->attr_pos.push_back(0.0);
        defaults_RootEntityData->attr_pos.push_back(0.0);
        defaults_RootEntityData->attr_velocity.clear();
        defaults_RootEntityData->attr_velocity.push_back(0.0);
        defaults_RootEntityData->attr_velocity.push_back(0.0);
        defaults_RootEntityData->attr_velocity.push_back(0.0);
        defaults_RootEntityData->attr_stamp_contains = 0.0;
        defaults_RootEntityData->attr_stamp = 0.0;
        defaults_RootEntityData->attr_parents = std::list<std::string>(1, "root_entity");
    }
    return defaults_RootEntityData;
}

RootEntityData *RootEntityData::getDefaultObject()
{
    return RootEntityData::getDefaultObjectInstance();
}

} } } // namespace Atlas::Objects::Entity
