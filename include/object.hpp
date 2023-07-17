#ifndef OBJECT 
#define OBJECT

#include <string> 

#include <SDL2/SDL.h>

#include <GLOBAL.hpp>

class Object 
{
private:
    SDL_Renderer* render;
    SDL_Rect* location;
    SDL_Rect* crop;
    
    SDL_Color *color;
    SDL_Texture *texture;
    SHAPE shapeType;

    int radius;
    SDL_Point center;

protected:
    void fillWithColor();
    void fillCircleByColor();
    void fillRectangleByColor(); 
public:
    Object(SDL_Renderer *& r);
    ~Object();

    const SDL_Rect* getCrop();
    void cropping(int x, int y, int w, int h);
    void cropping(SDL_Rect c);
    void noCropping();

    const SDL_Rect* getLocation();
    int getX();
    int getY();
    int getW();
    int getH();

    void locating(int x, int y, int w, int h);
    void locating(SDL_Rect l);
    
    void locatingX(int x);
    void locatingY(int y);
    void locatingW(int w);
    void locatingH(int h);

    void moveX(int delta);
    void moveY(int delta);
    void zoomW(int delta);
    void zoomH(int delta);

    const SDL_Color* getColor();
    void coloring(int r, int g, int b, int a);
    void coloring(SDL_Color c);

    void importFromFile(std::string dir);
    
    void changeToCircle();
    void changeToCircle(SDL_Point c);
    void changeToCircle(SDL_Point c, int r);   
    void changeToCircle(int x, int y, int r);

    void changeToRectangle();

    virtual void rendering();
};

#endif
