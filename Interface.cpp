#include "Interface.h"
#include "Config.h"

#include<SDL.h>
#include<SDL_image.h>
#include<string>



Interface::Interface(SDL_Renderer* &gRenderer)
{
    this->loadMedia(gRenderer);
}

Interface::~Interface()
{
    for(int i = 0; i < 3; i++)
    {
        this->ChessBoxTexture[i].free();
    }
}

bool Interface::loadMedia(SDL_Renderer* &gRenderer)
{
    //Loading success flag
    bool success = true;
    for(int i = 0; i < 3; i++)
    {
        this->ChessBoxTexture[i].loadFromFile(this->ChessBoxTexturePath[i], gRenderer);
    }
    for(int i = 0; i < 3; i++)
    {
        if (this->ChessBoxTexture[i].get_mTexture() == NULL) {
                success = false;
                printf( "Failed to load playgorund texture image %d!\n" );
        }
    }
    return success;
}

void Interface::renderChessBoard(SDL_Renderer* &gRenderer)
{

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
              int states = game_board[i][j];
              this->ChessBoxTexture[states].render(gRenderer,i*200,j*200);
        }
    }
    SDL_RenderPresent(gRenderer);

    return;
}
