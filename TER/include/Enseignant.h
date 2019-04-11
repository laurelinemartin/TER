#ifndef Enseignant_H
#define Enseignant_H

#include <iostream>
#include <vector>
using namespace std;
class Enseignant
{
    public:
        // Constructeurs / Destructeur
        Enseignant();
        Enseignant(vector<int> p_plage);
        virtual ~Enseignant();

        // Getteurs
        vector<int> get_plage(){return plage;}
        int get_num_ens(){return num_ens;}
        
        // Setteurs
        void set_plage(vector<int> p_plage){plage = p_plage;}

        //FONCTIONS DE BASE
        void description();
        void add_dispo(int dispo);

    protected:

    private:
        static int id_count;
        int num_ens;
        vector<int> plage; //Dispo de l'enseignant
};

#endif // Enseignant_H
