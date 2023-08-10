#include <data_structures/AVL.hpp>

int AVL::getHigh(Node* node)
{
    if(node == nullptr) return 0;
    return node->high;
}

int AVL::balanceFactor(Node* node)
{
    if(node == nullptr) return 0;
    return getHigh(node->lson) - getHigh(node->rson);
}

Node* AVL::rotateLeft(Node* node)
{
    if(node == nullptr) return nullptr;
    if(node->rson == nullptr) return node;
    Node* tmp = node->rson;
    node->rson = tmp->lson;
    tmp->lson = node;
    node->repair();
    tmp->repair();
    return tmp;
}

Node* AVL::rotateRight(Node* node)
{
    if(node == nullptr) return nullptr;
    if(node->lson == nullptr) return node;
    Node* tmp = node->lson;
    node->lson = tmp->rson;
    int maxDepth;
    tmp->rson = node;
    node->repair();
    tmp->repair();
    return tmp;
}

void Node::repair()
{
    high = 1;
    if(lson != nullptr) high = std::max(high, lson->high + 1);
    if(rson != nullptr) high = std::max(high, rson->high + 1);
}

Node* AVL::balancing(Node* node)
{
    if(node == nullptr) 
    {
        return nullptr;
    }
    node->repair();
    int bf = balanceFactor(node);

    if(bf >= -1 && bf <= 1) return node;
    if(bf > 1)
    {
        if(balanceFactor(node->lson) < 0)
        {
            node->lson = rotateLeft(node->lson);
            node->repair();
        }
        node = rotateRight(node);
    }
    else if(bf < -1)
    {
        if(balanceFactor(node->rson) > 0)
        {
            node->rson = rotateRight(node->rson);
            node->repair();
        }
        node = rotateLeft(node);
        node->repair();
    }
    return node;
}
