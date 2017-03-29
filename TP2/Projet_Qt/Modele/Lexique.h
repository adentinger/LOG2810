#pragma once
#include <QObject>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

const int _TOTALELEMENTS = 22000;


class Lexique : public QObject
{
    Q_OBJECT

	class Noeud
	{
	public:
        Noeud(char lettreAssociee);
        ~Noeud();

        Noeud* addEnfant(char lettreAssociee); // Si l'enfant existe déjà, addEnfant est équivalent à getEnfant.
        Noeud* getEnfant(char lettreAssociee); // Retourne nullptr si enfant n'existe pas

        void addValide(const string& sousMot);
        bool estValide(const string& sousMot);

        inline char getLettreAssociee() const { return _lettreAssociee; }

	private:
		vector<Noeud*> _enfants;
        vector<string> _sousMotsValides;
		char _lettreAssociee;
	};

public:
    virtual ~Lexique();
    bool existe(const string& mot);
	vector<string>motsSuggeres;

    static void creerLexique(int longueurMax);
    static void construireLexique(const string& fichier);
    static Lexique* getInstance();

private:
    Lexique(int longueurMax);

    static void _construireLexique(const string& fichier);
    static void _minimiserLexique();

    const int _LONGUEUR_MAX;
    string lexique[_TOTALELEMENTS];
    Noeud* _racine;

    static Lexique* _instance;

// Pour la barre de progression de la vue
signals:
    void progressionConstruction(int progressionPourcent);
    void progressionMinimisation(int progressionPourcent);
    void constructionTerminee();
    void minimisationTerminee();
};





