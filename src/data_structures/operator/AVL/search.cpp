#include <data_structures.hpp>

void DataStructures::searchAVL(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));

    avl->search(value);
}

