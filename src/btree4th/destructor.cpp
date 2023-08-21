#include <data_structures/btree4th.hpp>

BTree4th::~BTree4th()
{
    if(root != nullptr) delete root;
}
