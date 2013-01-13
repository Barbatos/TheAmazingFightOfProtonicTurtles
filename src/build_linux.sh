#!/bin/sh
#@Charles: compilation sous linux.. ihhhi

gcc -o CourseDesTortues.x86 main.c jeu.c menu.c utils.c -lSDLmain -lSDL -lSDL_image -lSDL_ttf `sdl-config --cflags --libs`

chmod +x CourseDesTortues.x86
cp CourseDesTortues.x86 ../build
rm CourseDesTortues.x86


