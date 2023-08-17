#include <data_structures.hpp>


void DataStructures::insertHashTable(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));
    hashTable->insert(value);
}
