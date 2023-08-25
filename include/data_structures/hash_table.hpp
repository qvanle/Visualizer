#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include <thread>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>
#include <GLOBAL.hpp>
#include <script.hpp>

/**
 * @brief HashTable class.
 *
 * Drawable HashTable.
 */
class HashTable
{
    private:
        /**
         * @brief Node class.
         *
         * Node of HashTable.
         */
        struct Node 
        {
            Sprite* sprite;
            int key;
            Node* pnext; 
            Node(int k, Sprite* spr);
            ~Node();
            void repair();
        };

        /**
         * @brief Head class.
         *
         * Head of HashTable.
         */
        struct Head 
        {
            Node* root;
            Sprite* sprite;
            Head(Sprite* spr);
            ~Head();
        };
        int HASH_KEY; 

        Head** table;
        int capacity;
        int currentSize;

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

        bool isQueue;
        bool isPause;
        std::map<DATA_STRUCTURES_OPERATOR, Script*> scripts;
        Script* currentScript;
        TTF_Font* scriptFont;

        bool isAnimate;
        std::mutex animate_mutex;
        std::mutex pause_mutex;
        int stepWait;
        std::condition_variable step_cv;

        std::mutex step_mutex;
        std::mutex &ds_mutex;
    protected:
        Node* insert(Node* root, int k);
        Node* remove(Node* root, int k);
        bool search(Node* root, int k);
        int locating(Node* node, int shiftDown, int shiftRigh);
        int locating(Head** table, int shiftDown, int shiftRight);
        void renderEdges(Node* src, Node* dst);
        void defaultSetting();

        void drawEdge(Node* src, Node* dst);

        void waitForStep();
        void highlight(std::vector<int> l);
        void unhighlight(std::vector<int> l);

    public: 
        HashTable(SDL_Renderer* render, std::mutex& m, TTF_Font* font, SDL_Rect v, int cap);
        ~HashTable();

        void init(std::vector<int> v, int KEY);
        void insert(int key);
        void remove(int key);
        bool search(int key);

        void setEdgesColor(SDL_Color c);
        void setNodeColor(SDL_Color bg, SDL_Color fg);

        void goOff();
        void goOn();
        void goNext();
        void goBack();
        void speedUp();
        void slowDown();

        bool isReceiveEvent(SDL_Event& e);
        Button* react(SDL_Event& e);
        void closeScript();

        void rendering();

        void setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4);
};

#endif 
