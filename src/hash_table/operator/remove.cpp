#include <data_structures/hash_table.hpp>


HashTable::Node* HashTable::remove(Node* node, int key)
{
    if(node == nullptr) return nullptr;
    if(node->key == key)
    {
        Node* tmp = node->pnext;
        node->pnext = nullptr;
        delete node; 
        return tmp;
    }
    node->pnext = remove(node->pnext, key);
    return node;
}


void HashTable::remove(int key)
{
    if(table == nullptr) return;
    table[key % HASH_KEY]->root = remove(table[key % HASH_KEY]->root, key);
    locating(table[key % HASH_KEY]->root, key % HASH_KEY, 0);
}
