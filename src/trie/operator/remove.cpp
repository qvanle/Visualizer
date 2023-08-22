#include <data_structures/trie.hpp>

Trie::Node* Trie::remove(Node* node, std::string word, int index)
{
    if(node == nullptr) 
    {
        highlight({1, 2, 3});
        waitForStep();
        unhighlight({1, 2, 3});
        return nullptr;
    }
    node->numberOfWords--;

    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();

        waitForStep();
    }

    if(index == (int) word.size())
    {
        highlight({4, 5});
        waitForStep();
        unhighlight({4, 5});

        node->endOfWords--;
    }else 
    {
        highlight({6, 7, 8, 9, 10, 11, 12, 13});
        waitForStep();
        unhighlight({6, 7, 8, 9, 10, 11, 12, 13});

        if(isAnimate)
        {
            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
        }

        int key = word[index] - 'a';
        node->childs[key] = remove(node->childs[key], word, index + 1);
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

    if(node->numberOfWords == 0)
    {
        highlight({14});
        waitForStep();
        unhighlight({14});
        delete node;
        node = nullptr;
    }

    return node;
}

bool Trie::remove(std::string word)
{
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::DELETE];

    isAnimate = false;
    if(!search(root, word, 0)) 
    {
        isAnimate = true;
        highlight({1, 2, 3});
        waitForStep();
        unhighlight({1, 2, 3});

        return false;
    }
    isAnimate = true;

    highlight({0});
    waitForStep();
    unhighlight({0});

    root = remove(root, word, 0);
    return true;
}
