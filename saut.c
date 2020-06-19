#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main ( int argc, char** argv )
{
    //Init de la SDL
    SDL_Init( SDL_INIT_VIDEO );

    // On crée une fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE);
    // On charge le fond
    SDL_Surface* fond = IMG_Load("bg.png");

    //On charge Mario
    SDL_Surface* mario = IMG_Load("detective.png");

    // La position du fond
    SDL_Rect posFond;
    posFond.x = 0;
    posFond.y = 0;

    // La position de Mario
    SDL_Rect posMario;
    posMario.x = 100;
    posMario.y =300-(mario->h);

    // Les variables de la troisieme methode
   // double v_x = 1.5;

    double v_grav = 0.08;
    double v_saut = -4;

    double v_y = v_saut;

    // Boucle principale
    int fin = 0;
    while (!fin)
    {
        // Gestion des evenements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                fin = 1;
                break;

            case SDL_KEYDOWN:
                {
                    
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        fin = 1;
		    if (event.key.keysym.sym == SDLK_SPACE)
			v_y=v_saut;
                    break;
                }
            }
        }

        // EVOLUTION

            // Evolution des positions : vive la rigueur !
            //posMario.x += v_x;
            posMario.y += v_y;

            // evolution de la vitesse verticale
            v_y += v_grav;

	    // POINT A
		if (posMario.y > 320)
	v_y = 0;

        // FIN EVOLUTION

        // DESSIN

        // Effacement de l'ecran
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        // Dessin des images
        SDL_BlitSurface(fond, 0, ecran, &posFond);
        SDL_BlitSurface(mario, 0, ecran, &posMario);

        // FIN DESSIN

        
        SDL_Flip(ecran);
    }

    
    SDL_FreeSurface(fond);
    SDL_FreeSurface(mario);

    SDL_Quit();

    return 0;
}
