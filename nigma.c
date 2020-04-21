#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"


int main(int argc, char *argv[])
{
    SDL_Surface *ecran=NULL;
	SDL_Rect position,clipper;
	int continuer=1,tabV[6],quest=1;
	SDL_Event event;
	enigme e[6];
	init_enigme(e,6);
	initTabv(tabV,6);
    SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(2000, 1000 , 32, SDL_HWSURFACE|SDL_RESIZABLE);
	int i=generation_enigme(e,tabV);
	fprintf(stderr,"________________%d",i);
while(continuer)
{
afficher_enigme(e,i,ecran);

	SDL_WaitEvent(&event);
       switch(event.type)
	{
		case SDL_QUIT:
		 continuer=0;
		break;

case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
		case SDLK_ESCAPE:
		continuer=0;
		break;
	}
	break;
}

afficher_enigme(e,i,ecran);
resolution(e,tabV,ecran,i);
		
	
	SDL_Flip(ecran);

}
 
SDL_Quit();
  return EXIT_SUCCESS;
}

