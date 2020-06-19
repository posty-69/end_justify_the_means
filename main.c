#include<SDL/SDL.h>
#include"ennemi.h"

int main(){
	SDL_Surface *screen;
	SDL_Event e;

	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

	ennemi c;
	Clochard_Init(&c,350,380);
	

	int running = 1;

	while(running){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
				running = 0;
			}
		}

		SDL_FillRect(screen,NULL,0x000000);

		Clochard_Render(&c,&screen);

		SDL_Delay(16);
		SDL_Flip(screen);
	}	
	SDL_Quit();
}
