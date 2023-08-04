#include <data_structures.hpp>

DataStructures::~DataStructures()
{
    render = nullptr;
    for(auto& i : node)
        delete i;
    node.clear();
}
