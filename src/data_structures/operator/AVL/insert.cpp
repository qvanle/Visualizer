#include <data_structures.hpp>

void DataStructures::insertAVL(InputBox* inp)
{
    int value = NUMBER::stringToInt(inp->getText(1));
    avl->insert(value);
}
