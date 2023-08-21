#include <data_structures/btree4th.hpp>

BTree4th::Node* BTree4th::split(Node* node)
{
    if(node == nullptr) return nullptr;
    if(!node->isFull()) return node;

    Node* lson = new Node(node, *(node->key[0]), node->child[0], node->child[1]);
    Node* rson = new Node(node, *(node->key[2]), node->child[2], node->child[3]);
    
    delete node->key[0];
    node->key[0] = node->key[1];

    node->key[1] = nullptr;

    delete node->key[2];
    node->key[2] = nullptr;

    node->child[0] = lson;
    node->child[1] = rson;
    node->child[2] = nullptr;
    node->child[3] = nullptr;
    
    return node;
}
