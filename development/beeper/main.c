// https://stackoverflow.com/questions/10110905/simple-sound-wave-generator-with-sdl-in-c

#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <unistd.h>

#include "emscripten.h"

const int AMPLITUDE = 28000;
const int SAMPLE_RATE = 44100;

void audio_callback(void *user_data, Uint8 *raw_buffer, int bytes) {
    Sint16 *buffer = (Sint16 *) raw_buffer;
    int length = bytes / 2; // 2 bytes per sample for AUDIO_S16SYS
    int sample_nr = (*(int *) user_data);

    for (int i = 0; i < length; i++, sample_nr++) {
        double time = (double) sample_nr / (double) SAMPLE_RATE;
        buffer[i] = (Sint16)(AMPLITUDE * sin(2.0f * M_PI * 441.0f * time)); // render 441 HZ sine wave
    }
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE
int play_sound(int argc, char *args[]) {
//int main(int argc, char *argv[]) {
    printf("Starting.\n");

    if (SDL_Init(SDL_INIT_AUDIO) != 0) printf("Failed to initialize SDL\n");

    int sample_nr = 0;

    SDL_AudioSpec want;
    want.freq = SAMPLE_RATE; // number of samples per second
    want.format = AUDIO_S16SYS; // sample type (here: signed short i.e. 16 bit)
    want.channels = 1; // only one channel
    want.samples = 2048; // buffer-size
    want.callback = audio_callback; // function SDL calls periodically to refill the buffer
    want.userdata = &sample_nr; // counter, keeping track of current sample number

    SDL_AudioSpec have;
    if (SDL_OpenAudio(&want, &have) != 0) printf("Failed to open audio: ");
    if (want.format != have.format) printf("Failed to get the desired AudioSpec");

    SDL_PauseAudio(0); // start playing sound
    usleep(5000000); // wait while sound is playing
    SDL_PauseAudio(1); // stop playing sound

    SDL_CloseAudio();

    printf("DONE\n");

    return 0;
}
