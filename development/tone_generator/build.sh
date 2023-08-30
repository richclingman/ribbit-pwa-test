#!/usr/bin/env sh

emcc main.c -s USE_SDL=2 -o index.html
