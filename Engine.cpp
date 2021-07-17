#include"Engine.h"
#include"Config.h"


#include<iostream>
#include<time.h>
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
    if (this->state==1) this->state=2;
    else if (this->state==2) this->state=1;
}

void Engine::random()
{
    srand(time(0));
    this->cpu_move_x = rand() % 3;
    this->cpu_move_y = rand() % 3;
}

bool Engine::check_move(int x, int y)
{
    if (this->interface->game_board[x][y] == 0)
    {
        return false;
    }
    return true;
}


void Engine::player_input(int i, int j)
{
    if(this->interface->game_board[i][j]==0){
        this->interface->game_board[i][j]=state;
        move++;
    }
}

void Engine::moving(SDL_Event& e, int s)
{
    switch(s)
    {
       case 1:
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                    this->player_input(e.button.x/CHESS_BOX_WIDTH,e.button.y/CHESS_BOX_HEIGHT);
                    if(move <= 8)
                    {
                        this->switch_player();
                    }
            }
            break;
       case 2:
            do
            {
                this->random();
            }
            while(this->check_move(cpu_move_x,cpu_move_y));
            this->interface->game_board[cpu_move_x][cpu_move_y] = this->state;
            move++;
            this->switch_player();
            break;
    }
}

bool Engine:: check_winner(int player){
    int row_count;
    int col_count=0;
    int dig_count1=0;
    int dig_count2=0;
    for(int i=0;i<3;i++){
            row_count=0;
            col_count=0;
        for(int j=0;j<3;j++){
            if(this->interface->game_board[i][j]==player) row_count++;
            if(this->interface->game_board[j][i]==player) col_count++;
        }
            if(row_count==3||col_count==3) return true;
            //r->l
            if(this->interface->game_board[i][i]==player) dig_count1++;
            //l->r
            if(this->interface->game_board[i][2-i]==player) dig_count2++;
    }
    //check
    if (dig_count1==3||dig_count2==3) return true;
    else return false;
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
            }
            this->moving(e,this->state);
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
        if(this->check_winner(player1)==false && this->check_winner(player2)==false && move == 9)
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
