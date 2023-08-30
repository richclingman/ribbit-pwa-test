#!/usr/bin/env sh

#emcc main.c -o index.html -s USE_SDL=2 -s USE_SDL_MIXER=2 --preload-file path_to_your_music_file.mp3


#emcc simple_music_wasm.cpp -o index.html -s USE_SDL=2 -s USE_SDL_MIXER=2 --preload-file encoded.wav -s EXPORTED_RUNTIME_METHODS='["ccall"]'
#emcc simple_music_wasm.cpp -o index.js -s USE_SDL=1 -s USE_SDL_MIXER=1 --use-preload-plugins --preload-file encoded.wav --preload-file high.wav -s EXPORTED_RUNTIME_METHODS='["ccall"]'
emcc simple_music_wasm.cpp -o index.js --use-preload-plugins --preload-file encoded.wav --preload-file high.wav -s EXPORTED_RUNTIME_METHODS='["ccall"]'

