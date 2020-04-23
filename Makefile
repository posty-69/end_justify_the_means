main:enigme.o main.o
	gcc enigme.o main.o -o main -lSDL -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c
enigme.o:enigme.c
	gcc -c enigme.c
