#include "Sommet.h"
using namespace std;

Sommet::Sommet()
{ }

Sommet::Sommet(int gain, const std::map<Sommet*, int>& distances)
    : _gain(gain), _distances(distances)
{ }

Sommet::~Sommet() {}

int Sommet::distanceA(const Sommet* s) const {
    int ret;

    if (s.estActif()) {
        ret = _distances[s];
    }
    else {
        int daa = s->_obtenirDistanceAvantActif();
        
        bool distEstInfinie = (daa <= INT_MAX - 1);
        if (!distEstInfinie) {
            ret = daa + _distances[s];
        }
        else {
            ret = daa;
        }
    }
    return ret;
}

void Sommet::setNom(string nomSommet)
{
    this._nom = nomSommet;
}

void Sommet::setGain(string quantiteGain)
{
    this._gain = stoi(quantiteGain);
}

void Sommet::addDistance(Sommet* s, string distance)
{
    //creer une paire avec l'objet 2e point et cette distance
    pair <Sommet*,int> temp1;
    temp1 = make_pair (s,distance);

    //ajouter cette paire dans la map de l'attribut _distances de l'objet courant
    _distances.insert(temp1);
    
    //ensuite, creer une paire avec l'objet courant et cette distance
    pair <Sommet*,int> temp2;
    temp2 = make_pair (this,distance);
    
    //ajouter cette paire dans la map de l'attribut _distances de l'objet correspondant au string deuxiemePoint
    s._distances.insert(temp2);
    
}

string getNom()
{
    return _nom;
}
