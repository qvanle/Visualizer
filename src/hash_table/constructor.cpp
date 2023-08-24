#include <data_structures/hash_table.hpp>
#include <iostream>
#include <services.hpp>

HashTable::Node::Node(int k, Sprite* spr)
{
    key = k;
    sprite = spr;
    pnext = nullptr;
}

HashTable::Head::Head(Sprite* spr)
{
    sprite = spr;
    root = nullptr;
}

HashTable::HashTable(SDL_Renderer* r, std::mutex& m, TTF_Font* f, SDL_Rect v, int cap) : ds_mutex(m)
{
    render = r;
    font = f;
    viewport = v;
    capacity = cap;

    table = nullptr;
    
    currentSize = 0;

    isQueue = false;
    isPause = false;

    edgesColor = {255, 255, 255, 255};
    nodeColor = {20, 85, 185, 255};
    fontColor = {255, 255, 255, 255};

    shiftX = 20;
    shiftY = 20;
    distanceX = 100;
    distanceY = 70;
    isMoving = false;

    stepWait = 600;

    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;
    Script* insert = new Script(render, scriptFont);
    insert->linking("hash_table/insert");
    scripts[DATA_STRUCTURES_OPERATOR::INSERT] = insert;

    Script* remove = new Script(render, scriptFont);
    remove->linking("hash_table/remove");
    scripts[DATA_STRUCTURES_OPERATOR::DELETE] = remove;

    Script* search = new Script(render, scriptFont);
    search->linking("hash_table/search");
    scripts[DATA_STRUCTURES_OPERATOR::SEARCH] = search;

    Script* init = new Script(render, scriptFont);
    init->linking("hash_table/init");
    scripts[DATA_STRUCTURES_OPERATOR::INIT] = init;

}

int HashTable::locating(Node* node, int shiftDown, int shiftRight)
{
    if(node == nullptr) return 0;

    node->sprite->locatingX(shiftX + shiftRight * distanceX);
    node->sprite->locatingY(shiftY + shiftDown * distanceY);
    node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);

    locating(node->pnext, shiftDown, shiftRight + 1);
    return 0;
}

int HashTable::locating(Head** table, int shiftDown, int shiftRight)
{
    if(table == nullptr) return 0;

    for(int i = 0; i < HASH_KEY; i++)
    {
        if(table[i] == nullptr) continue;

        table[i]->sprite->locatingX(shiftX + shiftRight * distanceX);
        table[i]->sprite->locatingY(shiftY + (i + shiftDown) * distanceY);
        table[i]->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
        if(table[i]->root == nullptr) table[i]->sprite->show();
        else 
        {
            table[i]->sprite->hide();
            locating(table[i]->root, i + shiftDown, shiftRight);
        }
    }

    return 0;
}

void HashTable::defaultSetting()
{
    HASH_KEY = 19;
    table = new Head*[HASH_KEY];
    for(int i = 0; i < HASH_KEY; i++)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->setFontColor(fontColor);
        spr->coloring(nodeColor);
        spr->linking("hash-table/head");
        table[i] = new Head(spr);
    }
    locating(table, 0, 0);
}

void HashTable::setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4)
{
    nodeColor = c2;
    fontColor = c3;
    edgesColor = c4;
    bgColor.r = nodeColor.r * 0.5;
    bgColor.g = nodeColor.g * 0.5;
    bgColor.b = nodeColor.b * 0.5;
    bgColor.a = 255;

    for(int i = 0; i < HASH_KEY; i++)
    {
        table[i]->sprite->coloring(bgColor);
        table[i]->sprite->setFontColor(fontColor);

        Node* current = table[i]->root;

        while(current != nullptr)
        {
            current->sprite->coloring(nodeColor);
            current->sprite->setFontColor(fontColor);
            current = current->pnext;
        }
    }
}
