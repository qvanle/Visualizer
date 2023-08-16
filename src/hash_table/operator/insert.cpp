#include <data_structures/hash_table.hpp>
#include <services.hpp>

HashTable::Node* HashTable::insert(Node* node, int k)
{
    if(node == nullptr)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("hash-table/node");
        spr->setText(NUMBER::intToString(k));
        return new Node(k, spr);
    }
    if(node->key == k) return node;
    node->pnext = insert(node->pnext, k);
    return node;
}

void HashTable::insert(int key)
{
    if(table == nullptr) defaultSetting();
    int k = key % HASH_KEY;
    table[k]->root = insert(table[k]->root, key);
    locating(table, 0, 0);
}
