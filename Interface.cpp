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
    this->EmtyChessBoxTexture.free();
}

bool Interface::loadMedia(SDL_Renderer* &gRenderer)
{
    //Loading success flag
    bool success = true;
    this->EmtyChessBoxTexture.loadFromFile(this->EmtyChessBoxTexturePath, gRenderer);
    if (this->EmtyChessBoxTexture.get_mTexture() == NULL) {
            success = false;
            printf( "Failed to load playgorund texture image %d!\n" );
    }
    return success;
}

void Interface::renderChessBoard(SDL_Renderer* &gRenderer)
{

    for(int i = 100; i <= 500; i+= 200)
    {
        for(int j = 0; j <= 400; j += 200)
        {
              this->EmtyChessBoxTexture.render(gRenderer,i,j);
        }
    }
    SDL_RenderPresent(gRenderer);

    return;
}
