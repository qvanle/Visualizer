#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sprite.hpp>
#include <type_traits>

class HashTable
{
    private:
        struct Node 
        {
            Sprite* sprite;
            int key;
            Node* pnext; 
            Node(int k, Sprite* spr);
            ~Node();
            void repair();
        };
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

        int shiftX;
        int shiftY;
        int distanceX;
        int distanceY;

        bool isQueue;
        bool isPause;
    protected:
        Node* insert(Node* root, int k);
        Node* remove(Node* root, int k);
        bool search(Node* root, int k);
        int locating(Node* node, int shiftDown, int shiftRigh);
        int locating(Head** table, int shiftDown, int shiftRight);
        void renderEdges(Node* src, Node* dst);
        void defaultSetting();

        void drawEdge(Node* src, Node* dst);
    public: 
        HashTable(SDL_Renderer* render, TTF_Font* font, SDL_Rect v, int cap);
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
        void react(SDL_Event& e);
        void rendering();
};

#endif 
