#include <data_structures/hash_table.hpp>


bool HashTable::search(Node* node, int key)
{
    if(node == nullptr) return false;
    if(node->key == key) return true;
    return search(node->pnext, key);
}

bool HashTable::search(int key)
{
    if(table == nullptr) return false;
    return search(table[key % HASH_KEY]->root, key);
}
