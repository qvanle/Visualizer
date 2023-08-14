#include <data_structures/trie.hpp>
Trie::Node::~Node()
{
    for (int i = 0; i < 26; i++)
        if(childs[i] != nullptr) delete childs[i];
}


Trie::~Trie()
{
    if(root != nullptr) delete root;
}

