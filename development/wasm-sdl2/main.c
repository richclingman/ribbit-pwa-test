//
// Created by Rich on 8/28/2023.
//
// https://chat.openai.com/?model=text-davinci-002-render-sha
// https://www.aconvert.com/audio/

#include <SDL.h>

#include <SDL_mixer.h> // had to add this

#include "emscripten.h"
#include <stdio.h>
#include <unistd.h>

/**
 * TODO: Separate audio code into function
 *   Expose to enscripten
 *   Call from JS w/ button
 */

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EMSCRIPTEN_KEEPALIVE
int playSound(int argc, char* argv[]) {

    printf("\nStarting.\n");

    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    printf("\nStarting 1.\n");


    // Initialize audio subsystem
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        SDL_Log("Unable to initialize audio: %s", Mix_GetError());
        return 1;
    }

    printf("\nStarting 2.\n");

    // Load music file
    Mix_Music* music = Mix_LoadMUS("encoded.wav");
    if (!music) {
        SDL_Log("Unable to load music: %s", Mix_GetError());
        return 1;
    }

    printf("\nStarting 3.\n");

    Mix_VolumeMusic(MIX_MAX_VOLUME);

    // Play the loaded music
    if (Mix_PlayMusic(music, 1) == -1) {
        SDL_Log("Unable to play music: %s", Mix_GetError());
        return 1;
    }

    printf("\nStarting 4.\n");

    usleep(2000000);

    // Wait for user input or some time to hear the music
    SDL_Delay(2000); // Delay for 5 seconds

    printf("\nStarting 5.\n");

    // Free resources and quit
    Mix_CloseAudio();
    Mix_FreeMusic(music);
    SDL_Quit();
    return 0;
}



