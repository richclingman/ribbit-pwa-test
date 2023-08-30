# Finally Got Some Sound

After **many** tests and iterations, I finally got WASM/SDL to produce sound
using **simple_music_wasm** which was derived from 
21_sound_effects_and_music.

*The "chunk" (high.wav) sound still is not playing.*

## The Minimum build.sh

```shell
#!/usr/bin/env sh

emcc simple_music_wasm.cpp -o index.js --use-preload-plugins --preload-file encoded.wav --preload-file high.wav -s EXPORTED_RUNTIME_METHODS='["ccall"]'
```

## Repeated Command Line

Using this to build and run Python3 http server:

```shell
clear && ./build.sh && python3 -m http.server
```

**Note:** The server *does* provide caching which is a problem.
In browser, use "Empty cache and force reload" (right-click reload button).

## Helpful Hint

https://github.com/AlbertVeli/wasm_sdl2_test/tree/master

This was not helpful, and could not get his example code to build.
(The preloaded files were still not available.)

>  I only got file loading to work together with emscripten by adding 
  --preload-file to CFLAGS. This in turn only works with the _RW 
  versions of the load files. Like 
  ```Mix_LoadWAV_RW(SDL_RWFromFile("assets/bounce.ogg", "rb"), 1);```

*However,* he also included this note:

* Audio API - Emscripten only supports SDL_mixer 1. Can be used together with SDL2.

I could **not** get Mixer1 to build with SDL2. 
However, I **did** get it building with Mixer1 and SDL1.

## The Other Required Hint

https://stackoverflow.com/questions/33941083/cannot-find-preloaded-image-emscripten

* SDL_image requires --use-preload-plugins or -s STB_IMAGE=1, etc.

We're using audio, not images; however, ```--use-preload-plugins```
**did** make it all work.

## Not Needed for "1"

I found that, while "2" is required for SDL2, the build
command does not need...

```shell
 -s USE_SDL=1 -s USE_SDL_MIXER=1
```

## Set Chrome to Allow Play

Browsers are set to **not** allow audio to auto-play on page load.
This is because of abusive ads and sites over the years.

However, when developing, it can be nice to have audio play on page load.

Here's how to set Chrome to allow auto-play of audio.

* Go to 
[chrome://settings/content/sound?search=play](chrome://settings/content/sound?search=play)

* Under ```Sound | Allowed to play sound```
* Add ```http://localhost```

