#include <data_structures/btree4th.hpp>


void BTree4th::init(std::vector<int> keys)
{
    for(int i = 0; i < keys.size(); i++)
    {
        root = insert(root, keys[i]);
    }
}
