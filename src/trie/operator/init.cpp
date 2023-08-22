#include <data_structures/trie.hpp>


void Trie::init(std::vector<std::string> words)
{
    if(root != nullptr) delete root;
    root = nullptr;
    currentScript = scripts[DATA_STRUCTURES_OPERATOR::INIT];
    isAnimate = false;
    for(auto word : words)
    {
        root = insert(root, word, 0);
    }
}
