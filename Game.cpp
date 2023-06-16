#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
    // Initialize member variables here
}

Game* Game::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}

bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow("Labs_LastName", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    isRunning = true;
    currentState = GameState::TitleScreen;
    return true;
}

void Game::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void Game::run()
{
    x1 = 50;
    y1 = 50;
    x2 = 300;
    y2 = 300;
    w1 = 50;
    h1 = 50;
    w2 = 150;
    h2 = 150;
    // Load resources
    // Example: SDL_Texture* titleScreenImage = loadImage("title_screen_image.png");
    // Example: Mix_Music* backgroundMusic = loadMusic("background_music.mp3");
    // Example: Mix_Chunk* jumpSoundEffect = loadSoundEffect("jump_sound.wav");


    // Game loop
    while (isRunning)
    {
        handleEvents();
        update();
    }

    cleanup();
}
