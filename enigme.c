#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enigme.h"

void init_enigme(enigme e[],int n)
{
char Q[10], R1[10];
int i=0;
FILE *f=NULL;
f=fopen("fichier_enigme.txt","r");
while(fscanf(f,"%s %s %d",Q,R1,&e[i].numR)!=EOF)

{
e[i].Quest=IMG_Load(Q);
e[i].Ans=IMG_Load(R1);
e[i].Fail=IMG_Load("f.png");
e[i].Succ=IMG_Load("v.png");
printf("%s %s %d\n",Q,R1,e[i].numR);
i++;
}

fclose(f);

for(i=0;i<n;i++)
{
e[i].PosQ.x=300; 
e[i].PosQ.y=300; 

e[i].PosA.x=300;  
e[i].PosA.y=482; 


e[i].PosF.x=300;  
e[i].PosF.y=300;  

e[i].PosS.x=300;  
e[i].PosS.y=300; 
}
}
int generation_enigme(enigme e[],int tabV[])
{
srand(time(NULL));
int i;
i= rand()%7+1 ;

return i;

}


int resolutionauto( enigme e[],int choix,int i)
{

if (choix==e[i].numR)
return 1;
else 
return 0;
}
int afficher_enigme(enigme e[],int i,SDL_Surface *ecran)
{

SDL_BlitSurface(e[i].Quest,NULL,ecran,&e[i].PosQ);
SDL_BlitSurface(e[i].Ans,NULL,ecran,&e[i].PosA);

return i;

}
void resolution(enigme e[],int tabV[],SDL_Surface *ecran,int i)
{
int choix,j,continuer=1;
SDL_Event event;
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
	case SDLK_KP1:
/*******************/
	choix=1;
 	break;
	case SDLK_KP2 :
	choix=2;
	break;
	case SDLK_KP3:
	choix=3;
	break;
	}

	j=resolutionauto(e,choix,i);
	if (j==0)
	{
	SDL_BlitSurface(e[i].Fail,NULL,ecran,&e[i].PosF);
	
}
	else  
	{SDL_BlitSurface(e[i].Succ,NULL,ecran,&e[i].PosS);
	
	
}
// niveau de vie diminue ou augmente(gestion du score)
}

}
void initTabv(int tabV[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		tabV[i]=0;
	}
}
