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

int main()
{   
    initFichier();
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
    TAILLE = 10;
    NBCOLOR = 5;
    HEUREMAX = 34;
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
    int *NBELEVES = nb_eleves(TYPE,TAILLE);
    printf("\n TYPE DE COURS ET NOMBRES D'ELEVES ASSOCIES\n");
    printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ",TYPE[i]);
    }
    printf("\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %d ",NBELEVES[i]);
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

    int congestion_totale = calcul_congestion_totale(Horaires,NBELEVES,34,TAILLE);
    /// Ecriture fichier ///
    ecrireSolution(Horaires, couleur, TAILLE, congestion_totale);
    // ecrireCongestionTotale(congestion_totale);
    ecrireCongestionTotale(congestion_totale, HEUREMAX);
    /// Ecriture Terminal ///
    printf("\n Calcul congestion \n");
    printf("----------------------------------------\n");
    printf("Congestion totale : %d\n",congestion_totale);
    printf("\n");

   

    bool a = test_solution_valide(Horaires,TAILLE,couleur,TYPE,TO);
    //a = true;
    printf("solution planification initiale valide ? : %d\n",a); //true = 1 false = 0

    if(a == 1)
    {
        int *Horaires_tabou = Algo_tabou(Horaires, TAILLE, premier_sommet, couleur, TYPE,TO,1,HEUREMAX,NBELEVES);
        printf("\n Planification tabou \n");
        printf("\n 0  1  2  3  4  5  6  7  8  9  INDICES\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < TAILLE; i++)
        {
          printf(" %d ",Horaires_tabou[i]);
        }
        printf("\n");

        congestion_totale = calcul_congestion_totale(Horaires_tabou,NBELEVES,HEUREMAX,TAILLE);
        printf("\n Calcul congestion tabou \n");
        printf("----------------------------------------\n");
        printf("Congestion totale tabou : %d\n",congestion_totale);
        printf("\n");

        a = test_solution_valide(Horaires_tabou,TAILLE,couleur,TYPE,TO);
        //a = true;
        printf("solution tabou1 valide ? : %d\n",a); //true = 1 false = 0
    }

    

  






    /****************************TEST COURS************************************/
    //remplacer Eleve et Enseignant par int dans le .h pour ces tests
    //Cours *c1;
    //Constructeur par defaut
    /*c1 = new Cours();

    c1->add_etu(1);
    c1->add_etu(2);
    c1->add_enseignants(5);
    c1->add_enseignants(6);

    c1->description(); */

    //Constructeur avec des données 
    /*vector<int> p_liste_etu, p_liste_ens;

    p_liste_etu.push_back(1); p_liste_etu.push_back(2);
    p_liste_ens.push_back(5), p_liste_ens.push_back(6);

    test = new Cours(1, 2, 3, 4, 9, 6, p_liste_etu, p_liste_ens);

    test->add_eleve(3);
    test->add_enseignants(7);
    test->set_num_ens(10);
    test->set_num_ens(5);

    test->description();*/
    
    /****************************TEST SALLE************************************/
    //Salle *test1, *test2;
    //Constructeur par defaut
    /*test1 = new Salle();
    test1->descritpion();*/

    //Constructeurs avec des données
   /* test1 = new Salle(0, 50);
    test1->description();
    test2 = new Salle(0, 45, 2);
    test2->description();

    /****************************TEST ETUDIANTS************************************/
    /* Etudiant *etu1, *etu2;
    //Constructeur par defaut
    etu1 = new Etudiant();
    etu1->description();
    //Constructeurs avec des données
    etu2 = new Etudiant(1, 30);
    etu2->description();

    /****************************TEST ENSEIGNANT************************************/
    /*Enseignant *ens1, *ens2;
    //Constructeur par defaut
    ens1 = new Enseignant();
    ens1->description();
    //Constructeurs avec des données
    vector<int> p_plage;
    p_plage.push_back(3);
    ens2 = new Enseignant(p_plage);
    ens2->add_dispo(17);
    ens2->description();

    /****************************TEST CONTRAINTES************************************/
    
    //cout<<"contrainte_cours_salle : "<<contrainte_cours_salle(*test1, *test)<<endl;
    /*Cours* cours1;
    Cours* cours2;
    
    
     vector<int> p_liste_etu, p_liste_ens;

    p_liste_etu.push_back(1); p_liste_etu.push_back(2);
    p_liste_ens.push_back(5), p_liste_ens.push_back(6);

    cours1 = new Cours(1, 2, 3, 4, 9, 6, p_liste_etu, p_liste_ens);

    cours1->add_etu(3);
    cours1->add_enseignants(7);
    cours1->set_num_ens(10);
    cours1->set_num_ens(5);

    cours1->description();
    
    cours2 = new Cours(1, 2, 3, 4, 9, 12, p_liste_etu, p_liste_ens);

    cours2->add_etu(3);
    cours2->add_enseignants(7);
    cours2->set_num_ens(10);
    cours2->set_num_ens(5);

    cours2->description();

	//~ bool a = test_contraintes(*cours1,*cours2);
	bool a = contrainte_cours_cours(*cours1,*cours2);
	printf(a ? "true" : "false");

    return 0; */
}
