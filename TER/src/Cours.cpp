#include "../include/Cours.h"
#include "../include/Contraintes.h"


Cours::Cours() : num_cours(0), duree(0), type_salle(),
                num_salle(0), num_ens(0), debut(0){}

Cours::Cours(int p_num_cours, int p_duree, int p_type_salle,
              int p_num_salle, int p_num_ens, int p_debut,
              vector<int> p_liste_etu, vector<int> p_liste_ens): num_cours(p_num_cours), duree(p_duree), type_salle(p_type_salle),
                                                                num_salle(p_num_salle), debut(p_debut),
                                                                liste_etu(p_liste_etu), liste_ens(p_liste_ens)
{
    if (contrainte_professeur_cours(*this)) 
        this->num_ens = p_num_ens;
    else 
        cout<<"l'enseignant designé n'est pas dans la liste"<<endl;
}

Cours::~Cours()
{
    //dtor
}

void Cours::add_eleve(int eleve){
    liste_etu.push_back(eleve);
}

void Cours::add_enseignants(int enseignant){
    liste_ens.push_back(enseignant);
}

void Cours::set_num_ens(int p_num_ens){
    if (contrainte_professeur_cours(*this)) 
        this->num_ens = p_num_ens;
    else 
        cout<<"l'enseignant designé n'est pas dans la liste"<<endl;
}

void Cours::description(){
    cout<<"num_cours : "<<this->get_num_cours()<<endl;
    cout<<"duree : "<<this->get_duree()<<endl;
    cout<<"type_salle : "<<this->get_type_salle()<<endl;
    cout<<"num_salle : "<<this->get_num_salle()<<endl;
    cout<<"num_ens : "<<this->get_num_ens()<<endl;
    cout<<"debut : "<<this->get_debut()<<endl;
    cout<<"Elèves : "<<endl;
    for(int i = 0; i < this->liste_etu.size(); i ++){
        cout<<this->liste_etu[i]<<endl;
    }
    cout<<"Enseignants : "<<endl;
    for(int i = 0; i < this->liste_ens.size(); i ++){
        cout<<this->liste_ens[i]<<endl;
    }
}