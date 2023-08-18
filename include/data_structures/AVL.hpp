#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <cmath>
#include <mutex>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>

class AVL 
{
    private:
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

        bool isAnimate;
        std::mutex animate_mutex;
        bool isQueue;
        bool isPause;
        std::mutex pause_mutex;
        int stepWait;
        std::condition_variable step_cv;
        std::mutex step_mutex;
        Node* cache;
        
        std::mutex& ds_mutex;
    protected:
        Node* rotateLeft(Node * node);
        Node* rotateRight(Node * node);

        int getHigh(Node* node);
        int balanceFactor(Node* node);
        Node* balancing(Node* node);

        int maxDepth(Node* node);

        Node* insert(Node* node, Node* newNode);
        Node* unplugSmallest(Node* Node, struct Node*& n2); 
        Node* remove(Node* node, int key);
        void search(Node* node, int key);

        int locating(Node* node, int shiftDown, int shiftRight);
        void renderLine(Node* src, Node* dst);

        void waitForStep();
    public:
        AVL(SDL_Renderer* render, std::mutex& m, TTF_Font* f, SDL_Rect v, int cap);
        ~AVL();

        void init(std::vector< int > v);
        bool insert(int key);
        bool remove(int key);
        bool search(int key);
        int maxDepth();

        void setEdgesColor(SDL_Color c);
        void setNodeColor(SDL_Color bg, SDL_Color fg);

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
