#include <algorithm>

#include <data_structures/AVL.hpp>

int AVL::compare(Node* a, Node* b)
{
    if(a == nullptr && b == nullptr) return 0;
    if(a == nullptr) return -1;
    if(b == nullptr) return 1;
    if(a->key < b->key) return -1;
    if(a->key > b->key) return 1;
    return 0;
}
AVL::Node::Node(int k, Sprite* spr)
{
    key = k;
    sprite = spr;
    high = 1;
    lson = nullptr;
    rson = nullptr;
}
AVL::AVL(SDL_Renderer* rend, std::mutex& m, TTF_Font* f, SDL_Rect vp, int cap) : ds_mutex(m)
{
    root = nullptr;
    render = rend;
    font = f;
    viewport = vp;
    capacity = cap;
    sizeOfTree = 0;
    isQueue = false;
    isPause = false;
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftY = 20;
    distanceX = 40;
    distanceY = 100;
    isMoving = false;
    stepWait = 600;
    isAnimate = false;

    
    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;
    Script* insert = new Script(render, scriptFont);
    insert->linking("AVL/insert");
    scripts[DATA_STRUCTURES_OPERATOR::INSERT] = insert;

    currentScript = insert;
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

    if(node->sprite != nullptr)
    {
        node->sprite->locatingX(shiftX + shiftRight * distanceX + left * distanceX);
        node->sprite->locatingY(shiftY + shiftDown * distanceY);
        node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
    }
    locating(node->rson, shiftDown + 1, shiftRight + left + 1);

    return (1 << (maxHigh - shiftDown)) - 1;
}
