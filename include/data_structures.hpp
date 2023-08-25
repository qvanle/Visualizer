#ifndef DATA_STRUCTURES_HPP
#define DATA_STRUCTURES_HPP

#include <iostream>
#include <vector>
#include <string> 
#include <mutex>

#include <SDL2/SDL.h>

#include <GLOBAL.hpp>

#include <object.hpp>
#include <sprite.hpp>
#include <services.hpp>
#include <display.hpp>
#include <inputbox.hpp>

#include <data_structures/AVL.hpp>
#include <data_structures/trie.hpp>
#include <data_structures/hash_table.hpp>
#include <data_structures/minheap.hpp>
#include <data_structures/maxheap.hpp>
#include <data_structures/graph.hpp>
/**
 * @brief Container that contains all data structures.
 *
 * Drawable
 *
 * contain AVL 
 *
 * contain Trie 
 *
 * contain Hash Table 
 *
 * contain Graph 
 *
 * contain Heap
 */
class DataStructures : protected Object
{
private:
    std::mutex& ds_mutex;
    SDL_Renderer* render;
    std::string name;
    std::vector<Sprite*> node;
    std::string spriteLinker;
    DATA_STRUCTURES_TYPE type;
    std::vector<Display*> displays;
    TTF_Font* font;

    AVL* avl;
    Trie* trie;
    HashTable* hashTable;
    minHeap* minheap;
    maxHeap* maxheap;
    Graph* graph;

protected:
    void initBackground(const json& mem);
    void initLinker(const json& mem);
    void initDisplay(const json& mem);
    void importFromJson();
    
    void initAVL(InputBox* inp);
    void insertAVL(InputBox* inp);
    void removeAVL(InputBox* inp);
    void searchAVL(InputBox* inp);
    void settingAVL(InputBox* inp);

    void initTrie(InputBox* inp);
    void insertTrie(InputBox* inp);
    void removeTrie(InputBox* inp);
    void searchTrie(InputBox* inp);
    void settingTrie(InputBox* inp);

    void initHashTable(InputBox* inp);
    void insertHashTable(InputBox* inp);
    void removeHashTable(InputBox* inp);
    void searchHashTable(InputBox* inp);
    void settingHashTable(InputBox* inp);

    void initMinHeap(InputBox* inp);
    void insertMinHeap(InputBox* inp);
    void removeMinHeap(InputBox* inp);
    void searchMinHeap(InputBox* inp);
    void settingMinHeap(InputBox* inp);

    void initGraph(InputBox* inp);
    void Dijkstra(InputBox* inp);
    void MST();
    void SCC();
    void settingGraph(InputBox* inp);

public:
    DataStructures(SDL_Renderer* r, TTF_Font* f, std::mutex& m);
    ~DataStructures();

    void linking(std::string n);
    void setDataType(DATA_STRUCTURES_TYPE t);
    DATA_STRUCTURES_TYPE getDataType();

    std::string getName();

    void rendering();

    void init(InputBox* inp);
    void insert(InputBox* inp);
    void remove(InputBox* inp);
    void search(InputBox* inp);
    void setting(InputBox* inp);
    void top();
    void size();
    void scc();
    void mst();
    void dijkstra(InputBox* inp);
    
    void goBack();
    void goNext();
    void goOn();
    void goOff();
    void speedUp();
    void slowDown();

    void closeScript();

    bool isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);

    int capacity;
};


#endif 
