#include <data_structures/hash_table.hpp>

void HashTable::drawEdge(Node* src, Node* dst)
{
    SDL_Rect srcRect = *src->sprite->getLocation();
    SDL_Rect dstRect = *dst->sprite->getLocation();

    SDL_SetRenderDrawColor(render, edgesColor.r, edgesColor.g, edgesColor.b, edgesColor.a);
    for(int j = -1; j <= 1; j++)
    {
        SDL_RenderDrawLine(render,srcRect.x + srcRect.w, srcRect.y + srcRect.h / 2 + j, dstRect.x, dstRect.y + dstRect.h / 2 + j);
    }
    
    for(int j =  -3; j <= 3; j++)
    {
        SDL_RenderDrawLine(render, dstRect.x - 8, dstRect.y - 5 + j + dstRect.h / 2, dstRect.x, dstRect.y + dstRect.h / 2);
        SDL_RenderDrawLine(render, dstRect.x - 8, dstRect.y + 5 + j + dstRect.h / 2, dstRect.x, dstRect.y + dstRect.h / 2);
        SDL_RenderDrawLine(render, dstRect.x - 8, dstRect.y - 5 + j + dstRect.h / 2, dstRect.x - 8, dstRect.y + 5 + j + dstRect.h / 2);
    }
}

void HashTable::rendering()
{
    if(table == nullptr) return ;
    SDL_RenderSetViewport(render, &viewport);

    for(int i = 0; i < HASH_KEY; i++)
    {
        if(table[i]->root == nullptr)
            table[i]->sprite->rendering();
        else 
        {
            Node* current = table[i]->root;
            while(current != nullptr) 
            {
                if(current->pnext != nullptr) drawEdge(current, current->pnext);
                current->sprite->rendering();
                current = current->pnext;
            }
        }
    }
}
