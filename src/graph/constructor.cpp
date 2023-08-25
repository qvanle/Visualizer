#include <data_structures/graph.hpp>

Graph::Node::Node(int value, Sprite* spr)
{
    this->value = value;
    this->sprite = spr;
    edges.clear();
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

Graph::Graph(SDL_Renderer* r, std::mutex& m, TTF_Font* f, SDL_Rect v, int capacity) : ds_mutex(m)
{
    render = r;
    font = f;
    viewport = v;
    capacity = capacity;
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftY = 20;

    nodirect = false;

    nodeColor = {20, 75, 185, 255};
    fontColor = {255, 255, 255, 255};

    stepWait = 600;

    isMoving = false;
    chosenNode = nullptr;
    lastMousePressed = {0, 0};

    std::string fontpath = PATH::ASSETS::FONTS_ + "nimbus-sans-l/regular.otf";
    scriptFont = TTF_OpenFont(fontpath.c_str(), 18);

    currentScript = nullptr;
    Script* dij = new Script(render, scriptFont);
    dij->linking("graph/dijkstra");
    Script* mst = new Script(render, scriptFont);
    mst->linking("graph/mst");

    script[DATA_STRUCTURES_OPERATOR::DIJKSTRA] = dij;
    script[DATA_STRUCTURES_OPERATOR::MST] = mst;
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
