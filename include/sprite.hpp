#ifndef SPRITE
#define SPRITE

#include <vector>

#include <SDL2/SDL.h>

#include <nlohmann/json.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <object.hpp>

using json = nlohmann::json;

class Sprite : public Object 
{
private: 
    
    std::string name;
    TTF_Font* font;
    std::vector<Object*> objects;
    Object* textBox;

    HORIZONTAL_ALIGN alignH;
    VERTICAL_ALIGN alignV;

    bool receiveDigit;
    bool receiveLetter;
    bool receiveSymbol;
    std::string numberLower;
    std::string numberUpper;
    int maxSize;
    
    SDL_Color cacheColor;

    SDL_Renderer* render;
protected:
    
    void initBackground(const json &mem);
    void initObjects(const json &mem);
    void initTextBox(const json& mem);
    void initInput(const json& mem);
    void importFromJson();
    void aligning();
public:
    Sprite(SDL_Renderer* r);
    ~Sprite();
    
    void linking(std::string n);
    void setFont(TTF_Font* f);
    void setFontColor(SDL_Color c);

    void setTextBox(TTF_Font* f);
    void setTextBoxTransparent(int a);
    void setText(std::string s);
    void typing(char c);
    void typing(std::string s);
    void backspace();
    void backspace(int n);
    std::string getText();

    void locating(int x, int y, int w, int h) override;
    void locating(SDL_Rect r) override;
    void locatingX(int x) override;
    void locatingY(int y) override;
    void moveX(int x) override;
    void moveY(int y) override;

    void aligning(HORIZONTAL_ALIGN h, VERTICAL_ALIGN v);
    void aligning(HORIZONTAL_ALIGN h);
    void aligning(VERTICAL_ALIGN v);

    void rendering() override;
    void highlight();
    void unhighlight();
};

#endif 
