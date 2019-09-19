//An SDL program that displays pup dog
//      -- from _C++ for Lazy Programmers_

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

int main(int argc, char** argv)
{
    //initialization

    enum { DEFAULT_WIDTH = 640, DEFAULT_HEIGHT = 480 };
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return -1;

    SDL_Window* sdlWindow
        = SDL_CreateWindow("My SDL program!",
                           SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           DEFAULT_WIDTH, DEFAULT_HEIGHT,
                           0); //flags are 0 by default
    if (!sdlWindow) return -1; //nope, it failed

    //defaults below:  
    // rendererIndex shd be -1 (pick first renderer that works best)
    // rendererFlags should be 0
    int rendererIndex = -1;
    int rendererFlags = 0;
    SDL_Renderer* sdlRenderer
        = SDL_CreateRenderer(sdlWindow, rendererIndex,
                             rendererFlags);

    if (!sdlRenderer) return -1;//nope, it failed

    SDL_ClearError();           //Initially, no errors

    static const int IMG_FLAGS  //all available types
        = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
    if (!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))  //start SDL_Image
        return -1;

    if (TTF_Init() == -1) return -1;         //...and SDL_TTF

                                             //...and SDL_Mixer
    int soundInitialized = (Mix_OpenAudio(88020, MIX_DEFAULT_FORMAT,
                                          MIX_DEFAULT_CHANNELS, 4096) != -1);
    if (!soundInitialized) SDL_ClearError();
            //if it failed, we can still do the program 
            //  -- just forget error


    //Draw an image

    SDL_Surface* sdlSurface = IMG_Load("media/pupdog.png");
    if (!sdlSurface) return -1;

    SDL_Texture* image = SDL_CreateTextureFromSurface
        (sdlRenderer, sdlSurface);
    if (!image) return -1;
    SDL_FreeSurface(sdlSurface);

    SDL_Rect dst;                 //dst is where it's going on screen
    dst.x = 0; dst.y = 0;

    SDL_QueryTexture(image, nullptr, nullptr, &dst.w, &dst.h);
                                  //get width and height of image
    SDL_RenderCopy(sdlRenderer, image, nullptr, &dst);


    //Waiting for a key

    SDL_Event sdlEvent;

    SDL_RenderPresent(sdlRenderer);       //display everything

    bool isTimeToQuit = false;
    while (!isTimeToQuit)
    {
        if (SDL_WaitEvent(&sdlEvent) == 0) return -1;

                                         //handle quit messages
        if (sdlEvent.type == SDL_QUIT) isTimeToQuit = true;
        if (sdlEvent.type == SDL_KEYDOWN
            && sdlEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            isTimeToQuit = true;

        if (sdlEvent.type == SDL_KEYDOWN) //Got that key? break
            break;                        // (break, not return!)
    }

    
    //cleanup
    //If sound system started, close it
    if (soundInitialized) { Mix_AllocateChannels(0); Mix_CloseAudio(); }
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();

    return 0;
}

