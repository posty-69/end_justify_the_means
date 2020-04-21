#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
//void pause();
typedef struct enigme
{
SDL_Surface *fond;
SDL_Rect position;
}enigme;
void Initenigme(enigme *e)
{
e->fond=IMG_Load("enigme1.png");
e->position.x=0;
e->position.y=0;
}
void afficher(enigme e,SDL_Surface *ecran )
{ SDL_BlitSurface(e.fond,NULL,ecran,&e.position);
	SDL_Delay(40);
}
int main()
{ 
	    srand(time(NULL));
    int reponse=0,a=5,i=0,b=50,e1,e2,e3,c=1,d=40,nombre,reponses;
enigme e;

char let='&';
    int continuer;
    SDL_Event event;
char che1[4],che2[4],che3[255];
SDL_Surface *text1,*ecran=NULL,*text2=NULL,*text3=NULL,*text4=NULL; 
    TTF_Font *police = NULL ;
SDL_Rect positiontext,positiontext1,positiontext2,positiontext4;
 SDL_Color couleurNoire = {0, 0, 0} ;
SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
 positiontext.x=420;
    positiontext.y=150;
 positiontext1.x=350;
    positiontext1.y=230;
positiontext2.x=300;
    positiontext2.y=300;
    positiontext4.x=0;
    positiontext4.x=0;

ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|  SDL_RESIZABLE );

SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
Initenigme(&e);
    do{
	e1=rand()%100+3;
	}while(e1%3!=0);
nombre=e1/3;
sprintf(che1, "%d", e1);
    e2=rand()%(d-c)+c;
    
	reponses=e2-nombre;
printf("%d\n",e2);
sprintf(che2, "%d", e2);


//pause();
 while (continuer)
    {
        while(SDL_PollEvent(&event))
        switch(event.type)
        {
              
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_MOUSEBUTTONUP:  
        break;
        case SDL_KEYDOWN:
            
        {            
    switch(event.key.keysym.sym)
    {                     
	case SDLK_KP0:
	let='0';
	break;
	case SDLK_KP1:
	let='1';
	break;
	case SDLK_KP2:
	let='2';
	break;
	case SDLK_KP3:
	let='3';
                             
	case SDLK_KP4:
	let='4';
	break;
	case SDLK_KP5:
	let='5';
	break;
	case SDLK_KP6:
	let='6';
	break;
	case SDLK_KP7:
	let='7';
    case SDLK_KP8:
        let='8';
    case SDLK_KP9:
        let='9';
        
    }}}
            
        
//che[4]=e1;
    afficher(e,ecran);
   police = TTF_OpenFont("fente.ttf", 55);
    text1 = TTF_RenderText_Blended(police,che1, couleurNoire);
    SDL_BlitSurface(text1, NULL,ecran,&positiontext);
    //printf("x + y = %d \n",e1+e2);
   text2 = TTF_RenderText_Blended(police, che2, couleurNoire);
   SDL_BlitSurface(text2, NULL,ecran,&positiontext1);
   SDL_Flip(ecran);

  
  do
    {

        printf("y = ");
        scanf("%d",&e3);
if(e3==reponses){
sprintf(che3, "%d vous avez gagne",e3);

}
else{
sprintf(che3, "%d vous avez rater",e3);
}
 text3 = TTF_RenderText_Blended(police,che3, couleurNoire);
  SDL_BlitSurface(text3, NULL,ecran,&positiontext2);
        i++;


SDL_Flip(ecran);
text3=NULL;
SDL_FreeSurface(text3);
    }
    while(e3!=e2 &&  i!=3);
if (e1==e3)
{reponse=1;
SDL_Flip(ecran);
}else 
{sprintf(che3, "%d",e2);
text3 = TTF_RenderText_Blended(police, che3, couleurNoire);  
SDL_BlitSurface(text3, NULL,ecran,&positiontext2);
SDL_Flip(ecran);
reponse=0; }
TTF_CloseFont(police);
   TTF_Quit();
SDL_FreeSurface(text1);
SDL_FreeSurface(text2);
SDL_FreeSurface(text3);
SDL_FreeSurface(ecran);

   SDL_Quit();
}}
/*
void pause()
{
    
        }}*/
