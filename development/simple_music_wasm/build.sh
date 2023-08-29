#!/usr/bin/env sh

#emcc main.c -o index.html -s USE_SDL=2 -s USE_SDL_MIXER=2 --preload-file path_to_your_music_file.mp3


emcc main.c -o index.html -s USE_SDL=2 -s USE_SDL_MIXER=2 --preload-file encoded.wav -s EXPORTED_RUNTIME_METHODS='["ccall"]'

