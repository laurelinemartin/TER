#include "include/Salle.h"
#include "include/Cours.h"
#include "include/Etudiant.h"
#include "include/Enseignant.h"
//#include "include/Contraintes.h"

using namespace std;

int main()
{
    /****************************TEST COURS************************************/
    //remplacer Eleve et Enseignant par int dans le .h pour ces tests
    Cours *test;
    //Constructeur par defaut
    test = new Cours();

    test->add_etu(1);
    test->add_etu(2);
    test->add_enseignants(5);
    test->add_enseignants(6);

    test->description();

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
    Salle *test1, *test2;
    //Constructeur par defaut
    /*test1 = new Salle();
    test1->descritpion();*/

    //Constructeurs avec des données
    test1 = new Salle(0, 50);
    test1->description();
    test2 = new Salle(0, 45, 2);
    test2->description();

    /****************************TEST ETUDIANTS************************************/
    Etudiant *etu1, *etu2;
    //Constructeur par defaut
    etu1 = new Etudiant();
    etu1->description();
    //Constructeurs avec des données
    etu2 = new Etudiant(1, 30);
    etu2->description();

    /****************************TEST ENSEIGNANT************************************/
    Enseignant *ens1, *ens2;
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

    return 0;
}
