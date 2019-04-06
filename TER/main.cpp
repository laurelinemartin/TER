#include "include/Salle.h"
#include "include/Cours.h"
#include "include/Eleve.h"
#include "include/Enseignant.h"

using namespace std;

int main()
{
    /****************************TEST COURS************************************/
    //remplacer Eleve et Enseignant par int dans le .h pour ces tests
    Cours *test;
    //Constructeur par defaut
    /*test = new Cours();

    test->add_eleve(1);
    test->add_eleve(2);
    test->add_enseignants(5);
    test->add_enseignants(6);

    test->description();*/

    //Constructeur avec des données 
    vector<int> p_liste_etu, p_liste_ens;

    p_liste_etu.push_back(1); p_liste_etu.push_back(2);
    p_liste_ens.push_back(5), p_liste_ens.push_back(6);

    test = new Cours(1, 2, 3, 4, 9, 6, p_liste_etu, p_liste_ens);

    test->add_eleve(3);
    test->add_enseignants(7);
    test->set_num_ens(10);
    test->set_num_ens(5);

    test->description();



    return 0;
}
