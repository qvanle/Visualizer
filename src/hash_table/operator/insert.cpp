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
        highlight({1, 2});
        waitForStep();
        unhighlight({1, 2});
        return new Node(k, spr);
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();
        waitForStep();
    }
    if(node->pnext == nullptr)
    {
        if(isAnimate)
        {
            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
        }
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("hash-table/node");
        spr->setText(NUMBER::intToString(k));
        node->pnext = new Node(k, spr);

        if(isAnimate)
        {
            animate_mutex.lock();
            node->pnext->sprite->highlight();
            animate_mutex.unlock();
        }

        highlight({10});
        waitForStep();
        unhighlight({10});

        if(isAnimate)
        {
            animate_mutex.lock();
            node->pnext->sprite->unhighlight();
            animate_mutex.unlock();
        }
    }else 
    {
        highlight({7, 8, 9});
        waitForStep();
        unhighlight({7, 8, 9});
        if(isAnimate)
        {
            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
        }
        node->pnext = insert(node->pnext, k);
    }
    return node;
}

void HashTable::insert(int key)
{
    if(table == nullptr) defaultSetting();
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    
    isAnimate = true;
    
    highlight({0});
    waitForStep();
    unhighlight({0});
    
    highlight({1, 2});
    waitForStep();
    unhighlight({1, 2});
    
    int k = key % HASH_KEY;
    
    if(isAnimate && table[k]->root == nullptr)
    {
        animate_mutex.lock();
        table[k]->sprite->highlight();
        animate_mutex.unlock();

        waitForStep();

        animate_mutex.lock();
        table[k]->sprite->unhighlight();
        animate_mutex.unlock();
    }

    table[k]->root = insert(table[k]->root, key);
    locating(table, 0, 0);
}
