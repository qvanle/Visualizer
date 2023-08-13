#include <data_structures/trie.hpp>

struct Node
{
    char key;
    Sprite* sprite;
    bool isEndOfWord;
    int numberOfWords;
    Node *children[26];
    
    Node(char key, Sprite* sprite);
    ~Node();
};

Node::Node(char key, Sprite* sprite)
{
    this->key = key;
    this->sprite = sprite;
    this->isEndOfWord = false;
    this->numberOfWords = 0;
    for (int i = 0; i < 26; i++)
        this->children[i] = nullptr;
}

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
    distanceX = 40;
    distanceY = 100;
    isMoving = false;

}

int Trie::locating(Node* node, int shiftDown, int shiftRight)
{
    if(node == nullptr) return 0;
    int children = 0;
    for(int i = 0; i < 26; i++)
        if(node->children[i] != nullptr)
            children++;

    int i = 0;
    int j = children / 2;
    for(; i < 26 && 0 < j; i++)
    {
        if(node->children[i] == nullptr) continue;
        j--;
        shiftRight += locating(node->children[i], shiftDown + 1, shiftRight);
    }

    node->sprite->locatingX(shiftX + shiftRight * distanceX);
    node->sprite->locatingY(shiftY + shiftDown * distanceY);
    shiftRight++;

    for(; i < 26; i++)
    {
        if(node->children[i] == nullptr) continue;
        shiftRight += locating(node->children[i], shiftDown + 1, shiftRight);
    }
    return shiftRight;
}
