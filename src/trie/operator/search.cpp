#include <data_structures/trie.hpp>

bool Trie::search(Node* node, std::string word, int index)
{
    if(node == nullptr) return false;
    if(index == (int) word.size())
        return node->endOfWords > 0;
    
    int key = word[index] - 'a';

    return search(node->childs[key], word, index + 1);
}

bool Trie::search(std::string word)
{
    return search(root, word, 0);
}
