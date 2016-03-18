#include <Atlas/Objects/Operation.h>
#include <Atlas/Objects/Entity.h>
#include <Atlas/Objects/loadDefaults.h>

#include <iostream>
#include <cstdlib>
#include <cassert>

using Atlas::Objects::Root;
using Atlas::Objects::Operation::Look;
using Atlas::Objects::Entity::Account;
using Atlas::Objects::smart_dynamic_cast;
using Atlas::Objects::objectDefinitions;

using Atlas::Message::Element;
using Atlas::Message::MapType;
using Atlas::Message::ListType;

int main(int argc, char** argv)
{
    std::string atlas_xml_path;
    char * srcdir_env = getenv("srcdir");
    if (srcdir_env != 0) {
        atlas_xml_path = srcdir_env;
        atlas_xml_path += "/";
    }
    atlas_xml_path += "../../protocol/spec/atlas.xml";
    try {
	Atlas::Objects::loadDefaults(atlas_xml_path);
    } catch(Atlas::Objects::DefaultLoadingException e) {
	std::cout << "DefaultLoadingException: "
             << e.getDescription() << std::endl;
    }
    Root root = Atlas::Objects::objectDefinitions.find("root")->second;
    Root root_inst;
    root_inst->setAttr("id", std::string("root_instantiation"));
    assert(root->getAttr("id").asString() == "root");
    assert(root_inst->getAttr("id").asString() == "root_instantiation");
    assert(root->getAttr("parents").asList().size() == 0);
    assert(root_inst->getAttr("parents").asList().size() == 1);
    assert((*root_inst->getAttr("parents").asList().begin()).asString() ==
            "root");

    Look look = smart_dynamic_cast<Look>(objectDefinitions.find("look")->second);
    Look look_inst;
    look_inst->setAttr("id", std::string("look_instantiation"));
    assert(look->getAttr("id").asString() == "look");
    assert(look_inst->getAttr("id").asString() == "look_instantiation");
    assert(look->getAttr("parents").asList().size() == 1);
    assert((*look->getAttr("parents").asList().begin()).asString() ==
            "perceive");
    assert(look_inst->getAttr("parents").asList().size() == 1);
    assert((*look_inst->getAttr("parents").asList().begin()).asString() ==
            "look");

    Account acct = smart_dynamic_cast<Account>(objectDefinitions.find("account")->second);
    Account acct_inst;
    acct_inst->setAttr("id", std::string("account_instantiation"));
    assert(acct->getAttr("id").asString() == "account");
    assert(acct_inst->getAttr("id").asString() == "account_instantiation");
    assert(acct->getAttr("parents").asList().size() == 1);
    assert((*acct->getAttr("parents").asList().begin()).asString() ==
            "admin_entity");
    assert(acct_inst->getAttr("parents").asList().size() == 1);
    assert((*acct_inst->getAttr("parents").asList().begin()).asString() ==
            "account");



    {

        Atlas::Objects::Entity::Anonymous anon;
        anon->setLoc("12345");
        ListType velocity;
        velocity.push_back(1.4);
        velocity.push_back(2.4);
        velocity.push_back(3.4);
        anon->setVelocityAsList(velocity);
        ListType bbox;
        bbox.push_back(1.4);
        bbox.push_back(2.4);
        bbox.push_back(3.4);
        bbox.push_back(2.4);
        anon->setAttr("bbox", bbox);

        Atlas::Objects::Operation::Move move;
        move->setFrom("123456");
        move->setTo("123456");
        move->setSeconds(12345678);
        move->setId("123456");
        move->setArgs1(anon);

        Atlas::Objects::Operation::Sight sight;
        sight->setFrom("123456");
        sight->setTo("123456");
        sight->setSeconds(12345678);
        sight->setId("123456");
        sight->setArgs1(move);

        Atlas::Message::MapType map;
        sight->addToMessage(map);
        std::cout << map.size() << std::flush;
        assert(map.size() == 7);
        assert(map["objtype"].String() == "op");
        assert(map["from"].String() == "123456");
        assert(map["to"].String() == "123456");
        assert(map["seconds"].Float() == 12345678);
        assert(map["id"].String() == "123456");
        assert(map["args"].List().size() == 1);


    }

}
