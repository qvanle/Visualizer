#include <data_structures/graph.hpp>

struct Point 
{
    double x, y;
};

void Graph::renderEdge(Edge* e)
{
    if(nodirect && e->u->value > e->v->value)
        return ;
    if(e->mark == 3)
        SDL_SetRenderDrawColor(render, 50, 50, 50, 255);
    else if(e->mark == 2)
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    else if(e->mark == 1)
        SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
    else 
        SDL_SetRenderDrawColor(render, edgesColor.r, edgesColor.g, edgesColor.b, edgesColor.a);
    const SDL_Rect* srcloc = (e->u->sprite->getLocation());
    const SDL_Rect* dstloc = (e->v->sprite->getLocation());

    SDL_Point src;
    src.x = srcloc->x + srcloc->w/2;
    src.y = srcloc->y + srcloc->h/2;


    SDL_Point dst;
    dst.x = dstloc->x + dstloc->w/2;
    dst.y = dstloc->y + dstloc->h/2;

    int sign = 1;
    if(dst.x < src.x)
        sign = -1;
    e->sprite->locatingX((src.x + dst.x) / 2 + sign * 10);

    sign = 1;
    if(dst.y < src.y)
        sign = -1;
    e->sprite->locatingY((src.y + dst.y) / 2 + sign * 10);

    for (int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            SDL_RenderDrawLine(render, src.x + i, src.y + j, dst.x + i, dst.y + j);
        }
    }
    if(nodirect) return ;
    Point v;
    v.x = dst.x - src.x;
    v.y = dst.y - src.y;
    double len = sqrt(v.x * v.x + v.y * v.y);
    v.x /= len;
    v.y /= len;

    
    Point u = {v.y, -v.x};

    SDL_Point p1;
    p1.x = dst.x - v.x * 40 + u.x * 10;
    p1.y = dst.y - v.y * 40 + u.y * 10;

    SDL_Point p2;
    p2.x = dst.x - v.x * 40 - u.x * 10;
    p2.y = dst.y - v.y * 40 - u.y * 10;
    
    SDL_Point p3;
    p3.x = dst.x - v.x * 28;
    p3.y = dst.y - v.y * 28;

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
        {
            SDL_RenderDrawLine(render, p1.x + i, p1.y + j, p3.x + i, p3.y + j);
            SDL_RenderDrawLine(render, p2.x + i, p2.y + j, p3.x + i, p3.y + j);
        }
}

void Graph::rendering()
{
    std::lock_guard<std::mutex> lock(animate_mutex);
    for(auto i : edges)
    {
        renderEdge(i);
        if(i->sprite != nullptr) i->sprite->rendering();
    }
    for(auto i : nodes)
    {
        i->sprite->rendering();
    }

    if(currentScript != nullptr)
    {
        currentScript->rendering();
    }
}
