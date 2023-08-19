#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP
#include <iostream>
#include <vector>
#include <string> 

class maxHeap 
{
private:
    struct Node 
    {
        int value;
        Node(int value);
        ~Node();
    };

    std::vector<Node*> value;
protected:
    void heapify(int index);
    void swap(int index1, int index2);
    bool swapable(int index1, int index2);
public: 
    maxHeap();
    ~maxHeap();
    void init(std::vector<int>& value);
    void insert(int value);
    void pop();
    int top();
    int size();
};

#endif 
