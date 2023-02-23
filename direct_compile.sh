#!/usr/bin/env bash

gcc src/*.c -Wall -Werror -Wextra -pedantic $(sdl2-config --cflags --libs) \
-o 'The Maze Project'
# -lSDL2main -lSDL2
