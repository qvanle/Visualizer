#include <data_structures/trie.hpp>


void Trie::init(std::vector<std::string> words)
{
    if(root != nullptr) delete root;
    root = nullptr;
    for(auto word : words)
    {
        root = insert(root, word, 0);
    }
    locating(root, 0, 0);
}
