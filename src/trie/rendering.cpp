#include <data_structures/trie.hpp>
#include <queue>

void Trie::drawEgdes(Node* u, Node* v)
{
    SDL_Point psrc = {u->sprite->getX() + u->sprite->getW() / 2, u->sprite->getY() + u->sprite->getH() / 2};
    SDL_Point pdst = {v->sprite->getX() + v->sprite->getW() / 2, v->sprite->getY() + v->sprite->getH() / 2};
    
    SDL_SetRenderDrawColor(render, edgesColor.r, edgesColor.g, edgesColor.b, edgesColor.a);
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
            SDL_RenderDrawLine(render, psrc.x + i, psrc.y + j, pdst.x + i, pdst.y + j);
    }
}

void Trie::rendering()
{
    if(root == nullptr) return ;
    SDL_RenderSetViewport(render, &viewport);
    locating(root, 0, 0);

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();
        
        for(int i = 0; i < 26; i++)
        {
            if(u->childs[i] != nullptr)
            {
                q.push(u->childs[i]);
                drawEgdes(u, u->childs[i]);
            }
        }
        u->sprite->rendering();
    }
    if(currentScript != nullptr)
    {
        SDL_RenderSetViewport(render, nullptr);
        currentScript->rendering();
    }
}
