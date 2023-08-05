#ifndef SPRITE
#define SPRITE

#include <vector>

#include <SDL2/SDL.h>

#include <nlohmann/json.hpp>

#include <object.hpp>

using json = nlohmann::json;

class Sprite : public Object 
{
private: 
    
    std::string name;

    std::vector<Object*> objects;
    Object* textBox;

    SDL_Renderer* render;
protected:
    
    void initBackground(const json &mem);
    void initObjects(const json &mem);
    void importFromJson();
public:
    Sprite(SDL_Renderer* r);
    ~Sprite();
    
    void linking(std::string n);

    void setTextBox(TTF_Font* f);
    void setText(std::string s);
    void typing(char c);
    void typing(std::string s);
    void backspace();
    void backspace(int n);

    void locating(int x, int y, int w, int h) override;
    void locating(SDL_Rect r) override;
    void locatingX(int x) override;
    void locatingY(int y) override;
    void moveX(int x) override;
    void moveY(int y) override;

    void rendering() override;
};

#endif 
