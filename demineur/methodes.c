#include "define.h"

///////////////////initialisation

extern void init(int *casesDispo, int *casesVides, int *perdu){

    *casesDispo = DIMENSIONS*DIMENSIONS - NBMINES;

    *casesVides = 1;

    *perdu = 0;
}

extern void init_Tab(int tabInit[DIMENSIONS][DIMENSIONS]){
    int xTab=0, yTab=0;

    for (yTab=0; yTab<DIMENSIONS; yTab++){
        for (xTab=0; xTab<DIMENSIONS; xTab++){

            tabInit[yTab][xTab] = -1;
        }
    }
}

///////////////////introduction

extern void intro(int tabMines[DIMENSIONS][DIMENSIONS]){
    int xColonne=0, yLigne=0;

    printf("Un tableau de %dx%d cellules contient un total de %d mines.\n", DIMENSIONS, DIMENSIONS, NBMINES);
    printf("Essayer de devoiler toutes les cases sures, en evitant les mines !\n");
    printf("Pour commencer, choisissez les coordonner de la premiere case a devoiler.\nNe vous inquitez pas, ce ne sera pas une mine !\n");

    lecture(&xColonne, &yLigne);

    tabMines[yLigne][xColonne]=0;

    srand(time(NULL));
    generMines(tabMines);

    rapport(xColonne, yLigne, tabMines);
}

extern void generMines(int tabMines[DIMENSIONS][DIMENSIONS]){
    int xRand=0, yRand=0;
    int resteMine = NBMINES;

    while (resteMine > 0) {
        xRand = rand()%DIMENSIONS;
        yRand = rand()%DIMENSIONS;

        if (tabMines[yRand][xRand] == -1){
            tabMines[yRand][xRand] = 1;
            resteMine--;

            printf("%d,%d - \n", xRand+1, yRand+1);
        }
    }
}

///////////////////methodes reutilisables

extern void lecture(int *xColonne, int *yLigne){
    char repereColonne[]="Colonne";
    char repereLigne[]="Ligne";

    printf("Entrez des coordonees :\n");

    *xColonne = verification(repereColonne) - 1;
    *yLigne = verification(repereLigne) - 1;
}

extern int verification(char repere[]){
    int coordTemp=0;

    fflush(stdin);
    printf("%s : ", repere); scanf("%d", &coordTemp);

    while ((coordTemp<1) || (coordTemp>DIMENSIONS)) {

        printf("Veuillez saisir une valeur comprise entre 1 et %d !\n", DIMENSIONS);

        fflush(stdin);
        printf("%s : ", repere); scanf("%d", &coordTemp);
    }

    return coordTemp;
}


extern void rapport(int xColonne, int yLigne, int tabMines[DIMENSIONS][DIMENSIONS]){
    int comptMines=0;

    if (tabMines[yLigne-1][xColonne-1] == 1){
        comptMines++;
    }
    if (tabMines[yLigne][xColonne-1] == 1){
        comptMines++;
    }
    if (tabMines[yLigne+1][xColonne-1] == 1){
        comptMines++;
    }
    if (tabMines[yLigne-1][xColonne] == 1){
        comptMines++;
    }
    if (tabMines[yLigne-1][xColonne+1] == 1){
        comptMines++;
    }
    if (tabMines[yLigne][xColonne+1] == 1){
        comptMines++;
    }
    if (tabMines[yLigne+1][xColonne] == 1){
        comptMines++;
    }
    if (tabMines[yLigne+1][xColonne+1] == 1){
        comptMines++;
    }

    printf("Il y a %d mine(s) autour de la cellule %d-%d.\n", comptMines, (xColonne+1), (yLigne+1));
}

///////////////////////////////////////

extern void partie(int tabMines[DIMENSIONS][DIMENSIONS], int *casesVides, int *perdu){
    int xColonne=0, yLigne=0;

    lecture(&xColonne, &yLigne);

    if (tabMines[yLigne][xColonne] == 0){

        printf("Vous avez deja verifie cette case. ");
        rapport(xColonne, yLigne, tabMines);
    }
    else if (tabMines[yLigne][xColonne] == -1){

        rapport(xColonne, yLigne, tabMines);

        (*casesVides)++;
    }
    else if (tabMines[yLigne][xColonne] == 1){

        *perdu = 1;
    }
}


extern void defaite(int perdu){

    if (perdu == 1){

        printf("Oh non, c'etait une mine ! PERDU !!");
    }
}

extern void victoire(int casesVides, int casesDispo){

    if (casesVides == (casesDispo)){

        printf("Bravo, vous avez demine le plateau !");
    }
}
