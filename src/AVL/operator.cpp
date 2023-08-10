#include <data_structures/AVL.hpp>
#include <services.hpp>

Node* AVL::insert(Node* node, Node* newNode)
{
    if(node == nullptr) 
    {
        sizeOfTree++;
        return newNode;
    }

    if(compare(newNode, node) == -1)
    {
        node->lson = insert(node->lson, newNode);
    }
    else if(compare(newNode, node) == 1)
    {
        node->rson = insert(node->rson, newNode);
    }
    node = balancing(node);
    return node;
}



void AVL::init(std::vector<int> values)
{
    if(root != nullptr)
        delete root;
    root = nullptr;
    for(int i = 0; i < values.size() && sizeOfTree < capacity; i++)
    {
        insert(values[i]);
    }
    maxHigh = maxDepth(root);
    locating(root, 0, 0);
}

bool AVL::insert(int key)
{
    if(sizeOfTree == capacity)
    {
        return false;
    }


    Sprite* sprite = new Sprite(render);
    sprite->setFont(font);
    sprite->linking("AVL/node");
    sprite->setText(NUMBER::intToString(key));

    Node* node = new Node(key, sprite);
    root = insert(root, node);
    
    int step = 0;
    Node* current;

    return true;
}
