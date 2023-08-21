#ifndef BTREE4TH_HPP
#define BTREE4TH_HPP

#include <vector>
#include <string>
#include <iostream>

class BTree4th 
{
private: 
    struct Node 
    {
        int* key[3];
        Node* child[4];
        Node* parent;
        Node(Node* p);
        Node(Node* p, int k);
        Node(Node* p, int k1, int k2);
        Node(Node* p, int k1, int k2, int k3);
        Node(Node* p, int k, Node* lson, Node* rson);
        Node(Node* p, int k1, int k2, Node* lson, Node* mson, Node* rson);
        Node(Node* p, int k1, int k2, int k3, Node* lson, Node* m1son, Node* m2son, Node* rson);

        bool containsKey(int k);
        int* findKey(int k);
        bool isFull();
        bool isLeaf();
        bool isBinary();
        int size();
        void repair(bool recursive);
        ~Node();
    };
    Node* root;
protected:
    Node* leftMost(Node* node);
    Node* rightMost(Node* node);
    Node* split(Node* node);
    Node* addRecordToLeaf(Node* node, int key);
    Node* mergeChild(Node* node, int index);
    Node* mergeChild(Node* node, Node* child);
    void insert(Node *& node, int key);
    bool search(Node* node, int key);
public: 
    BTree4th();
    ~BTree4th();
    void init(std::vector<int> keys);
    void insert(int key);
    void remove(int key);
    bool search(int key);
};

#endif
