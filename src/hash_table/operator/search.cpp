#include <data_structures/hash_table.hpp>


bool HashTable::search(Node* node, int key)
{
    if(node == nullptr) 
    {
        highlight({9});
        waitForStep();
        unhighlight({9});
        return false;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();
        waitForStep();
        animate_mutex.lock();
        node->sprite->unhighlight();
        animate_mutex.unlock();
    }
    if(node->key == key) 
    {
        highlight({4, 5});
        waitForStep();
        unhighlight({4, 5});
        return true;
    }
    return search(node->pnext, key);
}

bool HashTable::search(int key)
{
    if(table == nullptr) return false;
    isAnimate = true;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::SEARCH];

    highlight({0});
    waitForStep();
    unhighlight({0});

    highlight({1, 2});
    waitForStep();
    unhighlight({1, 2});
    
    if(isAnimate)
    {
        animate_mutex.lock();
        table[key % HASH_KEY]->sprite->highlight();
        animate_mutex.unlock();
    }
    highlight({3});
    waitForStep();
    if(isAnimate)
    {
        animate_mutex.lock();
        table[key % HASH_KEY]->sprite->unhighlight();
        animate_mutex.unlock();
    }
    search(table[key % HASH_KEY]->root, key);

    unhighlight({3});

    return true;
}
