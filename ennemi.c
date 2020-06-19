#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"ennemi.h"


void Clochard_Init(ennemi *c, int x, int y){
	c->sprite = IMG_Load("ennemi.png");
	c->sprite2 = IMG_Load("ennemi2.png");
	c->x = x;
	c->y = y;
	c->dx = 0;
	c->cx = 0;
}

void Clochard_Render(ennemi *c, SDL_Surface **screen){
	SDL_Rect r2 = {c->x, c->y};
	if(c->dx){
		c->x += 5;                
		SDL_BlitSurface(c->sprite2,NULL,*screen, &r2);
	}else{
		SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
		c->x -= 5;
	}

	c->cx++;
	if(c->cx % 30 == 0)
		c->dx = !c->dx;


}
