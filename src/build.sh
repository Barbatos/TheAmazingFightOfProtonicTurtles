#!/bin/sh
# @Charles: fichier de compilation avec mingw32

gcc -o CourseDesTortues.exe main.c jeu.c menu.c utils.c -lmingw32 -lwinmm -lSDLmain -lSDL -lSDL_image -lSDL_ttf `sdl-config --cflags --libs` 

cp CourseDesTortues.exe ../build/
rm CourseDesTortues.exe
