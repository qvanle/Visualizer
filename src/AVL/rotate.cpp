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

AVL::Node* AVL::rotateLeft(Node* node)
{
    if(node == nullptr) return nullptr;
    if(node->rson == nullptr) return node;
    
    if(isAnimate)
    {
        waitForStep();
        node->sprite->highlight();
        node->rson->sprite->highlight();
        if(node->rson->rson != nullptr) 
            node->rson->rson->sprite->highlight();
        waitForStep();

        node->sprite->unhighlight();
        node->rson->sprite->unhighlight();
        if(node->rson->rson != nullptr) 
            node->rson->rson->sprite->unhighlight();
        waitForStep();
    }

    Node* tmp = node->rson;
    node->rson = tmp->lson;
    tmp->lson = node;
    node->repair();
    tmp->repair();

    return tmp;
}

AVL::Node* AVL::rotateRight(Node* node)
{
    if(node == nullptr) return nullptr;
    if(node->lson == nullptr) return node;
    if(isAnimate)
    {
        waitForStep();
        node->sprite->highlight();
        node->lson->sprite->highlight();
        if(node->lson->lson != nullptr) 
            node->lson->lson->sprite->highlight();
        waitForStep();
        node->sprite->unhighlight();
        node->lson->sprite->unhighlight();
        if(node->lson->lson != nullptr) 
            node->lson->lson->sprite->unhighlight();
        waitForStep();
    }
    Node* tmp = node->lson;
    node->lson = tmp->rson;
    int maxDepth;
    tmp->rson = node;
    node->repair();
    tmp->repair();
    return tmp;
}

void AVL::Node::repair()
{
    high = 1;
    if(lson != nullptr) high = std::max(high, lson->high + 1);
    if(rson != nullptr) high = std::max(high, rson->high + 1);
}

AVL::Node* AVL::balancing(Node* node)
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
