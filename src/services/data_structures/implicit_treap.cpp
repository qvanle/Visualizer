#include <services.hpp>

template<typename T> 
IMPLICIT_TREAP::Node<T>::Node(T data) 
{
    NodeData = data;
    priority = RANDOM::getLongLong(0, LLONG_MAX);
    treeSize = 1;
    lson = nullptr;
    rson = nullptr;
}
template<typename T>
IMPLICIT_TREAP::Node<T>::~Node() 
{
    if(lson != nullptr) delete lson;
    if(rson != nullptr) delete rson;
}

template<typename T>
void IMPLICIT_TREAP::Node<T>::updating() 
{
    treeSize = 1 + size(lson) + size(rson);
}

template<typename T>
void IMPLICIT_TREAP::Node<T>::lazyPushDown() 
{
    updating();
}

template<typename T>
T IMPLICIT_TREAP::Node<T>::getData() 
{
    return NodeData;
}


template<typename T>
int size(IMPLICIT_TREAP::Node<T>* node) {
    return node == nullptr ? 0 : node->treeSize;
}

template<typename T>
IMPLICIT_TREAP::Node<T>* merge(IMPLICIT_TREAP::Node<T>* l, IMPLICIT_TREAP::Node<T>* r) 
{
    if(l == nullptr) return r;
    if(r == nullptr) return l;

    if(l->priority < r->priority) 
    {
        l->lazyPushDown();
        l->rson = merge(l->rson, r);
        l->updating();
        return l;
    }
    else 
    {
        r->lazyPushDown();
        r->lson = merge(l, r->lson);
        r->updating();
        return r;
    }
}

template<typename T>
void split(IMPLICIT_TREAP::Node<T>* node, IMPLICIT_TREAP::Node<T>*& l, IMPLICIT_TREAP::Node<T>*& r, int key) 
{
    if(node == nullptr) 
    {
        l = nullptr;
        r = nullptr;
        return;
    }
    if(key == 0) 
    {
        l = nullptr;
        r = node;
        return ;
    }
    if(size(node) == key)
    {
        l = node;
        r = nullptr;
        return ;
    }

    node->lazyPushDown();

    if(size(node->lson) <= key) 
    {
        split(node->rson, l, r, key - size(node->lson) - 1);
        node->rson = l;
        node->updating();
        l = node;
    }
    else 
    {
        split(node->lson, l, r, key);
        node->lson = r;
        node->updating();
        r = node;
    }
}
