#ifndef OBJECT 
#define OBJECT

#include <string> 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <nlohmann/json.hpp>

#include <GLOBAL.hpp>

using json = nlohmann::json;

struct Position 
{
    SDL_Rect* location;
    SDL_Rect* crop;
    int radius;
    SDL_Point center;
    bool visible;
};

class Object : private Position
{
private:
    SDL_Renderer* render;
    TTF_Font* font;
    std::string text;

    SDL_Color *color;
    SDL_Texture *texture;
    SHAPE shapeType;

    std::string name;
protected:
    void fillWithColor();
    void fillCircleByColor();
    void fillRectangleByColor(); 

    void textToTexture();
public:
    Object(SDL_Renderer *& r);
    ~Object();

    const SDL_Rect* getCrop();
    void cropping(int x, int y, int w, int h);
    void cropping(SDL_Rect c);
    void cropping(const json& mem);
    void noCropping();

    const SDL_Rect* getLocation();
    int getX();
    int getY();
    int getW();
    int getH();

    virtual void locating(int x, int y, int w, int h);
    virtual void locating(SDL_Rect l);
    virtual void locating(const json& mem);

    virtual void locatingX(int x);
    virtual void locatingY(int y);
    virtual void locatingW(int w);
    virtual void locatingH(int h);

    virtual void moveX(int delta);
    virtual void moveY(int delta);
    virtual void zoomW(int delta);
    virtual void zoomH(int delta);
    virtual void zoom(double delta);
    virtual void zoomInMiddle(double delta);
    
    void fitTheTexture();
    const SDL_Color* getColor();
    void coloring(int r, int g, int b, int a);
    void coloring(SDL_Color c);
    void coloring(const json& mem);

    void textureFromFile(std::string dir);

    void changeToCircle();
    void changeToCircle(SDL_Point c);
    void changeToCircle(int x, int y);
    void changeToCircle(SDL_Point c, int r);   
    void changeToCircle(int x, int y, int r);

    void changeToRectangle();
    void setShape(const json& mem);


    bool isLieInside(int x, int y);
    bool isLieInside(SDL_Point p);
    bool isLieInside(SDL_Rect r);
    bool isLieInside(int x, int y, int w, int h);

    virtual void rendering();

    void show();
    void hide();
    bool isVisible();  
    
    void importFromJson(const json& mem);

    void linking(std::string n);

    void setFont(TTF_Font* f);
    void setText(std::string t);
    void addText(std::string t);
    void addCharacter(char c);
    void removeCharacter();
    void removeCharacter(int n);

};

#endif
