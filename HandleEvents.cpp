#include"Game.h"

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (currentState)
            {
            case GameState::TitleScreen:
                // Handle Title Screen input
                break;
            case GameState::MainMenu:
                handleMainMenuInput(event.key.keysym.sym);
                break;
            case GameState::Credit:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    currentState = GameState::MainMenu;
                break;
            case GameState::Game:
                handleGameInput(event.key.keysym.sym);
                break;
            case GameState::Pause:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    currentState = GameState::Game;
                break;
            case GameState::Win:
                if (event.key.keysym.sym == SDLK_SPACE)
                    currentState = GameState::MainMenu;
                break;
            case GameState::Lose:
                if (event.key.keysym.sym == SDLK_SPACE)
                    currentState = GameState::MainMenu;
                break;
            }
        }
    }
}

void Game::handleMainMenuInput(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_c:
        currentState = GameState::Credit;
        break;
    case SDLK_g:
        currentState = GameState::Game;
        break;
    }
}

void Game::handleGameInput(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_w:
    {
        y1 -= 5;
    }
    break;
    case SDLK_a:
    {
        x1 -= 5;
    }
    break;
    case SDLK_s:
    {
        y1 += 5;
    }
    break;
    case SDLK_d:
    {
        x1 += 5;
    }
    break;
    case SDLK_p:
        currentState = GameState::Pause;
        break;
    case SDLK_ESCAPE:
        currentState = GameState::Game;
        break;
    }
}