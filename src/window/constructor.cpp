#include <window.hpp>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void MyWindow::initSDL2()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    window = SDL_CreateWindow(
        "Dr Duck",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    render = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init();
}

MyWindow::MyWindow()
{
    HEIGHT = 635;
    WIDTH = 1200;
    status = WINDOW_STATUS::IS_CLOSED;
    FPS = 60;
    viewport = SDL_Rect({0, 0, WIDTH, HEIGHT});

    window = nullptr;
    render = nullptr;

    initSDL2();

}

