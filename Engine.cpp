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


void Engine::player_input(SDL_Event& e)
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
                if(x < 0 || x > CHESS_BOX_WIDTH || y < 0 || y > CHESS_BOX_HEIGHT)
                {
                    inside_box[0][0] = false;
                }
                if(inside_box[0][0] && this->interface->game_board[0][0] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[0][0] = state % 2;
                            }
                }
                if(x < 0 || x > CHESS_BOX_WIDTH || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
                {
                    inside_box[0][1] = false;
                }
                if(inside_box[0][1] && this->interface->game_board[0][1] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[0][1] = state % 2;
                            }
                }
                if(x < 0 || x > CHESS_BOX_WIDTH || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
                {
                    inside_box[0][2] = false;
                }
                if(inside_box[0][2] && this->interface->game_board[0][2] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[0][2] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < 0 || y > CHESS_BOX_HEIGHT)
                {
                    inside_box[1][0] = false;
                }
                if(inside_box[1][0] && this->interface->game_board[1][0] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[1][0] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
                {
                    inside_box[1][1] = false;
                }
                if(inside_box[1][1] && this->interface->game_board[1][1] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[1][1] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
                {
                    inside_box[1][2] = false;
                }
                if(inside_box[1][2] && this->interface->game_board[1][2] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[1][2] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < 0 || y > CHESS_BOX_HEIGHT)
                {
                    inside_box[2][0] = false;
                }
                if(inside_box[2][0] && this->interface->game_board[2][0] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[2][0] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
                {
                    inside_box[2][1] = false;
                }
                if(inside_box[2][1] && this->interface->game_board[2][1] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[2][1] = state % 2;
                            }
                }
                if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
                {
                    inside_box[2][2] = false;
                }
                if(inside_box[2][2] && this->interface->game_board[2][2] == 2)
                {
                            if (e.type == SDL_MOUSEBUTTONDOWN )
                            {
                               this->interface->game_board[2][2] = state % 2;
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
            this->player_input(e);
        }
        this->interface->renderChessBoard(this->gRenderer);
        this->state+=1;
        cout << this->state << endl;
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
