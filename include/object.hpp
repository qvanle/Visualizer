#ifndef OBJECT 
#define OBJECT

#include <SDL2/SDL.h>

class Object 
{
private:
    SDL_Renderer* ren;
    SDL_Rect* location;
    SDL_Rect* crop;
    
    SDL_Color *color;
    SDL_Texture *texture;

protected:
    void fillWithColor();
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
    
    void rendering();
};

#endif
