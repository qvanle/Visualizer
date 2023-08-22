#include <data_structures/hash_table.hpp>


HashTable::Node* HashTable::remove(Node* node, int key)
{
    if(node == nullptr) 
    {
        return nullptr;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();
        waitForStep();
    }
    if(node->key == key)
    {
        Node* tmp = node->pnext;
        node->pnext = nullptr;
        delete node; 
        return tmp;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->unhighlight();
        animate_mutex.unlock();
    }
    if(node->pnext->key == key)
    {
        highlight({11, 12, 13, 14});
        waitForStep();
        unhighlight({11, 12, 13, 14});
    }
    node->pnext = remove(node->pnext, key);
    return node;
}


void HashTable::remove(int key)
{
    if(table == nullptr) return;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::DELETE];
    isAnimate = true;
    
    highlight({0});
    waitForStep();
    unhighlight({0});

    highlight({1, 2});
    waitForStep();
    unhighlight({1, 2});
    
    if(table[key % HASH_KEY]->root == nullptr)
    {
        highlight({3, 4, 5});
        waitForStep();
        unhighlight({3, 4, 5});
        return;
    }

    if(table[key % HASH_KEY]->root->key == key)
    {
        if(isAnimate)
        {
            animate_mutex.lock();
            table[key % HASH_KEY]->root->sprite->highlight();
            animate_mutex.unlock();
        }
        highlight({6, 7, 8});
        waitForStep();
        unhighlight({6, 7, 8});
        if(isAnimate)
        {
            animate_mutex.lock();
            table[key % HASH_KEY]->root->sprite->unhighlight();
            animate_mutex.unlock();
        }
        
        isAnimate = false;
        table[key % HASH_KEY]->root = remove(table[key % HASH_KEY]->root, key);
        return ;
    }
    highlight({10});
    waitForStep();
    table[key % HASH_KEY]->root = remove(table[key % HASH_KEY]->root, key);
    unhighlight({10});
    locating(table[key % HASH_KEY]->root, key % HASH_KEY, 0);
}
