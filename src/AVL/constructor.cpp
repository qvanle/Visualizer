#include <algorithm>
#include <queue>

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
    pause = false;
    edgesColor = {255, 255, 255, 255};
    fontColor = {255, 255, 255, 255};
    nodeColor = {20, 85, 185, 255};
    shiftX = 20;
    shiftY = 20;
    distanceX = 40;
    distanceY = 100;
    isMoving = false;
    stepWait = 600;
    isAnimate = false;

    nodeColor = {20, 85, 185, 255};
    fontColor = {255, 255, 255, 255};
    bgColor = {0, 0, 0, 255};
    
    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;
    Script* insert = new Script(render, scriptFont);
    insert->linking("AVL/insert");
    scripts[DATA_STRUCTURES_OPERATOR::INSERT] = insert;

    Script* remove = new Script(render, scriptFont);
    remove->linking("AVL/remove");
    scripts[DATA_STRUCTURES_OPERATOR::DELETE] = remove;

    Script* search = new Script(render, scriptFont);
    search->linking("AVL/search");
    scripts[DATA_STRUCTURES_OPERATOR::SEARCH] = search;

    Script* init = new Script(render, scriptFont);
    init->linking("AVL/init");
    scripts[DATA_STRUCTURES_OPERATOR::INIT] = init;

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

void AVL::setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4)
{
    bgColor = c1;
    nodeColor = c2;
    fontColor = c3;
    edgesColor = c4;

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node == nullptr)
            continue;
        node->sprite->coloring(nodeColor);
        node->sprite->setFontColor(fontColor);
        node->sprite->coloring(nodeColor);
        q.push(node->lson);
        q.push(node->rson);
    }
}
