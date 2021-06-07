#ifndef INTERFACE_H
#define INTERFACE_H

#include<SDL.h>
#include<SDL_image.h>
#include<string>

#include "LTexture.h"


using namespace std;

class Interface
{
    public:
        Interface(SDL_Renderer* &gRenderer);
        ~Interface();

        int game_board[3][3] = {{0,1,0},
                                {0,2,0},
                                {0,0,0}};

        void renderChessBoard(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);

         // game texture declaration
        LTexture ChessBoxTexture[3];
        string ChessBoxTexturePath[3] = {"./images/emty_cb.png",
                                         "./images/x_cb.png",
                                         "./images/o_cb.png"};

};



#endif // INTERFACE_H
