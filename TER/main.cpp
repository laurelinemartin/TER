#include "include/Planification.h"
#include "include/Algo.h"
#include "include/Bus.h"
#include "include/IO.h"

using namespace std;
int TAILLE;
int NBCOLOR;
int HEUREMAX;
int NB_ITERATIONS;
float proba;

int main(int argc, char** argv)
{   
//// Ecriture Fichier
    initFichier();
    /*
    printf("entrez la probabilitée de lien entre 2 cours :\n");
    scanf("%f",&proba);
    printf("entrez le nombre de cours pour la planification:\n");
    scanf("%d",&TAILLE);
    printf("entrez le nombre de salles disponibles pour la planification:\n");
    scanf("%d", &NBCOLOR);
    printf("lancement de l'application avec une probabilitée de %f, %d cours et %d salles\n",proba, TAILLE, NBCOLOR);*/


/////////////////////////
//// Les variables : ////
/////////////////////////
    // proba = 0.4;
    // TAILLE = 40;
    // NBCOLOR = 75;
    // HEUREMAX = 34;
    // NB_ITERATIONS = 10;

    //// Lecture fichier
    proba = lectureProbabilite();
    TAILLE = lectureNombreCours();
    NBCOLOR = lectureNombreSalles();
    HEUREMAX = lectureNombreBus();
    NB_ITERATIONS = lectureNombreIterations();
/////////////////////////


//////////////////////////////////
//// La matrice d'adjacence : ////
//////////////////////////////////
    int **T = matrice_adjacence_GNO(TAILLE, proba);

    //// Ecriture terminal
    printf("\n MATRICE DU GNO \n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int j = 0; j < TAILLE; j++)
    {
        for (int i = 0; i < TAILLE; i++)
        {
            printf(" %d ",T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
//////////////////////////////////


//////////////////////////////
//// Coloration des cours ////
//////////////////////////////
    int *couleur = coloration (TAILLE, NBCOLOR);

    //// Ecriture terminal
    printf("COLORATION\n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int j = 0; j < TAILLE; j++)
    {
        printf(" %d ",couleur[j]);
    }
    printf("\n");
    printf("\n");
//////////////////////////////


/////////////////////////////
//// La matrice orientée ////
/////////////////////////////
    int **TO = matrice_graphe_oriente(T,TAILLE);

    //// Ecriture terminal
    printf("\n MATRICE DU GO \n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int j = 0; j < TAILLE; j++)
    {
        for (int i = 0; i < TAILLE; i++)
        {
            printf(" %d ",TO[i][j]);
        }
        printf("\n");
    }
    printf("\n");
/////////////////////////////


///////////////////////////////////////
//// Sommet de degré entrant nul : ////
///////////////////////////////////////
    int premier_sommet = 0;

    //// Ecriture terminal
    printf("PREMIER SOMMET DE DEGRE ENTRANT NUL\n");
    printf("Degré entrant nul : %d\n\n",premier_sommet);
///////////////////////////////////////


/////////////////////////////////////
//// Assignation type de cours : ////
/////////////////////////////////////
    int *TYPE = type_cours(TAILLE);

    //// Ecriture terminal
    printf("\n TYPE DE COURS ET NOMBRES D'ELEVES ASSOCIES\n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ",TYPE[i]);
    }
    printf("\n");
/////////////////////////////////////


/////////////////////////////////////////////////
//// Assignation nombre d'élèves par cours : ////
/////////////////////////////////////////////////
    int *NBELEVES = nb_eleves(TYPE, TAILLE);

    //// Ecriture terminal
    for (int i = 0; i < TAILLE; i++)
    {
        printf("%d ", NBELEVES[i]);
    }
    printf("\n");
/////////////////////////////////////////////////


//////////////////////////////////
//// Première planification : ////
//////////////////////////////////
    int *Horaires = planification(TO, premier_sommet, couleur, TAILLE, TYPE);
    int congestion_totale = calcul_congestion_totale(Horaires, NBELEVES, 34, TAILLE, TO);
    
    //// Ecriture fichier
    ecrireInformation("\n\n * Planification initiale : \n");
    ecrireSolution(Horaires, couleur, TAILLE, HEUREMAX, congestion_totale);
   // int* Bus = congestionBus(HEUREMAX, TAILLE, Horaires,NBELEVES);
    ecrireInformation("* Nombre d'élèves par bus pour la planification initiale");
    ecrireCongestionBus(nbElevesBus(Horaires, couleur, HEUREMAX, TAILLE), HEUREMAX);
    // ecrireCongestionBus(Bus, HEUREMAX);

    //// Ecriture terminal
    printf("\n PLANIFICATION \n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ", Horaires[i]);
    }
    printf("\n");
    printf("\n Calcul congestion \n");
    printf("----------------------------------------\n");
    printf("Congestion totale : %d\n",congestion_totale);
    printf("\n");

   
///////////////////////////////
//// Test de la solution : ////
///////////////////////////////
    bool a = test_solution_valide(Horaires,TAILLE,couleur,TYPE,TO);

    //// Ecriture Terminal
    printf("Solution planification initiale valide ? : %d\n",a); //true = 1 false = 0
///////////////////////////////
    
    if(a == 1)
        {

////////////////////////
//// Algo glouton : ////
////////////////////////
		int *Horaires_glouton = (int*)malloc(TAILLE*sizeof(int*));
        Horaires_glouton = Algo_glouton(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,HEUREMAX,NBELEVES);
        congestion_totale = calcul_congestion_totale(Horaires_glouton,NBELEVES,HEUREMAX,TAILLE,TO);
        a = test_solution_valide(Horaires_glouton,TAILLE,couleur,TYPE,TO);

        //// Ecriture fichier
        ecrireInformation("\n\n * Algo glouton :\n");
        ecrireSolution(Horaires_glouton, couleur, TAILLE, HEUREMAX, congestion_totale);
        ecrireInformation("* Nombre d'élèves par bus pour l'algo glouton");
        ecrireCongestionBus(nbElevesBus(Horaires_glouton, couleur, HEUREMAX, TAILLE), HEUREMAX);

        //// Ecriture terminal
        printf("\n Planification gloutonne \n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++){
            printf(" %d ", Horaires_glouton[i]);
        }
        printf("\n Calcul congestion gloutone \n");
        printf("----------------------------------------\n");
        printf("Congestion totale gloutone : %d\n", congestion_totale);
        printf("\n");
        printf("Solution gloutone valide ? : %d\n",a); //true = 1 false = 0
        free(Horaires_glouton);
////////////////////////


/////////////////////
//// Tabou dur : ////
/////////////////////
        int *Horaires_tabou_dur = Algo_tabou_dur(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,NB_ITERATIONS, HEUREMAX, NBELEVES);
        congestion_totale = calcul_congestion_totale(Horaires_tabou_dur, NBELEVES, HEUREMAX, TAILLE, TO);
        a = test_solution_valide(Horaires_tabou_dur, TAILLE, couleur, TYPE, TO);

        /// Sortie fichier
        ecrireInformation("\n\n * Algo tabou dur :\n");
        ecrireSolution(Horaires_tabou_dur, couleur, TAILLE, HEUREMAX, congestion_totale);
        ecrireInformation("* Nombre d'élèves par bus pour l'algo tabou dur");
        ecrireCongestionBus(nbElevesBus(Horaires_tabou_dur, couleur, HEUREMAX, TAILLE), HEUREMAX);

        /// Sortie terminal
        printf("\n Planification tabou dur\n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++){
            printf(" %d ",Horaires_tabou_dur[i]);
        }
        printf("\n Calcul congestion tabou dur \n");
        printf("----------------------------------------\n");
        printf("Congestion totale tabou dur : %d\n",congestion_totale);
        printf("\n");
        printf("Solution tabou dur valide ? : %d\n",a);
        free(Horaires_tabou_dur);
/////////////////////


//////////////////////////
//// Tabou roulette : ////
//////////////////////////
        int *Horaires_tabou_roulette = Algo_tabou_roulette(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,NB_ITERATIONS,HEUREMAX,NBELEVES);
        congestion_totale = calcul_congestion_totale(Horaires_tabou_roulette,NBELEVES,HEUREMAX,TAILLE,TO);
        a = test_solution_valide(Horaires_tabou_roulette,TAILLE,couleur,TYPE,TO);

        //// Ecriture fichier
        ecrireInformation("\n\n * Algo tabou roulette :\n");
        ecrireSolution(Horaires_tabou_roulette, couleur, TAILLE, HEUREMAX, congestion_totale);
        ecrireInformation("* Nombre d'élèves par bus pour l'algo tabou roulette");
        ecrireCongestionBus(nbElevesBus(Horaires_tabou_roulette, couleur, HEUREMAX, TAILLE), HEUREMAX);

        //// Ecriture terminal
        printf("\n Planification tabou roulette\n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++){
            printf(" %d ",Horaires_tabou_roulette[i]);
        }
        printf("\n");
        printf("\n Calcul congestion tabou roulette\n");
        printf("----------------------------------------\n");
        printf("Congestion totale tabou roulette : %d\n", congestion_totale);
        printf("\n");
        printf("Solution tabou roulette valide ? : %d\n", a);

        free(Horaires_tabou_roulette);
//////////////////////////
     
    }
}
