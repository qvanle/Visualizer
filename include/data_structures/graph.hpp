#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <stack>

class Graph 
{
private: 
    struct Edges 
    {
        bool isWeighted;
        
        int flag;
        
        int weight;
        int u;
        int v;
        Edges(int s, int d);
        Edges(int s, int d, int w);
        ~Edges();
    };
    
    struct heap 
    {
        std::vector<int> values;
        void insert(int u);
        int pop();
        void heapify(int i);
    };


    using EdgesList = std::vector<Edges>;

    int numberOfVertices;
    int numberOfEdges;
    std::vector <EdgesList> adjList;
    EdgesList edges;

    std::vector<int> distance;
    std::vector<int> order, lowestOrder;
    std::vector< std::vector<int> > components;

    std::vector<int> present;
protected:
    void dfs(std::vector<EdgesList> &list, std::stack<int> &st, int u);
    void MST(EdgesList &list);
    void Dijkstra(std::vector<EdgesList> &list, int start);
public:
    Graph();
    ~Graph();
    void init(std::vector< std::vector<int> > matrix);
    void splitConnected();
    void FindMiniMumSpanningTree();
    void Dijkstra(int start);
};

#endif
