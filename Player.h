#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Player
{
public:
    Player(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
    ~Player();

    void handleEvent(SDL_Event& event);
    void update();
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect playerRect;
    int velocityX;
    int velocityY;
    bool isJumping;

    const int GRAVITY = 1;
    const int JUMP_VELOCITY = -15;
    const int MAX_VELOCITY = 10;
};

Player::Player(SDL_Renderer* renderer, const std::string& imagePath, int x, int y)
    : renderer(renderer), velocityX(0), velocityY(0), isJumping(false)
{
    texture = IMG_LoadTexture(renderer, imagePath.c_str());

    SDL_QueryTexture(texture, nullptr, nullptr, &playerRect.w, &playerRect.h);
    playerRect.x = x;
    playerRect.y = y;
}

Player::~Player()
{
    SDL_DestroyTexture(texture);
}

void Player::handleEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_SPACE:
            if (!isJumping)
            {
                velocityY = JUMP_VELOCITY;
                isJumping = true;
            }
            break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_SPACE:
            // Disable double jumping
            if (velocityY < JUMP_VELOCITY / 2)
            {
                velocityY = JUMP_VELOCITY / 2;
            }
            break;
        }
    }
}

void Player::update()
{
    // Apply gravity
    velocityY += GRAVITY;

    // Limit velocity
    if (velocityX > MAX_VELOCITY)
    {
        velocityX = MAX_VELOCITY;
    }
    else if (velocityX < -MAX_VELOCITY)
    {
        velocityX = -MAX_VELOCITY;
    }

    if (velocityY > MAX_VELOCITY)
    {
        velocityY = MAX_VELOCITY;
    }
    else if (velocityY < -MAX_VELOCITY)
    {
        velocityY = -MAX_VELOCITY;
    }

    // Update player position
    playerRect.x += velocityX;
    playerRect.y += velocityY;

    // Bound player within screen
    if (playerRect.x < 0)
    {
        playerRect.x = 0;
    }
    else if (playerRect.x + playerRect.w > SCREEN_WIDTH)
    {
        playerRect.x = SCREEN_WIDTH - playerRect.w;
    }

    if (playerRect.y < 0)
    {
        playerRect.y = 0;
    }
    else if (playerRect.y + playerRect.h > SCREEN_HEIGHT)
    {
        playerRect.y = SCREEN_HEIGHT - playerRect.h;
        velocityY = 0;
        isJumping = false;
    }
}

void Player::render()
{
    SDL_RenderCopy(renderer, texture, nullptr, &playerRect);
}



