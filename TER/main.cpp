#include "include/Salle.h"
#include "include/Cours.h"
#include "include/Etudiant.h"
#include "include/Enseignant.h"
#include "include/Contraintes.h"
#include "include/Planification.h"

using namespace std;

int main()
{
    int **T = matrice_adjacence(10,0.2);
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf(" %d ",T[i][j]);
        }
        printf("\n");
    }
    coloration (10, 2);
    int i = trouver_degre_entrant_nul(T,10);
    printf("degré entrant nul : %d\n",i);


   /* Cours *c1;
    Cours *c2;
    Cours *c3;
    Cours *c4;
    vector<int> p_liste_etu, p_liste_ens;
    p_liste_etu.push_back(1); p_liste_etu.push_back(2);
    p_liste_ens.push_back(1), p_liste_ens.push_back(2);
    
    c1 = new Cours(1, 2, 1, 1, 1, 1, p_liste_etu, p_liste_ens);
    c1->description();
    c2 = new Cours(2, 2, 1, 2, 2, 2, p_liste_etu, p_liste_ens);
    c2->description();
    vector<*Cours> liste_cours;
   liste_cours.push_back(c1);
    liste_cours.push_back(c2);
    for(int i = 0; i < liste_cours.size(); i ++){
        cout<<liste_cours[i]<<endl;
    } */
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
