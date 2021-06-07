#include"Engine.h"
#include"Config.h"


#include<iostream>

bool Engine::initWindowAndRender() {

    // Initialization flag
    bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		this->gWindow = SDL_CreateWindow( "Tic-Tac-Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( this->gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			this->gRenderer = SDL_CreateRenderer( this->gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( this->gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Engine::initInterface(SDL_Renderer* &gRenderer)
{
    this->interface = new Interface(gRenderer);

    return true;
}

bool Engine::initGame()
{
    this->initWindowAndRender();
    this->initInterface(gRenderer);

    return true;
}

void Engine::player1_input(SDL_Event& e)
{
    bool inside_box[3][3] = {{true,true,true},
                             {true,true,true},
                             {true,true,true}};

    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(x < i || x > CHESS_BOX_WIDTH*(i+1) || y < j || y > CHESS_BOX_HEIGHT*(j+1))
                    {
                        inside_box[i][j] = false;
                    }
                    if(inside_box[i][j] && this->interface->game_board[i][j] == 0)
                    {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
}


void Engine::two_player()
{

}



bool Engine::run()
{
    bool quit = false;

    SDL_Event e;
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            this->player1_input(e);
        }
        this->interface->renderChessBoard(this->gRenderer);

        SDL_RenderPresent(gRenderer);

    }
    this->close();

    return true;
}

void Engine::close()
{
    SDL_DestroyRenderer(this->gRenderer);
    SDL_DestroyWindow(this->gWindow);

    SDL_Quit();
}
