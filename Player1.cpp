#include"Player1.h"

#include<iostream>

Player1::Player1(SDL_Renderer* &gRenderer)
{

}

Player1::~Player1()
{

}

void Player1::input(SDL_Event& e)
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
            if(inside_box[0][0] && this->interface->game_board[0][0] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[0][0] = 1;
                        }
            }
            if(x < 0 || x > CHESS_BOX_WIDTH || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
            {
                inside_box[0][1] = false;
            }
            if(inside_box[0][1] && this->interface->game_board[0][1] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[0][1] = 1;
                        }
            }
            if(x < 0 || x > CHESS_BOX_WIDTH || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
            {
                inside_box[0][2] = false;
            }
            if(inside_box[0][2] && this->interface->game_board[0][2] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[0][2] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < 0 || y > CHESS_BOX_HEIGHT)
            {
                inside_box[1][0] = false;
            }
            if(inside_box[1][0] && this->interface->game_board[1][0] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[1][0] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
            {
                inside_box[1][1] = false;
            }
            if(inside_box[1][1] && this->interface->game_board[1][1] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[1][1] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH || x > CHESS_BOX_WIDTH * 2 || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
            {
                inside_box[1][2] = false;
            }
            if(inside_box[1][2] && this->interface->game_board[1][2] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[1][2] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < 0 || y > CHESS_BOX_HEIGHT)
            {
                inside_box[2][0] = false;
            }
            if(inside_box[2][0] && this->interface->game_board[2][0] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[2][0] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < CHESS_BOX_HEIGHT || y > CHESS_BOX_HEIGHT * 2)
            {
                inside_box[2][1] = false;
            }
            if(inside_box[2][1] && this->interface->game_board[2][1] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[2][1] = 1;
                        }
            }
            if(x < CHESS_BOX_WIDTH * 2 || x > CHESS_BOX_WIDTH * 3 || y < CHESS_BOX_HEIGHT * 2 || y > CHESS_BOX_HEIGHT * 3)
            {
                inside_box[2][2] = false;
            }
            if(inside_box[2][2] && this->interface->game_board[2][2] == 0)
            {
                        if (e.type == SDL_MOUSEBUTTONDOWN )
                        {
                           this->interface->game_board[2][2] = 1;
                        }
            }
        }
    }
}
