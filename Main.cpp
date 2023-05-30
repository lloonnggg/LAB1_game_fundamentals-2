#include <SDL.h>
#include <iostream>

// Game class as a Singleton
class Game
{
private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
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

    // Private constructor
    Game() {}

public:
    static Game* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Game();
        }
        return instance;
    }

    // Initialize SDL and create window/renderer
    bool initialize()
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

    // Handle input events
    void handleEvents()
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

    // Handle input events for the Main Menu state
    void handleMainMenuInput(SDL_Keycode key)
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

    // Handle input events for the Game state
    void handleGameInput(SDL_Keycode key)
    {
        switch (key)
        {
        case SDLK_w:
            // Move the white square up
            break;
        case SDLK_a:
            // Move the white square left
            break;
        case SDLK_s:
            // Move the white square down
            break;
        case SDLK_d:
            // Move the white square right
            break;
        case SDLK_p:
            currentState = GameState::Pause;
            break;
        case SDLK_ESCAPE:
            currentState = GameState::Game;
            break;
        case SDLK_1:
            currentState = GameState::Win;
            break;
        case SDLK_2:
            currentState = GameState::Lose;
            break;
        }
    }

    // Update game state
    void update()
    {
        switch (currentState)
        {
        case GameState::TitleScreen:
        {
            for (int i = 1; i <= 4; i++)
            {
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
            }
            currentState = GameState::MainMenu;
        }
            break;
        case GameState::MainMenu:
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255);
            SDL_RenderPresent(renderer);
        }
            break;
        case GameState::Credit:
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
            SDL_RenderPresent(renderer);
        }
            break;
        case GameState::Game:
            // Update Game Screen logic
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderPresent(renderer);
        }
            // Check collision with another object
            // Check survival time for win condition
            break;
        case GameState::Pause:
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
            SDL_RenderPresent(renderer);
        }
            break;
        case GameState::Win:
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderPresent(renderer);
        }
            break;
        case GameState::Lose:
        {
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderPresent(renderer);
        }
            break;
        }
    }

    // Run the game loop
    void run()
    {
        while (isRunning)
        {
            handleEvents();
            update();
        }
    }

    // Clean up resources and quit SDL
    void cleanup()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

Game* Game::instance = nullptr;

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