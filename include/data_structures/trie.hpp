#ifndef TRIE_HPP
#define TRIE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <script.hpp>

#include <sprite.hpp>


/**
 * @brief Trie data structure
 * 
 */
class Trie 
{
private:
    /**
     * @brief Node of Trie
     * 
     */
    struct Node 
    {
        char key;
        Sprite* sprite;
        Node* childs[26];
        int endOfWords;
        int numberOfWords;
        Node(int k, Sprite* spr);
        ~Node();
        void repair();
    };
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
    SDL_Color nodeColor;
    SDL_Color fontColor;
    SDL_Color bgColor;
    
    int shiftX;
    int shiftY;
    int distanceX;
    int distanceY;

    bool isAnimate;
    std::mutex animate_mutex;
    int stepWait;
    bool pause;
    std::mutex pause_mutex;
    std::condition_variable queue_cv;

    std::map<DATA_STRUCTURES_OPERATOR, Script*> scripts;
    Script* currentScript;
    TTF_Font* scriptFont;

    std::mutex step_mutex;

    std::mutex &ds_mutex;
protected:
    Node* insert(Node* node, std::string word, int index);
    bool search(Node* node, std::string word, int index);
    Node* remove(Node* node, std::string word, int index);
    int locating(Node* node, int shiftDown, int shiftRight);
    
    void drawEgdes(Node* u, Node* v);

    void waitForStep();
    void highlight(std::vector<int> l);
    void unhighlight(std::vector<int> l);

public:
    Trie(SDL_Renderer * r, std::mutex& m, TTF_Font* f, SDL_Rect v, int capacity);
    ~Trie();

    void init(std::vector<std::string> words);
    bool insert(std::string word);
    bool search(std::string word);
    bool remove(std::string word);

    void setEdgesColor(SDL_Color c);
    void setNodeColor(SDL_Color bg, SDL_Color fg);

    void rendering();

    bool isReceiveEvent(SDL_Event& e);
    Button* react(SDL_Event& e);
    void closeScript();
    void setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4);

    void goOff();
    void goOn();
    void speedUp();
    void slowDown();
    void goNext();
    void goBack();
};

#endif 
