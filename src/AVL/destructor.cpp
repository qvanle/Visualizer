#include <data_structures/AVL.hpp>

Node::~Node()
{
    if(lson != nullptr) delete lson;
    if(rson != nullptr) delete rson;
    delete sprite;
}
AVL::~AVL()
{
    if(root != nullptr) delete root;
}