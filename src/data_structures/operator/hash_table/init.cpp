#include <data_structures.hpp>

void DataStructures::initHashTable(InputBox* inp)
{
    int HASH_KEY = NUMBER::stringToInt(inp->getText(1));
    std::vector<int> v = NUMBER::stringToArray(inp->getText(2));
    hashTable->init(v, HASH_KEY);
}
