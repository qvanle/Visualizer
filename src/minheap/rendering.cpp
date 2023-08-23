#include <data_structures/minheap.hpp>
#include <cmath>

int minHeap::locating(int id, int shiftDown, int shiftRight)
{
    if(id < 0 || id >= value.size())
    {
        int shift = log2(value.size()) - shiftDown + 1;
        return std::max(0, (1 << shift) - 1);
    }

    int left = std::max(0, locating(id * 2 + 1, shiftDown + 1, shiftRight));
    Node* node = value[id];
    if(node->sprite != nullptr)
    {
        node->sprite->locatingX(shiftX + shiftRight * distanceX + left * distanceX);
        node->sprite->locatingY(shiftY + shiftDown * distanceY);
        node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
    }
    int right = locating(id * 2 + 2, shiftDown + 1, shiftRight + left + 1);

    int shift = log2(value.size()) - shiftDown + 1;
    return left + right + 1;
}

void minHeap::renderLine(Node* src, Node* dst)
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

void minHeap::rendering()
{
    SDL_RenderSetViewport(render, &viewport);
    std::lock_guard<std::mutex> lock(animate_mutex);
    locating(0, 0, 0);

    for(int i = 1; i < value.size(); i++)
    {
        Node* node = value[i];
        if(node->sprite != nullptr)
        {
            Node* parent = value[(i - 1) / 2];
            renderLine(parent, node);
        }
    }
    for(auto& i : value)
    {
        if(i->sprite != nullptr)
            i->sprite->rendering();
    }
    if(currentScript != nullptr)
    {
        SDL_RenderSetViewport(render, nullptr);
        currentScript->rendering();
    }

}
