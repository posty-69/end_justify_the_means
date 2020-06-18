#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include"SDL/SDL_image.h"

int main (void)
{


Uint8 *keystate = SDL_GetKeyState(NULL);

// int background...
SDL_Surface *background=NULL;
SDL_Surface *image=NULL;
SDL_Rect posbackground;

int counter;
int j;
float tab[7];


if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initilize SDL:%s\n",SDL_GetError());
        return 1;
    }
    background=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE);
    if(background==NULL)
    {
        printf("unable to set video mode: %s\n",SDL_GetError());
    }
image=IMG_Load("background.png");
    if(image==NULL)
    {
        printf("unable to set background: %s\n",SDL_GetError());
        return 1;
    }
    posbackground.x=0;
    posbackground.y=0;
    posbackground.w=image->w;
    posbackground.h=image->h;



// int player 
SDL_Surface *MPlayer=NULL;
SDL_Rect posMP;
SDL_Rect psize;



MPlayer=IMG_Load("playerssheet.png");
    if(MPlayer==NULL)
    {
        printf("unable to load playerssheet.png: %s\n",SDL_GetError());
        return 1;
    }


for(int i=0; i<8;i++)
tab[i]=(MPlayer->w/8)*i;

    posMP.x=0;
    posMP.y=0;
    posMP.w=MPlayer->w/8;
    posMP.h=MPlayer->h;


counter=0;




    psize.w=MPlayer->w/8;
    psize.h=MPlayer->h/8;
    psize.x=(MPlayer->w/8)*counter;
    psize.y=0;




// affichage 
SDL_Event event;
int keep=1;
while (keep)
{
SDL_BlitSurface(image,NULL,background,NULL);
SDL_BlitSurface(MPlayer,&psize,background,&posMP);

// quit key
while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
            {
                keep=0;
                break;
            }
           
        case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                    keep=0;
                }

//movement
                else if(event.key.keysym.sym==SDLK_d)
                {
                
     posMP.x+=10;
            
                }
else if(event.key.keysym.sym==SDLK_q)
                {
                
     posMP.x-=10;
            
                }
else if(event.key.keysym.sym==SDLK_z)
                {
                
     posMP.y-=10;
            
                }
else if(event.key.keysym.sym==SDLK_s)
                {
                
     posMP.y+=10;
            
                }

    


}
}
}

if(keystate[SDLK_LEFT])
    {

/* Left side animation */ 
psize.y=(MPlayer->h/8);
if (psize.x==(MPlayer->w/8)*7)
   psize.x=(MPlayer->w/8)*6;
else if (psize.x==(MPlayer->w/8)*6)
   psize.x=((MPlayer->w/8)*5);
else if (psize.x==(MPlayer->w/8)*5)
   psize.x=(MPlayer->w/8)*4;
else if (psize.x==(MPlayer->w/8)*4)
   psize.x=((MPlayer->w/8)*3)+5; 
else if (psize.x==((MPlayer->w/8)*3)+5)
   psize.x=((MPlayer->w/8)*2)+10;
else if (psize.x==((MPlayer->w/8)*2)+10)
   psize.x=((MPlayer->w/8)*1)+3;
else if (psize.x==((MPlayer->w/8)*1)+3)
   psize.x=0;
else if (psize.x==0)
psize.x=(MPlayer->w/8)*7;



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

posMP.x-=20;
if (keystate[SDLK_LSHIFT])
{
posMP.x-=30;
}
    }
    if(keystate[SDLK_RIGHT])

    {
/* Right side animation*/

psize.y=0;
 if (psize.x==(MPlayer->w/8)*0)
   psize.x=((MPlayer->w/8)*1)+3;
else if (psize.x==((MPlayer->w/8)*1)+3)
   psize.x=((MPlayer->w/8)*2)+10;
else if (psize.x==((MPlayer->w/8)*2)+10)
   psize.x=((MPlayer->w/8)*3)+5;
else if (psize.x==((MPlayer->w/8)*3)+5)
   psize.x=(MPlayer->w/8)*4; 
else if (psize.x==(MPlayer->w/8)*4)
   psize.x=(MPlayer->w/8)*5;
else if (psize.x==(MPlayer->w/8)*5)
   psize.x=(MPlayer->w/8)*6;
else if (psize.x==(MPlayer->w/8)*6)
   psize.x=(MPlayer->w/8)*7;
else if (psize.x==(MPlayer->w/8)*7)
psize.x=0;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


 
posMP.x+=20;
if (keystate[SDLK_LSHIFT])
{
posMP.x+=30;
}


    }


SDL_Flip(background);

}

SDL_FreeSurface(background);
    SDL_Quit();








return 0;
 }
