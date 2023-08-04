#include <data_structures.hpp>

void DataStructures::rendering()
{
    Object::rendering();
    for(auto& i : node)
        i->rendering();
}
