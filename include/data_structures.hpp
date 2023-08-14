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
#include <data_structures/trie.hpp>

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
    Trie* trie;

protected:
    void initBackground(const json& mem);
    void initLinker(const json& mem);
    void initDisplay(const json& mem);
    void importFromJson();

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
