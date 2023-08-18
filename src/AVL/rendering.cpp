#include <data_structures/AVL.hpp>
#include <queue>

void AVL::renderLine(Node* src, Node* dst)
{
    SDL_Point psrc = {src->sprite->getX() + src->sprite->getW() / 2, src->sprite->getY() + src->sprite->getH() / 2};
    SDL_Point pdst = {dst->sprite->getX() + dst->sprite->getW() / 2, dst->sprite->getY() + dst->sprite->getH() / 2};
    
    SDL_SetRenderDrawColor(render, edgesColor.r, edgesColor.g, edgesColor.b, edgesColor.a);
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
            SDL_RenderDrawLine(render, psrc.x + i, psrc.y + j, pdst.x + i, pdst.y + j);
    }
}

void AVL::rendering()
{
    if(root == nullptr) return ;
    SDL_RenderSetViewport(render, &viewport);
    
    std::lock_guard< std::mutex > lock(animate_mutex);

    locating(root, 0, 0);

    std::queue< Node* > q;
    q.push(root);

    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();
        if(u->lson != nullptr)
        {
            renderLine(u, u->lson);
            q.push(u->lson);
        }
        if(u->rson != nullptr)
        {
            renderLine(u, u->rson);
            q.push(u->rson);
        }
        u->sprite->rendering();
    }
    if(cache != nullptr) 
    {
        //cache->sprite->rendering();
    }
}
