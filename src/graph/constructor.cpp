#include <data_structures/graph.hpp>

Graph::Node::Node(int value, Sprite* spr)
{
    value = value;
    sprite = spr;
}
void Graph::Node::addEdge(Edge* e)
{
    edges.push_back(e);
}

Graph::Edge::Edge(Node* u, Node* v)
{
    u = u;
    v = v;
    weight = 1;
    isWeight = false;
    mark = 0;
}

Graph::Edge::Edge(Node* u, Node* v, int weight)
{
    u = u;
    v = v;
    weight = weight;
    isWeight = true;
    mark = 0;
}

Graph::Graph(SDL_Renderer* r, TTF_Font* f, SDL_Rect v, int capacity)
{
    render = r;
    font = f;
    viewport = v;
    capacity = capacity;
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftY = 20;

    isMoving = false;
    choosedNode = nullptr;
    lastMousePressed = {0, 0};


}
