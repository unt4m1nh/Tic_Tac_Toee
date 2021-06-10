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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
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
                               this->state++;
                            }
                }
            }
        }
}

/*int Engine::check_winner()
{
    int game_over = 2;
    int row1 = this->interface->game_board[0][0] + this->interface->game_board[0][1] + this->interface->game_board[0][2];
    int row2 = this->interface->game_board[1][0] + this->interface->game_board[1][1] + this->interface->game_board[1][2];
    int row3 = this->interface->game_board[2][0] + this->interface->game_board[2][1] + this->interface->game_board[2][2];
    int col1 = this->interface->game_board[0][0] + this->interface->game_board[1][0] + this->interface->game_board[2][0];
    int col2 = this->interface->game_board[0][1] + this->interface->game_board[1][1] + this->interface->game_board[2][1];
    int col3 = this->interface->game_board[0][2] + this->interface->game_board[1][2] + this->interface->game_board[2][2];
    int dig_left_right = this->interface->game_board[0][0] + this->interface->game_board[1][1] + this->interface->game_board[2][2];
    int dig_right_left = this->interface->game_board[0][2] + this->interface->game_board[1][1] + this->interface->game_board[2][0];
    if(row1 == 0 || row2 == 0 || row3 == 0 || col1 == 0 || col2 == 0 || col3 == 0 || dig_left_right == 0 || dig_right_left == 0)
    {
        game_over = 0;
    }
    else if(row1 == 3 || row2 == 3 || row3 == 3 || col1 == 3 || col2 == 3 || col3 == 3 || dig_left_right == 3 || dig_right_left == 3)
    {
        game_over = 1;
    }
    return game_over;
}*/
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
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            this->player_input(e);
        }
        this->interface->renderChessBoard(this->gRenderer);
        if(this->check_winner(player1)==true||this->check_winner(player2)==true)
        {
            this->interface->renderGameOver(this->gRenderer);

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
