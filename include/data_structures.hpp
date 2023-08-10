#ifndef DATA_STRUCTURES_HPP
#define DATA_STRUCTURES_HPP

#include <iostream>
#include <vector>
#include <string> 

#include <SDL2/SDL.h>

#include <GLOBAL.hpp>

#include <object.hpp>
#include <sprite.hpp>
#include <services.hpp>
#include <display.hpp>

#include <data_structures/AVL.hpp>

class DataStructures : protected Object
{
private:
    SDL_Renderer* render;
    std::string name;
    std::vector<Sprite*> node;
    std::string spriteLinker;
    DATA_STRUCTURES_TYPE type;
    std::vector<Display*> displays;
    TTF_Font* font;
    AVL* avl;

protected:
    void initBackground(const json& mem);
    void initLinker(const json& mem);
    void initDisplay(const json& mem);
    void importFromJson();

    void hashTableInit(std::vector<std::string> v);
    void hashTableInsert(std::string v);
    void hashTableRemove(std::string v);
    void hashTableSearch(std::string v);
    
    void graphInit(std::vector<std::string> v);
    void graphConnectedComponents();
    void graphFindMinimumSpanningTree();
    void graphDijkstra(int u, int v);

    void trieInit(std::vector<std::string> v);
    void trieInsert(std::string v);
    void trieRemove(std::string v);
    void trieSearch(std::string v);

    void AVLInit(std::vector<std::string> v);
    void AVLInsert(std::string v);
    void AVLRemove(std::string v);
    void AVLSearch(std::string v);

    void BTree4thInit(std::vector<std::string> v);
    void BTree4thInsert(std::string v);
    void BTree4thRemove(std::string v);
    void BTree4thSearch(std::string v);

    void heapInit(std::vector<std::string> v, bool isFindMax);
    void heapInsert(std::string v);
    void heapRemove(std::string v);
    void heapGetMax();
    void heapGetMin();
    void heapGetSize();
public:
    DataStructures(SDL_Renderer* r, TTF_Font* f);
    ~DataStructures();

    void linking(std::string n);
    void setDataType(DATA_STRUCTURES_TYPE t);
    DATA_STRUCTURES_TYPE getDataType();

    std::string getName();

    void rendering();

    void init(std::vector<std::string> v);
    void init(std::vector<int> v);
    void initFromFile(std::string f);
    void insert(std::string v);
    void remove(std::string v);
    void search(std::string v);

    bool isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);
};

#endif 
