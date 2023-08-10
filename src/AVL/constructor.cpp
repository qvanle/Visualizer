#include <algorithm>

#include <data_structures/AVL.hpp>

int compare(Node* a, Node* b)
{
    if(a == nullptr && b == nullptr) return 0;
    if(a == nullptr) return -1;
    if(b == nullptr) return 1;
    if(a->key < b->key) return -1;
    if(a->key > b->key) return 1;
    return 0;
}
Node::Node(int k, Sprite* spr)
{
    key = k;
    sprite = spr;
    high = 1;
    lson = nullptr;
    rson = nullptr;
}
AVL::AVL(SDL_Renderer* rend, TTF_Font* f, SDL_Rect vp, int cap)
{
    root = nullptr;
    render = rend;
    font = f;
    viewport = vp;
    capacity = cap;
    sizeOfTree = 0;
    animation = false;
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftY = 20;
    distanceX = 75;
    distanceY = 90;
    isMoving = false;
}
int AVL::maxDepth()
{
    return maxDepth(root);
}

int AVL::maxDepth(Node* node)
{
    if(node == nullptr) return 0;

    return 1 + std::max(maxDepth(node->lson), maxDepth(node->rson));
}


int AVL::locating(Node* node, int shiftDown, int shiftRight)
{
    if(node == nullptr) 
    {
        int shift = maxHigh - shiftDown;
        return (1 << shift) - 1;
    }
    int left = locating(node->lson, shiftDown + 1, shiftRight);

    node->sprite->locatingX(shiftX + shiftRight * distanceX + left * distanceX);
    node->sprite->locatingY(shiftY + shiftDown * distanceY);
    node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
    locating(node->rson, shiftDown + 1, shiftRight + left + 1);

    return (1 << (maxHigh - shiftDown)) - 1;
}
