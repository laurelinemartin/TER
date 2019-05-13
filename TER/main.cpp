#include "include/Salle.h"
#include "include/Cours.h"
#include "include/Etudiant.h"
#include "include/Enseignant.h"
#include "include/Contraintes.h"
#include "include/Planification.h"
#include "include/Algo.h"
#include "include/Bus.h"
#include "include/IO.h"

using namespace std;
int TAILLE;
int NBCOLOR;
int HEUREMAX;
int NB_ITERATIONS;

int main()
{   
    //initFichier();
    float proba;
    /*
    printf("entrez la probabilitée de lien entre 2 cours :\n");
    scanf("%f",&proba);
    printf("entrez le nombre de cours pour la planification:\n");
    scanf("%d",&TAILLE);
    printf("entrez le nombre de salles disponibles pour la planification:\n");
    scanf("%d", &NBCOLOR);
    printf("lancement de l'application avec une probabilitée de %f, %d cours et %d salles\n",proba, TAILLE, NBCOLOR);*/
    proba = 0.4;
    TAILLE = 40;
    NBCOLOR = 75;
    HEUREMAX = 34;
    NB_ITERATIONS = 10;
    int **T = matrice_adjacence_GNO(TAILLE,proba);
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

    int *couleur = coloration (TAILLE, NBCOLOR);
    printf("COLORATION\n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int j = 0; j < TAILLE; j++)
    {
        printf(" %d ",couleur[j]);
    }
    printf("\n");
    printf("\n");

    

    int **TO = matrice_graphe_oriente(T,TAILLE);
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
    printf("PREMIER SOMMET DE DEGRE ENTRANT NUL\n");
    int premier_sommet = trouver_degre_entrant_nul(TO,TAILLE);
    printf("degré entrant nul : %d\n",premier_sommet);
    printf("\n");

    int *TYPE = type_cours(TAILLE);
    int *NBELEVES = nb_eleves(TYPE, TAILLE);
    printf("\n TYPE DE COURS ET NOMBRES D'ELEVES ASSOCIES\n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ",TYPE[i]);
    }
    printf("\n");
    // int* tabEleves = tabCours(NBELEVES, TAILLE);
    for (int i = 0; i < TAILLE; i++)
    {
        printf("%d ", NBELEVES[i]);
//        printf("%d \t", tabEleves[i]);
    }
    printf("\n");

    int *Horaires = planification(TO, premier_sommet, couleur, TAILLE, TYPE);
    printf("\n PLANIFICATION \n");
    /// Ecriture fichier ///
    // ecrirePlanification(Horaires, couleur, TAILLE);
    /// Ecriture terminal ///
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ", Horaires[i]);
    }
    printf("\n");

    int congestion_totale = calcul_congestion_totale(Horaires, NBELEVES, 34, TAILLE, TO);
    /// Ecriture fichier ///
    ecrireSolution(Horaires, couleur, TAILLE, HEUREMAX, congestion_totale);
    // ecrireCongestionTotale(congestion_totale);
    // ecrireCongestionTotale(congestion_totale, HEUREMAX);
    /// Ecriture Terminal ///
    printf("\n Calcul congestion \n");
    printf("----------------------------------------\n");
    printf("Congestion totale : %d\n",congestion_totale);
    printf("\n");

   

    bool a = test_solution_valide(Horaires,TAILLE,couleur,TYPE,TO);
    //a = true;
    printf("Solution planification initiale valide ? : %d\n",a); //true = 1 false = 0
    
    if(a == 1)
    {
		int *Horaires_glouton = (int*)malloc(TAILLE*sizeof(int*));
        Horaires_glouton = Algo_glouton(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,HEUREMAX,NBELEVES);
        printf("\n Planification gloutonne \n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++)
        {printf(" %d ",Horaires_glouton[i]);}
        printf("\n");
        congestion_totale = calcul_congestion_totale(Horaires_glouton,NBELEVES,HEUREMAX,TAILLE,TO);
        printf("\n Calcul congestion gloutone \n");
        printf("----------------------------------------\n");
        printf("Congestion totale gloutone : %d\n",congestion_totale);
        printf("\n");
        a = test_solution_valide(Horaires_glouton,TAILLE,couleur,TYPE,TO);
        printf("Solution gloutone valide ? : %d\n",a); //true = 1 false = 0
        free(Horaires_glouton);

        int *Horaires_tabou_dur = Algo_tabou_dur(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,NB_ITERATIONS,HEUREMAX,NBELEVES);
        printf("\n Planification tabou dur\n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++)
        {printf(" %d ",Horaires_tabou_dur[i]);}
        printf("\n");
        congestion_totale = calcul_congestion_totale(Horaires_tabou_dur,NBELEVES,HEUREMAX,TAILLE,TO);
        printf("\n Calcul congestion tabou dur \n");
        printf("----------------------------------------\n");
        printf("Congestion totale tabou dur : %d\n",congestion_totale);
        printf("\n");
        a = test_solution_valide(Horaires_tabou_dur,TAILLE,couleur,TYPE,TO);
        printf("Solution tabou dur valide ? : %d\n",a);
        free(Horaires_tabou_dur);

        /*int *Horaires_tabou_roulette = Algo_tabou_roulette(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,NB_ITERATIONS,HEUREMAX,NBELEVES);
        printf("\n Planification tabou dur\n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++)
        {printf(" %d ",Horaires_tabou_roulette[i]);}
        printf("\n");
        congestion_totale = calcul_congestion_totale(Horaires_tabou_roulette,NBELEVES,HEUREMAX,TAILLE,TO);
        printf("\n Calcul congestion tabou dur \n");
        printf("----------------------------------------\n");
        printf("Congestion totale tabou dur : %d\n",congestion_totale);
        printf("\n");
        a = test_solution_valide(Horaires_tabou_roulette,TAILLE,couleur,TYPE,TO);
        printf("Solution tabou dur valide ? : %d\n",a);
        free(Horaires_tabou_roulette);*/
    }
}
