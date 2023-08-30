/**
* From chat.openai.com example
*/

#include <SDL2/SDL.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 28000
#define FREQUENCY 440

// Audio callback function
void audioCallback(void* userdata, Uint8* stream, int len) {
    for (int i = 0; i < len; i += 2) {
        double time = (double)(SDL_GetTicks()) / 1000.0;
        Sint16 sample = (Sint16)(AMPLITUDE * sin(2.0 * M_PI * FREQUENCY * time));

        stream[i] = sample & 0xFF;
        stream[i + 1] = (sample >> 8) & 0xFF;
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec spec;
    spec.freq = SAMPLE_RATE;
    spec.format = AUDIO_S16;
    spec.channels = 1;
    spec.samples = 2048;
    spec.callback = audioCallback;

    SDL_OpenAudio(&spec, NULL);

    SDL_PauseAudio(0);

    // Main loop
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_CloseAudio();
    SDL_Quit();
    return 0;
}
