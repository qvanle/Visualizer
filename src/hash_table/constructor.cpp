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

HashTable::HashTable(SDL_Renderer* r, TTF_Font* f, SDL_Rect v, int cap)
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
    shiftX = 20;
    shiftY = 20;
    distanceX = 100;
    distanceY = 80;
    isMoving = false;
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
        spr->linking("hash-table/head");
        table[i] = new Head(spr);
    }
    locating(table, 0, 0);
}
