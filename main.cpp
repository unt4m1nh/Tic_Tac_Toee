#include<iostream>
#include<SDL.h>

#include"Engine.h"

using namespace std;


int main(int argc, char* args[])
{
    Engine* engine = new Engine();

    engine->initGame();

    engine->run();

    return 0;
}
