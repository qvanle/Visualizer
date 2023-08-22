#include <data_structures/trie.hpp>

Trie::Node* Trie::insert(Node* node, std::string word, int index)
{
    if(node == nullptr)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("trie/node");
        spr->typing(' ');
        node = new Node('\0', spr);
        if(root == nullptr) root = node;

        if(isAnimate)
        {
            highlight({1, 2, 3});
            waitForStep();
            unhighlight({1, 2, 3});
        }
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

    highlight({4, 5, 6, 7, 8});
    waitForStep();
    unhighlight({4, 5, 6, 7, 8});

    node->numberOfWords++;
    if(index == (int) word.size())
    {
        node->endOfWords++;
        return node;
    }

    highlight({9, 10, 11, 12, 13, 14});
    waitForStep();
    unhighlight({9, 10, 11, 12, 13, 14});

    int key = word[index] - 'a';

    Node *& currentChild = node->childs[key];
    if(currentChild == nullptr)
    {
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("trie/node");
        spr->typing(word[index]);

        currentChild = new Node(key, spr);
    }
    currentChild = insert(currentChild, word, index + 1);

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
    highlight({15});
    waitForStep();
    unhighlight({15});
    return node;
}

bool Trie::insert(std::string word)
{

    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    isAnimate = true;


    highlight({0});
    waitForStep();
    unhighlight({0});

    root = insert(root, word, 0);
    return true;
}
