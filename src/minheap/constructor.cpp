#include <data_structures/minheap.hpp>

minHeap::Node::Node(int value, Sprite* spr) 
{
    sprite = spr;
    this->value = value;
}

minHeap::minHeap(SDL_Renderer* r, std::mutex& m, TTF_Font* f, SDL_Rect v, int cap) : ds_mutex(m)
{
    render = r;
    font = f;
    viewport = v;
    capacity = cap;
    nodeColor = {20, 85, 185, 255};
    fontColor = {255, 255, 255, 255};
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftY = 20;
    distanceX = 60;
    distanceY = 80;
    isMoving = false;
    stepWait = 600;
    isAnimate = false;
    inverse = false;
    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;

    Script* insert = new Script(render, scriptFont);
    insert->linking("minheap/insert");
    scripts[DATA_STRUCTURES_OPERATOR::INSERT] = insert;

    Script* remove = new Script(render, scriptFont);
    remove->linking("minheap/remove");
    scripts[DATA_STRUCTURES_OPERATOR::DELETE] = remove;

    Script* search = new Script(render, scriptFont);
    search->linking("minheap/top");
    scripts[DATA_STRUCTURES_OPERATOR::TOP] = search;

    Script* init = new Script(render, scriptFont);
    init->linking("minheap/init");
    
    scripts[DATA_STRUCTURES_OPERATOR::INIT] = init;

    Script* size = new Script(render, scriptFont);
    size->linking("minheap/size");
    scripts[DATA_STRUCTURES_OPERATOR::SIZE] = size;

}

void minHeap::setmin()
{
    inverse = false;
}

void minHeap::setmax()
{
    inverse = true;
}

void minHeap::setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4)
{
    bgColor = c1;
    nodeColor = c2;
    fontColor = c3;
    edgesColor = c4;

    for(auto i : value)
    {
        i->sprite->setFontColor(fontColor);
        i->sprite->coloring(nodeColor);
    }
}
