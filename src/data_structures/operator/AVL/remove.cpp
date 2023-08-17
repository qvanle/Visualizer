#include <data_structures.hpp>

void DataStructures::removeAVL(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));

    avl->remove(value);
}
