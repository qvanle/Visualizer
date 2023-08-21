#include <data_structures/btree4th.hpp>

void BTree4th::insert(int key)
{
    if(root == nullptr)
    {
        root = new Node(nullptr, key);
        return ;
    }

    if(root->isLeaf() && !root->isFull())
    {
        root = addRecordToLeaf(root, key);
        return ;
    }

    if(root->isFull()) root = split(root);
    
    Node* current = root;

    do 
    {
        int pnext = 3;
        for(int i = 0; i < 3; i++)
        {
            if(current->key[i] == nullptr) 
            {
                pnext = i;
                break;
            }
            if(key < *(current->key[i]))
            {
                pnext = i;
                break;
            }
        }
        Node *& nxt = current->child[pnext];
        if(nxt->isLeaf() && !nxt->isFull())
        {
            nxt = addRecordToLeaf(nxt, key);
            break;
        }
        if(nxt->isFull()) 
        {
            nxt = split(nxt);
            mergeChild(current, pnext);
        }

    }while(true);
}
