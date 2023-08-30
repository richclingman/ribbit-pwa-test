/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/
// https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
// from 21_sound_effects_and_music.cpp


#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif


//Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>

#include <string.h>

#include <unistd.h>

#include "emscripten.h"


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gHigh = NULL;


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
    gMusic = Mix_LoadMUS("/encoded.wav");
//    gMusic = Mix_LoadMUS_RW(SDL_RWFromFile("encoded.wav", "rb"), 1);
    if (gMusic == NULL) {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
    gHigh = Mix_LoadWAV("/high.wav");
//    gMusic = Mix_LoadMUS_RW(SDL_RWFromFile("high.wav", "rb"), 1);
    if (gHigh == NULL) {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void close() {
    //Free the sound effects
    Mix_FreeChunk(gHigh);
    gHigh = NULL;

    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

EXTERN EMSCRIPTEN_KEEPALIVE
int play_sound(int argc, char *args[]) {
//int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {

//            Mix_Volume(-1, MIX_MAX_VOLUME); // doesn't help
//            Mix_VolumeChunk(gHigh, MIX_MAX_VOLUME); // doesn't help
//            Mix_VolumeMusic(MIX_MAX_VOLUME); // doesn't help
//            Mix_MasterVolume(MIX_MAX_VOLUME); // does not exist (but in docs)



            // "CHUNK" STILL DOES NOT PLAY
            printf("Play gHigh\n");

            Mix_PlayChannel(-1, gHigh, 0);

            usleep(5000000);


            // "MUSIC" *DOES* PLAY
            printf("Play gMusic\n");

            Mix_PlayMusic(gMusic, -1);
        }
    }

    printf("Waiting\n");

    usleep(3000000);

    printf("Close\n");

    //Free resources and close SDL
    close();

    return 0;
}
