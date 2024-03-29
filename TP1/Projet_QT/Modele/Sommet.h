/*
 Fichier: Sommet.h
 Auteur(s): Philippe Courtemanche, Anthony Dentinger et Marc-Gaël Hounto
 Date de creation: 12 février 2017
 Description: Description de la classe Sommet
 */

#ifndef SOMMET_H
#define SOMMET_H

#include <string>
#include <map>
#include <limits.h>

using namespace std;

class Sommet {

    friend class Graphe;

public:
    Sommet();
    Sommet(const Sommet& s);
    virtual Sommet* newClone() const = 0;
    virtual ~Sommet();

    int distanceA(Sommet* s);
    inline int getGain() const { return _gain; }
    string getNom() const;
    virtual void visiter() = 0;
    virtual void diminuerDistanceAvantActif(int distance) = 0;
    void setNom(string nomSommet);
    void setGain(int quantiteGain);
    void addDistance(Sommet* deuxiemePoint, int distance);

private:
    virtual bool _estActif() const = 0;
    virtual int _obtenirDistanceAvantActif() const = 0;

private:
    int _gain;
    string _nom;
    std::map<Sommet*, int> _distances;
};

#endif // !SOMMET_H
