#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <iostream>
#include <vector>
#include <string> 
#include <mutex>
#include <thread>
#include <condition_variable>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>
#include <button.hpp>
#include <script.hpp>

/**
 * @brief heap class.
 *
 * Drawable heap.
 *
 * Default is min heap.
 */

class minHeap 
{
    private:
        /**
         * @brief Node class.
         *
         * Node of heap.
         */
        struct Node 
        {
            int value;
            Sprite* sprite;
            Node(int value, Sprite* spr);
            ~Node();
            void repair();
        };

        std::vector<Node*> value;
        bool inverse;

        int capacity;

        SDL_Point lastMousePressed;
        SDL_Rect viewport;
        SDL_Renderer* render;
        TTF_Font* font;
        bool isMoving;
        SDL_Color bgColor;
        SDL_Color nodeColor;
        SDL_Color fontColor;
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

        std::map<DATA_STRUCTURES_OPERATOR, Script*> scripts;
        Script* currentScript;
        TTF_Font* scriptFont;

    protected:
        void heapify(int index);
        void swap(int index1, int index2);
        bool swapable(int index1, int index2);
        void realInsert(int value);

        int locating(int id, int shiftDown, int shiftRight);
        void renderLine(Node* src, Node* dst);

        void waitForStep();
        void highlight(std::vector<int> l);
        void unhighlight(std::vector<int> l);
    public: 
        minHeap(SDL_Renderer* render, std::mutex& m, TTF_Font* f, SDL_Rect v, int cap);
        ~minHeap();
        void setmax();
        void setmin();
        void init(std::vector<int> value);
        void insert(int value);
        void pop();
        int top();
        int size();

        void closeScript();

        bool isReceiveEvent(SDL_Event& e);
        Button* react(SDL_Event& e);
        void rendering();
        void setting(SDL_Color c1, SDL_Color c2, SDL_Color c3, SDL_Color c4);
};

#endif 

