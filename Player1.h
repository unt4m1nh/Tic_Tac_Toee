#ifndef PLAYER1_H
#define PLAYER1_H

#include"Config.h"
#include"Interface.h"

#include<SDL.h>
#include<iostream>

class Player1 {
    public:
        Player1(SDL_Renderer* &gRenderer);
         ~Player1();

        void input(SDL_Event& e);
        char chess;

    private:
        Interface* interface;

};

#endif // PLAYER1_H
