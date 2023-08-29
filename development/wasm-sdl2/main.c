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

    Mix_Music *music = NULL;
    Mix_Chunk *wave = NULL;

    SDL_Init(SDL_INIT_AUDIO);

    int audio_rate = 44100;
    Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
    int audio_channels = 1;
    int audio_buffers = 4096;

    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) < 0) {
        printf("Unable to open audio!\n");
        exit(1);
    }

    if(Mix_Init(MIX_INIT_MOD) != MIX_INIT_MOD)
        printf("errer\n");

    Mix_Volume(-1, MIX_MAX_VOLUME);

    music = Mix_LoadMUS("encoded.wav");
    wave = Mix_LoadWAV("encoded.wav");

    if (music == NULL) {
        printf("Could not load encoded.wav\n\n");
        printf("%s\n", Mix_GetError());
    }

    if (wave == NULL) {
        printf("Could not load encoded.wav\n\n");
        printf("%s\n", Mix_GetError());
    }

    Mix_VolumeChunk(wave, MIX_MAX_VOLUME);
    Mix_VolumeMusic(MIX_MAX_VOLUME);

    Mix_PlayMusic(music, 0);
    printf("%s\n", Mix_GetError());
    Mix_FadeInChannelTimed(-1, wave, 0, 100,1);
    printf("%s\n", Mix_GetError());

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
