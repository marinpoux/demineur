#include "define.h"

/*
PLAN:
    pour demineur debutant
1/ g�n�ration tableau 9x9 rempli de -1
2/ demande au joueur de choisir une case --> donner valeur 0
3/ remplissage al�atoire du tableau avec mines(1)
    --> compteur de mines : tant que mines>0 alors on recommence
    --> on peut mettre une mine SSI case == -1
4/ mise-�-jour case 0 --> indiquer ombien il y a de mines autour
5/ demande au joueur de choisir la prochaine case ou il veut tester une mine
6/ si case vide : indiquer combien de mines autour
   si mine : perdu !

BUT : trouver toutes les cases sans mines (transformer toutes les cases -1 en 0)

OSEF les drapeaux v.v
*/

int main()
{
    //variables
    int casesDispo = DIMENSIONS*DIMENSIONS - NBMINES;
    int casesVides = 1;     // 1 pour la cellule de d�part du joueur
    int perdu = 0;          // passe a 1 en case de d�faite
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
