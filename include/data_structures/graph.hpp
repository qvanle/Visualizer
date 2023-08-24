#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>
#include <button.hpp>

class Graph 
{
    private:
        struct Edge;
        struct Node 
        {
            int value;
            Sprite* sprite;
            std::vector<Edge*> edges;
            Node(int value, Sprite* spr);
            ~Node();
            void addEdge(Edge* e);
        };
        struct Edge
        {
            Node* u;
            Node* v;
            int weight;
            bool isWeight;
            int mark;
            Edge(Node* u, Node* v);
            Edge(Node* u, Node* v, int weight);
            ~Edge();
        };

        std::vector<Node*> nodes;
        std::vector<Edge*> edges;
        int capacity;
        
        SDL_Rect viewport;
        SDL_Renderer* render;
        TTF_Font* font;

        SDL_Point lastMousePressed;
        Node* choosedNode;
        bool isMoving;
        int shiftX;
        int shiftY;

        SDL_Color edgesColor;
    
        friend struct distanceHeap;
        std::vector<int> distance;

        std::vector<int> low, order;
        std::vector< std::vector<Node*> > components;
        std::stack<Node*> buffer;
        int state;
        
        friend struct DSU;
        std::vector<Edge*> sortedEdges;
    protected:
        void unionEdges();
        void Tarjan(Node* u);
        void repair();
    public:

    Graph(SDL_Renderer * r, TTF_Font* f, SDL_Rect v, int capacity);
    ~Graph();

    void Dijkstra(int start, int end);
    void MST();
    void SCC();
    
    void isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);
    
    void rendering();
};

#endif
