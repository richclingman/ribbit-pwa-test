#OBJS specifies which files to compile as part of the project
OBJS = 21_sound_effects_and_music.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#COMPILER_FLAGS = -w
#COMPILER_FLAGS = -v

#LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS = -lm -l./lib -lSDL2main -lSDL2 -lSDL2_mixer
LINKER_FLAGS = -L/usr/local/include/SDL2 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 21_sound_effects_and_music

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
