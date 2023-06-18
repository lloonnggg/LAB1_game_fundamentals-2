#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<ctime>
#include<Windows.h>
#include<iostream>
using namespace std;

static int ScreenWidth = 800;
static int ScreenHeight = 600;

SDL_Window* window = SDL_CreateWindow("Fundamental Lab", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);