#include <data_structures/graph.hpp>
#include <services.hpp>

double sqr(double x)
{
    return x * x;
}

bool Graph::isCollisionToNode(Node* node, int x, int y)
{
    SDL_Point p;
    p.x = node->sprite->getX() + node->sprite->getW() / 2;
    p.y = node->sprite->getY() + node->sprite->getH() / 2;

    return sqr(p.x - x) + sqr(p.y - y) + 50 <= sqr(node->sprite->getW());
}

bool Graph::isCollisionToEdge(Edge* e, int x, int y)
{
    const SDL_Rect* srcloc = (e->u->sprite->getLocation());
    const SDL_Rect* dstloc = (e->v->sprite->getLocation());

    SDL_Point src;
    src.x = srcloc->x + srcloc->w/2;
    src.y = srcloc->y + srcloc->h/2;


    SDL_Point dst;
    dst.x = dstloc->x + dstloc->w/2;
    dst.y = dstloc->y + dstloc->h/2;

    SDL_Point p;
    p.x = x;
    p.y = y;

    src.x -= p.x;
    src.y -= p.y;

    dst.x -= p.x;
    dst.y -= p.y;

    return sqr(src.x + dst.x) + sqr(src.y + dst.y) <= 1000;
}

bool Graph::isCollision(int x, int y)
{
    for(auto i : nodes)
        if(isCollisionToNode(i, x, y))
            return true;
    for(auto i : edges)
        if(isCollisionToEdge(i, x, y))
            return true;
    return false;
}

void Graph::init(std::vector<std::vector<int> > g)
{
    capacity = g.size();

    for(auto i : nodes)
        delete i;
    for(auto i : edges)
        delete i;
    nodes.clear();
    edges.clear();

    for(int i = 0; i < capacity; i++)
    {
        int x = 10;
        int y = 10;
        int rep = 20;
        do 
        {
            x = RANDOM::getInt(10, 720);
            y = RANDOM::getInt(10, 520);
            rep--;
        }while(rep != 0 && isCollision(x, y));
        Sprite* spr = new Sprite(render);
        spr->setFont(font);
        spr->linking("AVL/node");
        spr->locatingX(x);
        spr->locatingY(y);
        spr->setText(NUMBER::intToString(i));
        spr->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);

        Node* node = new Node(i, spr);

        nodes.push_back(node);
    }

    for(int i = 0; i < capacity; i++)
    {
        for(int j = 0; j < capacity && j < g[i].size(); j++)
        {
            if(g[i][j] != 0)
            {
                Sprite* spr = new Sprite(render);
                spr->setFont(font);
                spr->linking("graph/weight");

                spr->locatingX((nodes[i]->sprite->getX() + nodes[j]->sprite->getX()) / 2);
                spr->locatingY((nodes[i]->sprite->getY() + nodes[j]->sprite->getY()) / 2);

                spr->setText(NUMBER::intToString(g[i][j]));
                spr->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
                Edge* edge = new Edge(nodes[i], nodes[j], g[i][j], spr);
                edges.push_back(edge);
                nodes[i]->addEdge(edge);
            }
        }
    }
}
