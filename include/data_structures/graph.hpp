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
            Sprite* sprite;
            int weight;
            bool isWeight;
            int mark;
            Edge(Node* u, Node* v);
            Edge(Node* u, Node* v, int weight, Sprite* spr);
            ~Edge();
        };
    
        bool isCollisionToNode(Node* node, int x, int y);
        bool isCollisionToEdge(Edge* edge, int x, int y);
        bool isCollision(int x, int y);

        std::vector<Node*> nodes;
        std::vector<Edge*> edges;
        int capacity;
        
        SDL_Rect viewport;
        SDL_Renderer* render;
        TTF_Font* font;

        SDL_Point lastMousePressed;
        Node* chosenNode;
        bool isMoving;
        int shiftX;
        int shiftY;

        SDL_Color edgesColor;
        SDL_Color nodeColor;
        SDL_Color fontColor;
        SDL_Color bgColor;
    
        friend struct distanceHeap;
        std::vector<int> distance;

        std::vector<int> low, order;
        std::vector< std::vector<Node*> > components;
        std::stack<Node*> buffer;
        int state;
        
        friend struct DSU;
        std::vector<Edge*> sortedEdges;

        std::mutex animate_mutex;
        std::mutex& ds_mutex;
        int stepWait;
        bool nodirect;
    protected:
        void unionEdges();
        void Tarjan(Node* u);
        void repair();
        void renderEdge(Edge* edge);
        void waitForStep();
    public:

    Graph(SDL_Renderer * r, std::mutex& m, TTF_Font* f, SDL_Rect v, int capacity);
    ~Graph();

    void Dijkstra(int start, int end);
    void MST();
    void SCC();
    void init(std::vector< std::vector<int> > value);
    
    bool isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);
    
    void rendering();
    void setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4);
};

#endif
