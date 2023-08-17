#include <data_structures.hpp>

void DataStructures::initTrie(InputBox* inp)
{
    std::vector<std::string> v = SIUSTRING::split(inp->getText(1));
    trie->init(v);
}
