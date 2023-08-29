#


## Include mixer & image

```shell
apt-cache search libsdl2
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-mixer-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-gfx-dev
sudo apt-get install libsdl2-net-dev
```


## Include paths for SDL2

```shell
find / -type d -name "SDL" 2>/dev/null

find / -type f -name "SDL_mixer.h" 2>/dev/null
```

```text
/home/rich/emsdk/upstream/emscripten/system/lib/cmake/SDL2
/home/rich/emsdk/upstream/emscripten/cache/sysroot/include/SDL2
/home/rich/emsdk/upstream/emscripten/cache/sysroot/lib/cmake/SDL2
/mnt/c/development/emsdk/upstream/emscripten/cache/sysroot/lib/cmake/SDL2
/mnt/c/development/emsdk/upstream/emscripten/system/lib/cmake/SDL2
/usr/include/SDL2
/usr/include/x86_64-linux-gnu/SDL2
/usr/lib/x86_64-linux-gnu/cmake/SDL2
/usr/lib/x86_64-linux-gnu/installed-tests/SDL2
```

## XWindows

The examples use "image" and need XWindows installed.

https://askubuntu.com/questions/872792/what-is-xdg-runtime-dir

https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps



