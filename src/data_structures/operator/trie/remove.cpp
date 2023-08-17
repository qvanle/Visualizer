#include <data_structures.hpp>

void DataStructures::removeTrie(InputBox* inp)
{
    trie->remove(inp->getText(1));
}
