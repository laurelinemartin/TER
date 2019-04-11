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
        vector<int> get_plage();
        int get_num_ens();
        
        // Setteurs
        void set_plage(vector<int> p_plage);
        void description();

    protected:

    private:
        static int id_count;
        int num_ens;
        vector<int> plage; //Dispo de l'enseignant
};

#endif // Enseignant_H
