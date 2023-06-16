#include"Game.h"


//------------------------------------------------IMAGES------------------------------------------------
SDL_Texture* Game::loadImage(const string& filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

//------------------------------------------------SOUNDS------------------------------------------------
// Load a music file and return a Mix_Music*
Mix_Music* Game::loadMusic(const string& filename)
{
    Mix_Music* music = Mix_LoadMUS(filename.c_str());
    if (music == nullptr)
    {
        cerr << "Failed to load music: " << Mix_GetError() << endl;
        return nullptr;
    }
    return music;
}

// Load a sound effect file and return a Mix_Chunk*
Mix_Chunk* Game::loadSoundEffect(const string& filename)
{
    Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
    if (chunk == nullptr)
    {
        cerr << "Failed to load sound effect: " << Mix_GetError() << endl;
        return nullptr;
    }
    return chunk;
}
