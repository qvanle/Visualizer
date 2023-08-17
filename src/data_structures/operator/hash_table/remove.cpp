#include <data_structures.hpp>

void DataStructures::removeHashTable(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));

    hashTable->remove(value);
}
