#include <data_structures/btree4th.hpp>

bool BTree4th::search(Node* node, int key)
{
    if(node == nullptr) return false;

    if(node->key[0] == nullptr) return false;

    if(node->containsKey(key)) return true;

    for(int i = 0; i < 3; i++)
    {
        if(node->key[i] == nullptr) break;

        if(key < *(node->key[i]))
        {
            return search(node->child[i], key);
        }
    }
    return search(node->child[3], key);
}

bool BTree4th::search(int key)
{
    return search(root, key);
}
