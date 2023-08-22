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
    }
    node->numberOfWords++;
    if(index == (int) word.size())
    {
        node->endOfWords++;
        return node;
    }
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
    return node;
}

bool Trie::insert(std::string word)
{

    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INSERT];
    root = insert(root, word, 0);
    return true;
}
