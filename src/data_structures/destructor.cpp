#include <data_structures.hpp>

DataStructures::~DataStructures()
{
    render = nullptr;
    for(auto& i : node)
        delete i;
    for(auto& i : displays)
        delete i;
    node.clear();
    if(avl != nullptr) delete avl;
}
