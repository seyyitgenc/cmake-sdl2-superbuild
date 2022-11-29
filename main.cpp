#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "dog.h"
#include "worked.h"

int main(int argc, char **argv)
{
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(0);
    Dog *d1 = new Dog();
    Testing *t1 = new Testing();
    SDL_Window *window = SDL_CreateWindow("WORKEDDD!!!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    bool isRunning = true;
    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }
    }
    delete t1;
    delete d1;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}