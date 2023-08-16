#include <data_structures/hash_table.hpp>

HashTable::Node::~Node()
{
    if(sprite != nullptr) delete sprite;
    if(pnext != nullptr) delete pnext;
}

HashTable::Head::~Head()
{
    if(sprite != nullptr) delete sprite;
    if(root != nullptr) delete root;
}

HashTable::~HashTable()
{
    if(table != nullptr) 
    {
        for(int i = 0; i < HASH_KEY; i++)
        {
            if(table[i] != nullptr) delete table[i];
        }
        delete [] table;
    }
}

