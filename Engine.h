#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include"LTexture.h"
#include"Interface.h"

using namespace std;

class Engine{

    public:

        // game logic functions
        void close();
        bool run();
        void two_player();
        void vs_computer();
        void check_winner();

        // init functions
        bool initWindowAndRender();
        bool initGame();
        bool initInterface(SDL_Renderer* &gRenderer);

        //input functions
        void player1_input(SDL_Event& e);

    private:
        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;
        Interface* interface;
};

#endif // ENGINE_H_INCLUDED
