#include <data_structures/btree4th.hpp>

BTree4th::Node::Node(Node* p)
{
    key[0] = nullptr;
    key[1] = nullptr;
    key[2] = nullptr;

    child[0] = nullptr;
    child[1] = nullptr;
    child[2] = nullptr;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k)
{
    key[0] = new int(k);
    key[1] = nullptr;
    key[2] = nullptr;

    child[0] = nullptr;
    child[1] = nullptr;
    child[2] = nullptr;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k1, int k2)
{
    key[0] = new int(k1);
    key[1] = new int(k2);
    key[2] = nullptr;

    child[0] = nullptr;
    child[1] = nullptr;
    child[2] = nullptr;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k1, int k2, int k3)
{
    key[0] = new int(k1);
    key[1] = new int(k2);
    key[2] = new int(k3);

    child[0] = nullptr;
    child[1] = nullptr;
    child[2] = nullptr;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k, Node* lson, Node* rson)
{
    key[0] = new int(k);
    key[1] = nullptr;
    key[2] = nullptr;

    child[0] = lson;
    child[1] = rson;
    child[2] = nullptr;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k1, int k2, Node* lson, Node* mson, Node* rson)
{
    key[0] = new int(k1);
    key[1] = new int(k2);
    key[2] = nullptr;

    child[0] = lson;
    child[1] = mson;
    child[2] = rson;
    child[3] = nullptr;

    parent = p;
}

BTree4th::Node::Node(Node* p, int k1, int k2, int k3, Node* lson, Node* m1son, Node* m2son, Node* rson)
{
    key[0] = new int(k1);
    key[1] = new int(k2);
    key[2] = new int(k3);

    child[0] = lson;
    child[1] = m1son;
    child[2] = m2son;
    child[3] = rson;

    parent = p;
}


bool BTree4th::Node::containsKey(int k)
{
    if (key[0] != nullptr && *key[0] == k)
        return true;
    if (key[1] != nullptr && *key[1] == k)
        return true;
    if (key[2] != nullptr && *key[2] == k)
        return true;
    return false;
}

int* BTree4th::Node::findKey(int k)
{
    if (key[0] != nullptr && *key[0] == k)
        return key[0];
    if (key[1] != nullptr && *key[1] == k)
        return key[1];
    if (key[2] != nullptr && *key[2] == k)
        return key[2];
    return nullptr;
}

bool BTree4th::Node::isFull()
{
    return key[2] != nullptr;
}

bool BTree4th::Node::isLeaf()
{
    return child[0] == nullptr;
}

bool BTree4th::Node::isBinary()
{
    return child[2] == nullptr;
}

int BTree4th::Node::size()
{
    int size = 0;
    if (key[0] != nullptr)
        size++;
    if (key[1] != nullptr)
        size++;
    if (key[2] != nullptr)
        size++;
    return size;
}

BTree4th::Node::~Node()
{
    if(key[0] != nullptr)
        delete key[0];
    if(key[1] != nullptr)
        delete key[1];
    if(key[2] != nullptr)
        delete key[2];

    if(child[0] != nullptr)
        delete child[0];
    if(child[1] != nullptr)
        delete child[1];
    if(child[2] != nullptr)
        delete child[2];
    if(child[3] != nullptr)
        delete child[3];

}

void BTree4th::Node::repair(bool recursive)
{
    for(int i = 0; i < 3; i++)
    {
        if(child[i] == nullptr) break;
        child[i]->parent = this;
        if(recursive)
            child[i]->repair(recursive);
    }

}
