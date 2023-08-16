#include <iostream>
#include <data_structures/hash_table.hpp>
#include <services.hpp>


void HashTable::init(std::vector<int> v, int key)
{
    HASH_KEY = key;
    table = new Head*[HASH_KEY];
    for(int i = 0; i < HASH_KEY; i++)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("hash-table/head");
        table[i] = new Head(spr);
    }
    for(int i : v) 
    {
        int k = i % HASH_KEY;
        table[k]->root = insert(table[k]->root, i);
    }
    locating(table, 0, 0);
}
