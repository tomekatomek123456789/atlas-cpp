// This file may be redistributed and modified under the terms of the
// GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Michael Day

#ifndef ATLAS_CODECS_XML_H
#define ATLAS_CODECS_XML_H

#include "Utility.h"
#include "../Codec.h"

#include <stack>

using namespace std;
using namespace Atlas;

/*

Sample output for this codec: (whitespace added for clarity)

<atlas>
    <map>
	<int name="foo">13</int>
	<float name="meep">1.5</float>
	<string name="bar">hello</string>
	<list name="args">
	    <int>1</int>
	    <int>2</int>
	    <float>3.0</float>
	</list>
    </map>
</atlas>

The complete specification is located in cvs at:
    forge/protocols/atlas/spec/xml_syntax.html

*/

class XML : public Codec
{
    public:

    XML(const Codec::Parameters&);

    virtual void poll(bool can_read = true);

    virtual void streamBegin();
    virtual void streamMessage(const Map&);
    virtual void streamEnd();
    
    virtual void mapItem(const std::string& name, const Map&);
    virtual void mapItem(const std::string& name, const List&);
    virtual void mapItem(const std::string& name, int);
    virtual void mapItem(const std::string& name, double);
    virtual void mapItem(const std::string& name, const std::string&);
    virtual void mapEnd();
    
    virtual void listItem(const Map&);
    virtual void listItem(const List&);
    virtual void listItem(int);
    virtual void listItem(double);
    virtual void listItem(const std::string&);
    virtual void listEnd();

    protected:

    iostream& socket;
    Bridge* bridge;
    
    enum Token
    {
	TOKEN_TAG,
	TOKEN_START_TAG,
	TOKEN_END_TAG,
	TOKEN_DATA,
    };
    
    Token token;
    
    enum State
    {
	PARSE_NOTHING,
	PARSE_STREAM,
        PARSE_MAP,
        PARSE_LIST,
	PARSE_INT,
	PARSE_FLOAT,
	PARSE_STRING,
    };
    
    stack<State> state;
    stack<string> data;

    string tag;
    string name;

    inline void tokenTag(char);
    inline void tokenStartTag(char);
    inline void tokenEndTag(char);
    inline void tokenData(char);

    inline void parseStartTag();
    inline void parseEndTag();
};

#endif // ATLAS_CODECS_XML_H
