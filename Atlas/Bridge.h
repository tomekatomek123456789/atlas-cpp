// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_BRIDGE_H
#define ATLAS_BRIDGE_H

#include <string>

namespace Atlas {

/** Atlas stream bridge

This class presents an interface that accepts an Atlas stream. The stream
begins with a call to streamBegin() and finishes with streamEnd(). While the
Bridge is in this stream context, a message can be sent using streamMessage().
This puts the Bridge into a map context, allowing various mapItem() calls.

Several classes are derived from Bridge, the most notable of which is Codec,
which accepts an Atlas stream for encoding and transmission.

@see Codec
*/

class Bridge
{
    public:
    
    class Map { };
    class List { };
    
    static Map m_mapBegin;
    static List m_listBegin;
      
    // Interface for stream context

    /**
     *  Begin an Atlas stream.
     */
    virtual void streamBegin() = 0;
    /**
     *  Start a message in an Atlas stream.
     */
    virtual void streamMessage(const Map&) = 0;
    /**
     *  Ends the Atlas stream.
     */
    virtual void streamEnd() = 0;
    
    // Interface for map context

    /**
     *  Starts a map object to the currently streamed map.
     */
    virtual void mapItem(const std::string& name, const Map&) = 0;
    /**
     *  Starts a list object to the currently streamed map.
     */
    virtual void mapItem(const std::string& name, const List&) = 0;
    /**
     *  Adds an integer to the currently streames map.
     */
    virtual void mapItem(const std::string& name, long) = 0;
    /**
     *  Adds a float to the currently streamed map.
     */
    virtual void mapItem(const std::string& name, double) = 0;
    /**
     *  Adds a string to the currently streamed map.
     */
    virtual void mapItem(const std::string& name, const std::string&) = 0;
    /**
     *  Ends the currently streamed map.
     */
    virtual void mapEnd() = 0;
    
    // Interface for list context
    
    /**
     *  Starts a map object in the currently streamed list.
     */
    virtual void listItem(const Map&) = 0;
    /**
     *  Starts a list object in the currently streamed list.
     */
    virtual void listItem(const List&) = 0;
    /**
     *  Adds an integer to the currently streames list.
     */
    virtual void listItem(long) = 0;
    /**
     *  Adds a float to the currently streamed list.
     */
    virtual void listItem(double) = 0;
    /**
     *  Adds a string to the currently streamed list.
     */
    virtual void listItem(const std::string&) = 0;
    /**
     *  Ends the currently streamed list.
     */
    virtual void listEnd() = 0;
};

} // Atlas namespace

#endif
