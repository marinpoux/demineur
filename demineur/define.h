#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//constantes
#define NBMINES 5
#define DIMENSIONS 5

//prototype
extern void init(int *casesDispo, int *casesVides, int *perdu);
extern void init_Tab(int tabInit[DIMENSIONS][DIMENSIONS]);

extern void intro(int tabMines[DIMENSIONS][DIMENSIONS]);
extern void generMines(int tabMines[DIMENSIONS][DIMENSIONS]);

extern void lecture(int *xColonne, int *yLigne);
extern int verification(char repere[]);
extern void rapport(int xColonne, int yLigne, int tabMines[DIMENSIONS][DIMENSIONS]);

extern void partie(int tabMines[DIMENSIONS][DIMENSIONS], int *casesVides, int *perdu);
extern void defaite(int perdu);
extern void victoire(int casesVides, int casesDispo);

#endif // DEFINE_H_INCLUDED
