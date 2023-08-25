#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <cmath>
#include <mutex>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>
#include <script.hpp>
/**
 * @brief AVL class.
 *
 * Drawable AVL tree.
 */
class AVL 
{
    private:
        /**
         * @brief Node class.
         *
         * Node of AVL tree.
         */
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
        SDL_Color nodeColor;
        SDL_Color fontColor;
        SDL_Color bgColor;


        int shiftX;
        int shiftY;
        int distanceX;
        int distanceY;

        bool isAnimate;
        std::mutex animate_mutex;

        bool pause;
        std::mutex pause_mutex;
        std::condition_variable queue_cv;

        int stepWait;
        Node* cache;
        
        std::mutex& ds_mutex;

        std::map<DATA_STRUCTURES_OPERATOR, Script*> scripts;
        Script* currentScript;
        TTF_Font* scriptFont;

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
        void highlight(std::vector<int> l);
        void unhighlight(std::vector<int> l);
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

        void closeScript();

        bool isReceiveEvent(SDL_Event& e);
        Button* react(SDL_Event& e);
        void rendering();

        void setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4);
};
#endif
