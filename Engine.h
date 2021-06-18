#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include"LTexture.h"
#include"Interface.h"
#include"Player1.h"

using namespace std;

class Engine{

    public:

        // game logic functions
        void close();
        bool run();
        void two_player();
        void vs_computer();
        //int check_winner();
        bool check_winner(int player);

        // init functions
        bool initWindowAndRender();
        bool initGame();
        bool initInterface(SDL_Renderer* &gRenderer);

        //input functions
        void switch_player();
        void player_input(int j, int i);
        int state = -1;

    private:
        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;
        Interface* interface;
};

#endif // ENGINE_H_INCLUDED
