#ifndef ENIGME_H_
#define ENIGME_H_

typedef struct enigme
{
int nb_essai;
SDL_Surface *Quest, *Ans, *Fail, *Succ;
SDL_Rect PosQ, PosA, PosF, PosS;
int numR;
}enigme;
void initTabv(int tabV[],int n);
void resolution(enigme e[],int tabV[],SDL_Surface *ecran,int i);
int afficher_enigme(enigme e[],int i,SDL_Surface *ecran);
int resolutionauto( enigme e[],int choix,int i);
int generation_enigme(enigme e[],int tabV[]);
void init_enigme(enigme e[],int n);

#endif /*ENIGME_H_*/
