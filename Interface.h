#ifndef INTERFACE_H
#define INTERFACE_H

#include<SDL.h>
#include<SDL_image.h>
#include<string>

#include "LTexture.h"
#define player1 0
#define player2 1

using namespace std;

class Interface
{
    public:
        Interface(SDL_Renderer* &gRenderer);
        ~Interface();

        int game_board[3][3] = {{2,2,2},
                                {2,2,2},
                                {2,2,2}};

        void renderChessBoard(SDL_Renderer* &gRenderer);
        void renderGameOver(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);

         // game texture declaration
        LTexture ChessBoxTexture[3];
        string ChessBoxTexturePath[3] = {"./images/x_cb.png",
                                         "./images/o_cb.png",
                                         "./images/emty_cb.png"};
        LTexture GameOverTexture;
        string GameOverTexturePath = "./images/game_over.png";

};



#endif // INTERFACE_H
