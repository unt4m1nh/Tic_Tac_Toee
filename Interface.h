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

        void renderChessBoard(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);

         // game texture declaration
        LTexture EmtyChessBoxTexture;
        string EmtyChessBoxTexturePath = "./images/emty_cb.png";

};



#endif // INTERFACE_H
