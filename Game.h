#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<string>
#include<iostream>
using namespace std;

// Game class as a Singleton
class Game
{
private:
    static Game* instance;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* ObjectSurface = NULL;
    SDL_Texture* ObjectTexture = NULL;
    bool isRunning;

    // Game states
    enum class GameState
    {
        TitleScreen,
        MainMenu,
        Credit,
        Game,
        Pause,
        Win,
        Lose
    };
    GameState currentState;

    int x1, x2, y1, y2;
    int w1, w2, h1, h2;
    int ms;

    string Dev = "./Assets/Developer.jpg";

    SDL_Texture* titleScreenImage = NULL;
    SDL_Texture* mainMenuBackground = NULL;
    SDL_Texture* gameNameImage = NULL;
    SDL_Texture* MMkeyboardImage = NULL;
    SDL_Texture* creditTitleImage = NULL;
    SDL_Texture* yourNameImage = NULL;
    SDL_Texture* CkeyboardImage = NULL;
    SDL_Texture* gameBackground = NULL;
    SDL_Texture* playerImage = NULL;
    SDL_Texture* obstacleImage = NULL;
    SDL_Texture* GkeyboardImage = NULL;
    SDL_Texture* pauseText = NULL;
    SDL_Texture* winText = NULL;
    SDL_Texture* loseText = NULL;

    Game();

public:
    static Game* getInstance();
    bool initialize();

    SDL_Texture* loadImage(const std::string& filename);
    Mix_Music* loadMusic(const std::string& filename);
    Mix_Chunk* loadSoundEffect(const std::string& filename);

    void handleEvents();
    void handleMainMenuInput(SDL_Keycode key);
    void handleGameInput(SDL_Keycode key);
    
    void update();
    void run();
    void cleanup();
};