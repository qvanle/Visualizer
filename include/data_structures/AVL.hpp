#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <cmath>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>

struct Node 
{
    int key;
    Sprite* sprite;
    Node* lson;
    Node* rson;
    int high;
    Node(int k, Sprite* spr);
    ~Node();
    void repair();
};

int compare(Node* a, Node* b);

using NodeList = std::vector<Node*>;

class AVL 
{
private:
    Node* root;

    int capacity;
    int sizeOfTree;
    int maxHigh;

    SDL_Point lastPos;
    SDL_Rect viewport;
    SDL_Renderer* render;
    TTF_Font* font;
    SDL_Point lastMousePressed;
    bool isMoving;
    SDL_Color edgesColor;

    int shiftX;
    int shiftY;
    int distanceX;
    int distanceY;

    bool animation;
protected:
    Node* rotateLeft(Node * node);
    Node* rotateRight(Node * node);
    
    int getHigh(Node* node);
    int balanceFactor(Node* node);
    Node* balancing(Node* node);

    int maxDepth(Node* node);

    Node* insert(Node* node, Node* newNode);
    int locating(Node* node, int shiftDown, int shiftRight);
    void renderLine(Node* src, Node* dst);
public:
    AVL(SDL_Renderer* render, TTF_Font* f, SDL_Rect v, int cap);
    ~AVL();

    void init(std::vector< int > v);
    bool insert(int key);
    bool remove(int key);
    bool search(int key);
    int maxDepth();

    void setEdgesColor(SDL_Color c);
    void setNodeColor(SDL_Color bg, SDL_Color fg);
    
    void animated();
    void noAnimated();
    void goOff();
    void goOn();
    void goNext();
    void goBack();
    void speedUp();
    void slowDown();
    
    bool isReceiveEvent(SDL_Event& e);
    void react(SDL_Event& e);
    void rendering();
};
#endif
