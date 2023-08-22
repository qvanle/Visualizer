#include <data_structures/trie.hpp>

bool Trie::search(Node* node, std::string word, int index)
{
    if(node == nullptr) 
    {
        highlight({1, 2, 3});
        waitForStep();
        unhighlight({1, 2, 3});
        return false;
    }
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->highlight();
        animate_mutex.unlock();

        waitForStep();

    }
    if(index == (int) word.size())
    {
        highlight({4, 5, 6});
        waitForStep();
        unhighlight({4, 5, 6});
        if(isAnimate)
        {
            animate_mutex.lock();
            node->sprite->unhighlight();
            animate_mutex.unlock();
        }
        return node->endOfWords > 0;
    }
    int key = word[index] - 'a';
    if(isAnimate)
    {
        animate_mutex.lock();
        node->sprite->unhighlight();
        animate_mutex.unlock();
    }

    highlight({7, 8, 9, 10, 11, 12});
    waitForStep();
    unhighlight({7, 8, 9, 10, 11, 12});

    return search(node->childs[key], word, index + 1);
}

bool Trie::search(std::string word)
{
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::SEARCH];
    isAnimate = true;

    highlight({0});
    waitForStep();
    unhighlight({0});

    return search(root, word, 0);
}
