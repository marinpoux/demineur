#include "define.h"

/*
PLAN:
    pour demineur debutant
1/ génération int tableauMines 9x9 rempli de -1
   génération char tableauAffiche 9x9 rempli de ' '
2/ demande au joueur de choisir une case
3/ remplissage aléatoire du tableauMines avec mines(9)
    --> compteur de mines : tant que mines>0 alors on recommence
    --> on peut mettre une mine SSI case == -1
4/ remplissage final du tableauMines
    --> pour chaque cellule !=9, valeur=nb de mines autour
    --> on obtient un tableau rempli de chiffres
5/ mise-à-jour case tableauAffiche
    --> tableauAffiche[case] = tableauMines[case]
    --> écrire combien il y a de mines autour de la case choisie
6/ demande au joueur de choisir la prochaine case ou il veut tester une mine
    --> tableauAffiche[case] = tableauMines[case] avec la case choisie
    --> si case=9 : perdu !

BUT : trouver toutes les cases sans mines (transformer toutes les cases -1 en 0)

OSEF les drapeaux v.v
*/

int main()
{
    //variables
    int casesDispo = DIMENSIONS*DIMENSIONS - NBMINES;
    int casesVides = 1;     // 1 pour la cellule de départ du joueur
    int perdu = 0;          // passe a 1 en case de défaite
    //ATTENTION !!
    //  --> lecture humaine : colonne-ligne (x-y)
    //  --> lecture de l'ordi : ligne-colonne (y-x)

    int tabMines[DIMENSIONS][DIMENSIONS];


    //initialisation

    init(&casesDispo, &casesVides, &perdu);
    init_Tab(tabMines);


    //introduction

    printf("DEMINEUR\n");

    intro(tabMines);

    //partie

    while ((casesVides < casesDispo) && (perdu != 1)) {

        printf("Il reste %d cellules a deminer !\n", (casesDispo-casesVides));

        partie(tabMines, &casesVides, &perdu);
    }

    defaite(perdu);

    victoire(casesVides, casesDispo);

    return 0;
}
