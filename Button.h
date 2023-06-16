#pragma once
#include <SDL.h>
#include <string>

class Button
{
public:
    Button(SDL_Renderer* renderer, const std::string& upImage, const std::string& overImage, const std::string& downImage, int x, int y);
    ~Button();

    void handleEvent(SDL_Event& event);
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* upTexture;
    SDL_Texture* overTexture;
    SDL_Texture* downTexture;
    SDL_Rect buttonRect;
    bool isPressed;

    enum class ButtonState
    {
        Up,
        Over,
        Down
    };
    ButtonState currentState;
};

// Button.cpp
#include "Button.h"
#include <SDL_image.h>

Button::Button(SDL_Renderer* renderer, const std::string& upImage, const std::string& overImage, const std::string& downImage, int x, int y)
    : renderer(renderer), isPressed(false), currentState(ButtonState::Up)
{
    upTexture = IMG_LoadTexture(renderer, upImage.c_str());
    overTexture = IMG_LoadTexture(renderer, overImage.c_str());
    downTexture = IMG_LoadTexture(renderer, downImage.c_str());

    SDL_QueryTexture(upTexture, nullptr, nullptr, &buttonRect.w, &buttonRect.h);
    buttonRect.x = x;
    buttonRect.y = y;
}

Button::~Button()
{
    SDL_DestroyTexture(upTexture);
    SDL_DestroyTexture(overTexture);
    SDL_DestroyTexture(downTexture);
}

void Button::handleEvent(SDL_Event& event)
{
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        bool isInside = mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w &&
            mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h;

        if (!isPressed)
        {
            if (isInside)
            {
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    currentState = ButtonState::Down;
                    isPressed = true;
                }
                else
                {
                    currentState = ButtonState::Over;
                }
            }
            else
            {
                currentState = ButtonState::Up;
            }
        }
        else
        {
            if (event.type == SDL_MOUSEBUTTONUP)
            {
                isPressed = false;
                if (isInside)
                {
                    currentState = ButtonState::Over;
                }
                else
                {
                    currentState = ButtonState::Up;
                }
            }
        }
    }
}

void Button::render()
{
    switch (currentState)
    {
    case ButtonState::Up:
        SDL_RenderCopy(renderer, upTexture, nullptr, &buttonRect);
        break;
    case ButtonState::Over:
        SDL_RenderCopy(renderer, overTexture, nullptr, &buttonRect);
        break;
    case ButtonState::Down:
        SDL_RenderCopy(renderer, downTexture, nullptr, &buttonRect);
        break;
    }
}