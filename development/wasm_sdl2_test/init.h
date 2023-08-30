#ifndef __INIT_H
#define __INIT_H

/************************************************************
 *                                                        ***
 *   ~~=) All Rights Reversed - No Rights Reserved (=~~   ***
 *                                                        ***
 * Sweetmorn, the 40th day of Confusion in the YOLD 3184  ***
 *                                                        ***
 * Albert Veli                                            ***
 ************************************************************/

#include <emscripten.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#include "audio.h"

typedef struct {
   SDL_Window *window;
   SDL_Renderer *renderer;
   int audio_on;
   int quit;
} context;

extern context ctx;

void init(int w, int h);
void cleanup(void);

/**
 * Local Variables:
 * mode: c
 * indent-tabs-mode: nil
 * c-basic-offset: 3
 * End:
 */

#endif /* __INIT_H */
