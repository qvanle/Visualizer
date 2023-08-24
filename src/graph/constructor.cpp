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
    this->u = u;
    this->v = v;
    weight = 1;
    isWeight = false;
    mark = 0;
}

Graph::Edge::Edge(Node* u, Node* v, int weight, Sprite* spr)
{
    this->u = u;
    this->v = v;
    weight = weight;
    isWeight = true;
    sprite = spr;
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

    nodeColor = {20, 75, 185, 255};
    fontColor = {255, 255, 255, 255};


    isMoving = false;
    chosenNode = nullptr;
    lastMousePressed = {0, 0};


}

void Graph::setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4)
{
    bgColor = c1;
    nodeColor = c2;
    fontColor = c3;
    edgesColor = c4;
    for(auto i : nodes)
    {
        i->sprite->setFontColor(fontColor);
        i->sprite->coloring(nodeColor);
    }
}
