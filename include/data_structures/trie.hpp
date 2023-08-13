#ifndef TRIE_HPP
#define TRIE_HPP
#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>

struct Node;

class Trie 
{
private:
    Node* root;        
    int capacity;
    int size;
    int numberOfWords;

    SDL_Rect viewport;
    SDL_Renderer *render;
    TTF_Font *font;
    SDL_Point lastMousePressed;
    bool isMoving;
    SDL_Color edgesColor;
    
    int shiftX;
    int shiftY;
    int distanceX;
    int distanceY;

protected:
    Node* insert(Node* node, std::string word, int index);
    bool search(Node* node, std::string word, int index);
    bool remove(Node* node, std::string word, int index);
    int locating(Node* node, int shiftDown, int shiftRight);
public:
    Trie(SDL_Renderer * r, TTF_Font* f, SDL_Rect v, int capacity);
    ~Trie();

    void init(std::vector<std::string> words);
    bool insert(std::string word);
    bool search(std::string word);
    bool remove(std::string word);

    void setEdgesColor(SDL_Color c);
    void setNodeColor(SDL_Color bg, SDL_Color fg);
};

#endif 
