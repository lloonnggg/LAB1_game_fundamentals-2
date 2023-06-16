#include "Game.h"

int main(int argc, char* argv[])
{
    Game* game = Game::getInstance();
    if (game->initialize())
    {
        game->run();
        game->cleanup();
    }
    delete game;
    return 0;
}