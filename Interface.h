#ifndef INTERFACE_H
#define INTERFACE_H

#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include "Config.h"
#include "LTexture.h"
#define player1 -1
#define player2 1

using namespace std;

class Interface
{
    public:
        Interface(SDL_Renderer* &gRenderer);
        ~Interface();

        int game_board[N][N] = {{0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,0,0,0,0}};


        void renderChessBoard(SDL_Renderer* &gRenderer);
        void renderGameOverP1(SDL_Renderer* &gRenderer);
        void renderGameOverP2(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);

         // game texture declaration
        LTexture ChessBoxTexture[3];
        string ChessBoxTexturePath[3] = {"./images/x_cb.png",
                                         "./images/emty_cb.png",
                                         "./images/o_cb.png"};
        LTexture GameOverTextureP1;
        LTexture GameOverTextureP2;
        string GameOverTexturePathP1 = "./images/background-scene---player-1-win.png";
        string GameOverTexturePathP2 = "./images/background-scene---player-2-win.png";
};



#endif // INTERFACE_H
