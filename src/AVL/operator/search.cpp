#include <data_structures/AVL.hpp>
#include <services.hpp>


void AVL::search(Node* node, int key)
{

    if(node == nullptr)
    {
        highlight({2, 3, 4});
        waitForStep();
        unhighlight({2, 3, 4});
        return ;
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
        highlight({6, 7, 8});
        waitForStep();
        unhighlight({6, 7, 8});
        return ;
    }
    if(node->key < key)
    {
        highlight({10, 11});
        waitForStep();
        unhighlight({10, 11});
        search(node->rson, key);
    }
    else
    {
        highlight({12, 13, 14});
        waitForStep();
        unhighlight({12, 13, 14});
        search(node->lson, key);
    }
}

bool AVL::search(int key)
{
    if(sizeOfTree == 0)
    {
        return false;
    }
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::SEARCH];
    cache = nullptr;
    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");
    sprite->setText(NUMBER::intToString(key));
    
    cache = new Node(key, sprite);

    isAnimate = true;

    highlight({0});
    waitForStep();
    unhighlight({0});


    search(root, key);
    
    delete cache;
    cache = nullptr;
    return true;
}

