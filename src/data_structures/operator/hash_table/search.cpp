#include <data_structures.hpp>

void DataStructures::searchHashTable(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));

    hashTable->search(value);
}


