// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2004 Al Riddoch.
// Automatically generated using gen_cpp.py.

#include <Atlas/Objects/Operation.h>

using Atlas::Message::Element;
using Atlas::Message::MapType;

namespace Atlas { namespace Objects { namespace Operation { 

ImaginaryData::~ImaginaryData()
{
}

ImaginaryData * ImaginaryData::copy() const
{
    ImaginaryData * copied = ImaginaryData::alloc();
    *copied = *this;
    return copied;
}

bool ImaginaryData::instanceOf(int classNo) const
{
    if(IMAGINARY_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

//freelist related methods specific to this class
ImaginaryData *ImaginaryData::defaults_ImaginaryData = 0;
ImaginaryData *ImaginaryData::begin_ImaginaryData = 0;

ImaginaryData *ImaginaryData::alloc()
{
    if(begin_ImaginaryData) {
        ImaginaryData *res = begin_ImaginaryData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_ImaginaryData = (ImaginaryData *)begin_ImaginaryData->m_next;
        return res;
    }
    return new ImaginaryData(ImaginaryData::getDefaultObjectInstance());
}

void ImaginaryData::free()
{
    m_next = begin_ImaginaryData;
    begin_ImaginaryData = this;
}


ImaginaryData *ImaginaryData::getDefaultObjectInstance()
{
    if (defaults_ImaginaryData == 0) {
        defaults_ImaginaryData = new ImaginaryData;
        defaults_ImaginaryData->attr_objtype = "op";
        defaults_ImaginaryData->attr_serialno = 0;
        defaults_ImaginaryData->attr_refno = 0;
        defaults_ImaginaryData->attr_seconds = 0.0;
        defaults_ImaginaryData->attr_future_seconds = 0.0;
        defaults_ImaginaryData->attr_stamp = 0.0;
        defaults_ImaginaryData->attr_parents = std::list<std::string>(1, "imaginary");
    }
    return defaults_ImaginaryData;
}

ImaginaryData *ImaginaryData::getDefaultObject()
{
    return ImaginaryData::getDefaultObjectInstance();
}

UseData::~UseData()
{
}

UseData * UseData::copy() const
{
    UseData * copied = UseData::alloc();
    *copied = *this;
    return copied;
}

bool UseData::instanceOf(int classNo) const
{
    if(USE_NO == classNo) return true;
    return ActionData::instanceOf(classNo);
}

//freelist related methods specific to this class
UseData *UseData::defaults_UseData = 0;
UseData *UseData::begin_UseData = 0;

UseData *UseData::alloc()
{
    if(begin_UseData) {
        UseData *res = begin_UseData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_UseData = (UseData *)begin_UseData->m_next;
        return res;
    }
    return new UseData(UseData::getDefaultObjectInstance());
}

void UseData::free()
{
    m_next = begin_UseData;
    begin_UseData = this;
}


UseData *UseData::getDefaultObjectInstance()
{
    if (defaults_UseData == 0) {
        defaults_UseData = new UseData;
        defaults_UseData->attr_objtype = "op";
        defaults_UseData->attr_serialno = 0;
        defaults_UseData->attr_refno = 0;
        defaults_UseData->attr_seconds = 0.0;
        defaults_UseData->attr_future_seconds = 0.0;
        defaults_UseData->attr_stamp = 0.0;
        defaults_UseData->attr_parents = std::list<std::string>(1, "use");
    }
    return defaults_UseData;
}

UseData *UseData::getDefaultObject()
{
    return UseData::getDefaultObjectInstance();
}

InfoData::~InfoData()
{
}

InfoData * InfoData::copy() const
{
    InfoData * copied = InfoData::alloc();
    *copied = *this;
    return copied;
}

bool InfoData::instanceOf(int classNo) const
{
    if(INFO_NO == classNo) return true;
    return RootOperationData::instanceOf(classNo);
}

//freelist related methods specific to this class
InfoData *InfoData::defaults_InfoData = 0;
InfoData *InfoData::begin_InfoData = 0;

InfoData *InfoData::alloc()
{
    if(begin_InfoData) {
        InfoData *res = begin_InfoData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_InfoData = (InfoData *)begin_InfoData->m_next;
        return res;
    }
    return new InfoData(InfoData::getDefaultObjectInstance());
}

void InfoData::free()
{
    m_next = begin_InfoData;
    begin_InfoData = this;
}


InfoData *InfoData::getDefaultObjectInstance()
{
    if (defaults_InfoData == 0) {
        defaults_InfoData = new InfoData;
        defaults_InfoData->attr_objtype = "op";
        defaults_InfoData->attr_serialno = 0;
        defaults_InfoData->attr_refno = 0;
        defaults_InfoData->attr_seconds = 0.0;
        defaults_InfoData->attr_future_seconds = 0.0;
        defaults_InfoData->attr_stamp = 0.0;
        defaults_InfoData->attr_parents = std::list<std::string>(1, "info");
    }
    return defaults_InfoData;
}

InfoData *InfoData::getDefaultObject()
{
    return InfoData::getDefaultObjectInstance();
}

PerceptionData::~PerceptionData()
{
}

PerceptionData * PerceptionData::copy() const
{
    PerceptionData * copied = PerceptionData::alloc();
    *copied = *this;
    return copied;
}

bool PerceptionData::instanceOf(int classNo) const
{
    if(PERCEPTION_NO == classNo) return true;
    return InfoData::instanceOf(classNo);
}

//freelist related methods specific to this class
PerceptionData *PerceptionData::defaults_PerceptionData = 0;
PerceptionData *PerceptionData::begin_PerceptionData = 0;

PerceptionData *PerceptionData::alloc()
{
    if(begin_PerceptionData) {
        PerceptionData *res = begin_PerceptionData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_PerceptionData = (PerceptionData *)begin_PerceptionData->m_next;
        return res;
    }
    return new PerceptionData(PerceptionData::getDefaultObjectInstance());
}

void PerceptionData::free()
{
    m_next = begin_PerceptionData;
    begin_PerceptionData = this;
}


PerceptionData *PerceptionData::getDefaultObjectInstance()
{
    if (defaults_PerceptionData == 0) {
        defaults_PerceptionData = new PerceptionData;
        defaults_PerceptionData->attr_objtype = "op";
        defaults_PerceptionData->attr_serialno = 0;
        defaults_PerceptionData->attr_refno = 0;
        defaults_PerceptionData->attr_seconds = 0.0;
        defaults_PerceptionData->attr_future_seconds = 0.0;
        defaults_PerceptionData->attr_stamp = 0.0;
        defaults_PerceptionData->attr_parents = std::list<std::string>(1, "perception");
    }
    return defaults_PerceptionData;
}

PerceptionData *PerceptionData::getDefaultObject()
{
    return PerceptionData::getDefaultObjectInstance();
}

SightData::~SightData()
{
}

SightData * SightData::copy() const
{
    SightData * copied = SightData::alloc();
    *copied = *this;
    return copied;
}

bool SightData::instanceOf(int classNo) const
{
    if(SIGHT_NO == classNo) return true;
    return PerceptionData::instanceOf(classNo);
}

//freelist related methods specific to this class
SightData *SightData::defaults_SightData = 0;
SightData *SightData::begin_SightData = 0;

SightData *SightData::alloc()
{
    if(begin_SightData) {
        SightData *res = begin_SightData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_SightData = (SightData *)begin_SightData->m_next;
        return res;
    }
    return new SightData(SightData::getDefaultObjectInstance());
}

void SightData::free()
{
    m_next = begin_SightData;
    begin_SightData = this;
}


SightData *SightData::getDefaultObjectInstance()
{
    if (defaults_SightData == 0) {
        defaults_SightData = new SightData;
        defaults_SightData->attr_objtype = "op";
        defaults_SightData->attr_serialno = 0;
        defaults_SightData->attr_refno = 0;
        defaults_SightData->attr_seconds = 0.0;
        defaults_SightData->attr_future_seconds = 0.0;
        defaults_SightData->attr_stamp = 0.0;
        defaults_SightData->attr_parents = std::list<std::string>(1, "sight");
    }
    return defaults_SightData;
}

SightData *SightData::getDefaultObject()
{
    return SightData::getDefaultObjectInstance();
}

AppearanceData::~AppearanceData()
{
}

AppearanceData * AppearanceData::copy() const
{
    AppearanceData * copied = AppearanceData::alloc();
    *copied = *this;
    return copied;
}

bool AppearanceData::instanceOf(int classNo) const
{
    if(APPEARANCE_NO == classNo) return true;
    return SightData::instanceOf(classNo);
}

//freelist related methods specific to this class
AppearanceData *AppearanceData::defaults_AppearanceData = 0;
AppearanceData *AppearanceData::begin_AppearanceData = 0;

AppearanceData *AppearanceData::alloc()
{
    if(begin_AppearanceData) {
        AppearanceData *res = begin_AppearanceData;
        assert( res->m_refCount == 0 );
        res->m_attrFlags = 0;
        res->m_attributes.clear();
        begin_AppearanceData = (AppearanceData *)begin_AppearanceData->m_next;
        return res;
    }
    return new AppearanceData(AppearanceData::getDefaultObjectInstance());
}

void AppearanceData::free()
{
    m_next = begin_AppearanceData;
    begin_AppearanceData = this;
}


AppearanceData *AppearanceData::getDefaultObjectInstance()
{
    if (defaults_AppearanceData == 0) {
        defaults_AppearanceData = new AppearanceData;
        defaults_AppearanceData->attr_objtype = "op";
        defaults_AppearanceData->attr_serialno = 0;
        defaults_AppearanceData->attr_refno = 0;
        defaults_AppearanceData->attr_seconds = 0.0;
        defaults_AppearanceData->attr_future_seconds = 0.0;
        defaults_AppearanceData->attr_stamp = 0.0;
        defaults_AppearanceData->attr_parents = std::list<std::string>(1, "appearance");
    }
    return defaults_AppearanceData;
}

AppearanceData *AppearanceData::getDefaultObject()
{
    return AppearanceData::getDefaultObjectInstance();
}

} } } // namespace Atlas::Objects::Operation