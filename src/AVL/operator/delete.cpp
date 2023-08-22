#include <data_structures/AVL.hpp>
#include <services.hpp>

AVL::Node* AVL::unplugSmallest(Node* node, struct Node*& n2)
{
    if(node == nullptr) return nullptr;
    if(node->lson == nullptr)
    {
        n2 = node;
        return node->rson;
    }
    node->lson = unplugSmallest(node->lson, n2);
    return node;
}
AVL::Node* AVL::remove(Node* node, int key)
{
    if(node == nullptr) 
    {
        highlight({1, 2, 3});
        waitForStep();
        unhighlight({1, 2, 3});
        return node;
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
    if(node->key < key)
    {
        highlight({7, 8});
        waitForStep();
        unhighlight({7, 8});

        node->rson = remove(node->rson, key);

        highlight({13});
        waitForStep();

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
        node = balancing(node);
        unhighlight({13});

        return node;
    }
    else if(node->key > key)
    {
        highlight({9, 10, 11});
        waitForStep();
        unhighlight({9, 10, 11});
        node->lson = remove(node->lson, key);

        highlight({13});
        waitForStep();

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

        node = balancing(node);
        unhighlight({13});


        return node;
    }
    else
    {
        highlight({5, 6});
        waitForStep();
        unhighlight({5, 6});
        
        if(node->rson == nullptr)
        {
            Node* temp = node->lson;
            node->lson = nullptr;
            node->rson = nullptr;


            highlight({13});
            waitForStep();
            temp = balancing(temp);
            unhighlight({13});

            delete node;
            return temp;
        }else 
        {
            Node* temp = unplugSmallest(node->rson, cache);

            cache->lson = node->lson;

            cache->rson = temp;


            node->lson = nullptr;
            node->rson = nullptr;

            delete node;
            node = cache;
            highlight({13});
            waitForStep();
            node = balancing(node);
            unhighlight({13});
            return node;
        }
    }
}

bool AVL::remove(int key)
{
    if(sizeOfTree == 0)
    {
        return false;
    }

    currentScript = scripts[DATA_STRUCTURES_OPERATOR::DELETE];

    isAnimate = true;

    highlight({0});
    waitForStep();
    unhighlight({0});

    root = remove(root, key);
    locating(root, 0, 0);

    cache = nullptr;
    return true;
}

