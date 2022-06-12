#pragma once
#ifndef PROGRAM
#define PROGRAM

#include "SDL2/SDL.h"
#undef main

#include <glad/glad.h>

class Program {
public:
    // constructor
    Program(int w, int h);
    // destructor
    ~Program();

    // Update CPU side data per frame
    void Update();
    // Render images per frame
    void Render();
    // Infinite loop for running game logic until terminated
    void Loop();
    // Get the Pointer for the window
    SDL_Window* GetSDLWindow();
private:
    int width;
    int height;

    SDL_Window* window;
    SDL_GLContext openGLContext;

    bool InitGL();

};


#endif