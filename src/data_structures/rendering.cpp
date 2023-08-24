#include <data_structures.hpp>

void DataStructures::rendering()
{
    Object::rendering();
    for(auto& i : node)
        i->rendering();
    for(auto& i : displays)
        i->rendering();
    if(avl != nullptr) 
        avl->rendering();
    if(trie != nullptr)
        trie->rendering();
    if(hashTable != nullptr)
        hashTable->rendering();
    if(minheap != nullptr)
        minheap->rendering();
    if(graph != nullptr)
        graph->rendering();
}
