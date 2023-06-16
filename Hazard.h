#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "Game.h"

class Hazard
{
public:
    Hazard(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
    ~Hazard();

    void update();
    void render();

    SDL_Rect getBoundingBox();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect hazardRect;
    int velocityX;
};

Hazard::Hazard(SDL_Renderer* renderer, const std::string& imagePath, int x, int y)
    : renderer(renderer), velocityX(-5)
{
    texture = IMG_LoadTexture(renderer, imagePath.c_str());

    SDL_QueryTexture(texture, nullptr, nullptr, &hazardRect.w, &hazardRect.h);
    hazardRect.x = x;
    hazardRect.y = y;
}

Hazard::~Hazard()
{
    SDL_DestroyTexture(texture);
}

void Hazard::update()
{
    hazardRect.x += velocityX;

    // Wrap around when hazard goes off-screen
    if (hazardRect.x + hazardRect.w < 0)
    {
        hazardRect.x = ScreenWidth;
    }
}

void Hazard::render()
{
    SDL_RenderCopy(renderer, texture, nullptr, &hazardRect);
}

SDL_Rect Hazard::getBoundingBox()
{
    return hazardRect;
}