#include <data_structures/trie.hpp>

Trie::Node* Trie::remove(Node* node, std::string word, int index)
{
    if(node == nullptr) return nullptr;
    node->numberOfWords--;

    if(index == (int) word.size())
    {
        node->endOfWords--;
    }else 
    {
        int key = word[index] - 'a';
        node->childs[key] = remove(node->childs[key], word, index + 1);
    }

    if(node->numberOfWords == 0)
    {
        delete node;
        node = nullptr;
    }

    return node;
}

bool Trie::remove(std::string word)
{
    if(!search(root, word, 0)) return false;
    root = remove(root, word, 0);
    locating(root, 0, 0);
    return true;
}
