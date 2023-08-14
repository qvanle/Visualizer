#include <data_structures/trie.hpp>

Trie::Node::Node(int k, Sprite* spr)
{
    key = k;
    sprite = spr;
    endOfWords = 0;
    numberOfWords = 0;
    for(int i = 0; i < 26; i++)
        childs[i] = nullptr;
};

Trie::Trie(SDL_Renderer* r, TTF_Font* f, SDL_Rect v, int cap)
{
    render = r;
    font = f;
    viewport = v;
    capacity = cap;
    size = 0;
    root = nullptr;
    edgesColor = {255, 255, 255, 255};
    shiftX = 20;
    shiftX = 20;
    distanceX = 60;
    distanceY = 80;
    isMoving = false;
}

int Trie::locating(Node* node, int shiftDown, int shiftRight)
{
    if(node == nullptr) return 0;

    int j = 0;
    for(int i = 0; i < 26; i++) 
        if(node->childs[i] != nullptr) j++;
    j /= 2;

    int i = 0;

    for(; j > 0; i++)
    {
        if(node->childs[i] == nullptr)
            continue;
        j--;

        shiftRight = locating(node->childs[i], shiftDown + 1, shiftRight);
    }

    node->sprite->locatingX(shiftX + shiftRight * distanceX);
    node->sprite->locatingY(shiftY + shiftDown * distanceY);
    node->sprite->aligning(HORIZONTAL_ALIGN::CENTER, VERTICAL_ALIGN::CENTER);
    shiftRight++;

    for(; i < 26; i++)
    {
        if(node->childs[i] == nullptr)
            continue;
        shiftRight = locating(node->childs[i], shiftDown + 1, shiftRight);
    }

    return shiftRight;
}