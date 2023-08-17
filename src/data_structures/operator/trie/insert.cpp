#include <data_structures.hpp>

void DataStructures::insertTrie(InputBox* inp)
{
    std::string value = inp->getText(1);
    trie->insert(value);
}
