#include <iostream>
#include <data_structures/hash_table.hpp>
#include <services.hpp>


void HashTable::init(std::vector<int> v, int key)
{
    if(table != nullptr) 
    {
        for(int i = 0; i < HASH_KEY; i++)
        {
            delete table[i];
            table[i] = nullptr;
        }
        delete[] table;
    }
    HASH_KEY = key;
    table = new Head*[HASH_KEY];
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INIT];

    isAnimate = false;

    for(int i = 0; i < HASH_KEY; i++)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("hash-table/head");
        spr->setFontColor(fontColor);
        spr->coloring(SDL_Color{bgColor.r, bgColor.r, bgColor.r, 255});
        table[i] = new Head(spr);
    }
    for(int i : v) 
    {
        int k = i % HASH_KEY;
        table[k]->root = insert(table[k]->root, i);
    }
    locating(table, 0, 0);
}
