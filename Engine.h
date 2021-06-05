#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Engine{

    public:
        bool initGame();
        void close();
        bool run();

        // init function
        bool initWindowAndRender();

    private:
        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;
};

#endif // ENGINE_H_INCLUDED
