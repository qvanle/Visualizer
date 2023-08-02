#include <button.hpp>

BUTTON_ACTION Button::getAction()
{
    return action;
}

std::string Button::getNextScreen()
{
    if(!args.contains("next-screen"))
        return "";
    return args["next-screen"].get<std::string>();
}

DATA_STRUCTURES_TYPE Button::getDataType()
{
    if(!args.contains("data-type")) 
        return DATA_STRUCTURES_TYPE::NONE;

    std::string type = args["data-type"].get<std::string>();

    if(type == "AVL")
        return DATA_STRUCTURES_TYPE::AVL;

    if(type == "HASH_TABLE")
        return DATA_STRUCTURES_TYPE::HASH_TABLE;

    if(type == "GRAPH")
        return DATA_STRUCTURES_TYPE::GRAPH;

    if(type == "TRIE")
        return DATA_STRUCTURES_TYPE::TRIE;

    if(type == "BTREE_4TH")
        return DATA_STRUCTURES_TYPE::BTREE_4TH;
    if(type == "HEAP")
        return DATA_STRUCTURES_TYPE::HEAP;

    return DATA_STRUCTURES_TYPE::NONE;
}
