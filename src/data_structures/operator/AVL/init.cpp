#include <data_structures.hpp>

void DataStructures::initAVL(InputBox* inp)
{
    std::vector<int> v = NUMBER::stringToArray(inp->getText(1));
    avl->init(v);
}
