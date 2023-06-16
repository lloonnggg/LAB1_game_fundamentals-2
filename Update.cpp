#include"Game.h"

void Game::update()
{
    switch (currentState)
    {
    case GameState::TitleScreen:
    {
        for (int i = 1; i <= 4; i++)
        {
            SDL_RenderClear(renderer);
            // Render title screen image
            titleScreenImage = loadImage(Dev.c_str());
            if (titleScreenImage != nullptr)
                SDL_RenderCopy(renderer, titleScreenImage, nullptr, nullptr);
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
        // Render main menu background image
        mainMenuBackground = loadImage("./Assets/background.jpg");
        if (mainMenuBackground != nullptr)
            SDL_RenderCopy(renderer, mainMenuBackground, nullptr, nullptr);
        // Render game name image
        gameNameImage = loadImage("./Assets/GameName.png");
        if (gameNameImage != nullptr)
        {
            SDL_Rect destRect = { 200, 200, 400, 100 };
            SDL_RenderCopy(renderer, gameNameImage, nullptr, &destRect);
        }
        // Render keyboard input image
        MMkeyboardImage = loadImage("keyboard_image.png");
        if (MMkeyboardImage != nullptr)
        {
            SDL_Rect destRect = { 300, 400, 200, 100 };
            SDL_RenderCopy(renderer, MMkeyboardImage, nullptr, &destRect);
        }
        SDL_RenderPresent(renderer);
    }
    break;
    case GameState::Credit:
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
        // Render credit title image
        creditTitleImage = loadImage("credit_title_image.png");
        if (creditTitleImage != nullptr)
            SDL_RenderCopy(renderer, creditTitleImage, nullptr, nullptr);
        // Render your name image
        yourNameImage = loadImage("your_name_image.png");
        if (yourNameImage != nullptr)
        {
            SDL_Rect destRect = { 200, 200, 400, 100 };
            SDL_RenderCopy(renderer, yourNameImage, nullptr, &destRect);
        }
        // Render keyboard input image
        CkeyboardImage = loadImage("keyboard_image.png");
        if (CkeyboardImage != nullptr)
        {
            SDL_Rect destRect = { 300, 400, 200, 100 };
            SDL_RenderCopy(renderer, CkeyboardImage, nullptr, &destRect);
        }
        SDL_RenderPresent(renderer);
    }
    break;
    case GameState::Game:
        // Update Game Screen logic
    {
        SDL_RenderClear(renderer);
        // Render game background image
        gameBackground = loadImage("./Assets/background.jpg");
        if (gameBackground != nullptr)
            SDL_RenderCopy(renderer, gameBackground, nullptr, nullptr);
        // Render player image
        playerImage = loadImage("./Assets/player.png");
        if (playerImage != nullptr)
        {
            SDL_Rect destRect = { x1, y1, w1, h1 };
            SDL_RenderCopy(renderer, playerImage, nullptr, &destRect);
        }
        // Render obstacle image
        obstacleImage = loadImage("./Assets/obstacle.png");
        if (obstacleImage != nullptr)
        {
            SDL_Rect destRect = { x2, y2, w2, h2 };
            SDL_RenderCopy(renderer, obstacleImage, nullptr, &destRect);
        }
        // Render keyboard input image
        GkeyboardImage = loadImage("keyboard_image.png");
        if (GkeyboardImage != nullptr)
        {
            SDL_Rect destRect = { 300, 400, 200, 100 };
            SDL_RenderCopy(renderer, GkeyboardImage, nullptr, &destRect);
        }
        SDL_RenderPresent(renderer);

        ms++;

        if (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2)
        {
            currentState = GameState::Lose;
        }
        if (ms == 666)
        {
            currentState = GameState::Win;
        }
    }
    break;
    case GameState::Pause:
    {
        SDL_RenderClear(renderer);
        // Render pause text
        pauseText = loadImage("pause_text.png");
        if (pauseText != nullptr)
            SDL_RenderCopy(renderer, pauseText, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
    break;
    case GameState::Win:
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        // Render win text
        winText = loadImage(". / Assets / Win.jpg");
        if (winText != nullptr)
            SDL_RenderCopy(renderer, winText, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
    break;
    case GameState::Lose:
    {
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // Render lose text
        loseText = loadImage("./Assets/Lose.png");
        if (loseText != nullptr)
            SDL_RenderCopy(renderer, loseText, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
    break;
    }
}