/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/
// https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
// from 21_sound_effects_and_music.cpp


//Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>

#include <unistd.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;


bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {

        //Initialize SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            success = false;
        }
    }

    return success;
}

bool loadMedia() {
    //Loading success flag
    bool success = true;

    //Load music
    gMusic = Mix_LoadMUS("encoded.wav");
    if (gMusic == NULL) {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
//    gScratch = Mix_LoadWAV("scratch.wav");
//    if (gScratch == NULL) {
//        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        success = false;
//    }

    gHigh = Mix_LoadWAV("high.wav");
    if (gHigh == NULL) {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

//    gMedium = Mix_LoadWAV("medium.wav");
//    if (gMedium == NULL) {
//        printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        success = false;
//    }

//    gLow = Mix_LoadWAV("low.wav");
//    if (gLow == NULL) {
//        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        success = false;
//    }

    return success;
}

void close() {
    //Free the sound effects
    Mix_FreeChunk(gScratch);
    Mix_FreeChunk(gHigh);
    Mix_FreeChunk(gMedium);
    Mix_FreeChunk(gLow);
    gScratch = NULL;
    gHigh = NULL;
    gMedium = NULL;
    gLow = NULL;

    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

//EMSCRIPTEN_KEEPALIVE
//int play_music(int argc, char *args[]) {
int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {

            Mix_PlayChannel(-1, gHigh, 0);

            usleep(500000);

            Mix_PlayMusic(gMusic, -1);

//            //Main loop flag
//            bool quit = false;
//
//            //Event handler
//            SDL_Event e;
//
//            //While application is running
//            while (!quit) {
//                //Handle events on queue
//                while (SDL_PollEvent(&e) != 0) {
//                    //User requests quit
//                    if (e.type == SDL_QUIT) {
//                        quit = true;
//                    }
//                        //Handle key press
//                    else if (e.type == SDL_KEYDOWN) {
//                        switch (e.key.keysym.sym) {
//                            //Play high sound effect
//                            case SDLK_1:
//                                Mix_PlayChannel(-1, gHigh, 0);
//                                break;
//
//                                //Play medium sound effect
//                            case SDLK_2:
//                                Mix_PlayChannel(-1, gMedium, 0);
//                                break;
//
//                                //Play low sound effect
//                            case SDLK_3:
//                                Mix_PlayChannel(-1, gLow, 0);
//                                break;
//
//                                //Play scratch sound effect
//                            case SDLK_4:
//                                Mix_PlayChannel(-1, gScratch, 0);
//                                break;
//
//                            case SDLK_9:
//                                //If there is no music playing
//                                if (Mix_PlayingMusic() == 0) {
//                                    //Play the music
//                                    Mix_PlayMusic(gMusic, -1);
//                                }
//                                    //If music is being played
//                                else {
//                                    //If the music is paused
//                                    if (Mix_PausedMusic() == 1) {
//                                        //Resume the music
//                                        Mix_ResumeMusic();
//                                    }
//                                        //If the music is playing
//                                    else {
//                                        //Pause the music
//                                        Mix_PauseMusic();
//                                    }
//                                }
//                                break;
//
//                            case SDLK_0:
//                                //Stop the music
//                                Mix_HaltMusic();
//                                break;
//                        }
//                    }
//                }
//
//            }
        }
    }

    usleep(3000000);

    //Free resources and close SDL
    close();

    return 0;
}
