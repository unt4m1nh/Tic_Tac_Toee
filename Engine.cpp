#include"Engine.h"
#include"Config.h"


#include<iostream>
using namespace std;
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
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
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

void Engine::switch_player(){
    if (this->state==-1) this->state=1;
    else if (this->state==1) this->state=-1;
}

void Engine::player_input(int i, int j)
{
    if(this->interface->game_board[i][j]==0){
        this->interface->game_board[i][j]=state;
        switch_player();
        move++;
    }
}


bool Engine:: check_winner(int player){
    bool over = false;
    int row_count = -100;
    int col_count = -100;
    int dig_count_1 = -100;
    int dig_count_2 = -100;
    int max_sum = -100;

    if(player == -1)
    {
        max_sum = -3;
    }
    else if(player == 1)
    {
        max_sum = 3;
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                row_count = this->interface->game_board[i][j]+ this->interface->game_board[i+1][j] + this->interface->game_board[i+2][j];
                col_count = this->interface->game_board[i][j] + this->interface->game_board[i][j+1] + this->interface->game_board[i][j+2];
                dig_count_1 = this->interface->game_board[i][j]+ this->interface->game_board[i+1][j+1] + this->interface->game_board[i+2][j+2];
                dig_count_2 = this->interface->game_board[i][j+2]+ this->interface->game_board[i+1][j+1]+ this->interface->game_board[i+2][j];
                if(row_count == max_sum || col_count == max_sum || dig_count_1 == max_sum || dig_count_2 == max_sum)
                {
                    over = true;
                    break;
                }
            }
        }
    return over;
}
bool Engine::run()
{
    bool quit = false;
    SDL_Event e;
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            switch(e.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    this->player_input(e.button.x/CHESS_BOX_WIDTH,e.button.y/CHESS_BOX_HEIGHT);
                    break;
            }
        }
        this->interface->renderChessBoard(this->gRenderer);

        if(this->check_winner(player1)==true)
        {
            this->interface->renderGameOverP1(this->gRenderer);
            SDL_Delay(50000);
        }
        if(this->check_winner(player2)==true){
            this->interface->renderGameOverP2(this->gRenderer);
            SDL_Delay(50000);
        }
        if(this->check_winner(player1)==false && this->check_winner(player2)==false && move == 25)
        {
            this->interface->renderTiedGame(this->gRenderer);
            SDL_Delay(50000);
        }
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
