#!/usr/bin/env sh

#emcc main.c -s USE_SDL=2 -o index.html
#emcc main.c -s USE_SDL=2 -o index.js

emcc main.c -o index.js -s USE_SDL=2 -s USE_SDL_MIXER=2 -s EXPORTED_RUNTIME_METHODS='["ccall"]'


