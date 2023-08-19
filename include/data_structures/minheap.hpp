#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <iostream>
#include <vector>
#include <string> 

class minHeap 
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
    minHeap();
    ~minHeap();
    void init(std::vector<int>& value);
    void insert(int value);
    void pop();
    int top();
    int size();
};

#endif 

