#pragma once

typedef struct ennemi {
	SDL_Surface *sprite,*sprite2;
	int x,y;
	int dx,cx;
} ennemi;

void Clochard_Init(ennemi *c, int x, int y);
void Clochard_Render(ennemi *c, SDL_Surface **screen);

