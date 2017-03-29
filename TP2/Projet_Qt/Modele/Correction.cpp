#include "Correction.h"

Correction* Correction::_instance = nullptr;

Correction::Correction()
{ }

Correction::~Correction()
{ }

vector<string> Correction::suggerer(string mot) {
    vector<string> suggestions;



    return suggestions;
}

vector<string> Correction::corrigerMot(string mot)
{
    vector<string> motsCorriges;

	if (Lexique::getInstance()->existe(mot))
	{
        motsCorriges.push_back(mot);
	}
	else
	{
        for (unsigned int i = 0; i < mot.size(); i++)
		{
			char reserve = mot[i];
            for (int j = 0; j < 26; j++)
			{
				mot[i] = alphabet[j];
				if (Lexique::getInstance()->existe(mot))
					motsCorriges.push_back(mot);
			}
			mot[i] = reserve;
		}
		
	}
	return motsCorriges;

}

void Correction::creerCorrection() {
    delete _instance;
    _instance = new Correction();
}

void Correction::construireCorrection(const string& nomLexique) {
    Lexique::creerLexique(100);
    _connecter();
    Lexique::construireLexique(nomLexique);
}


// PRIVATE:

void Correction::_connecter() {
    connect(Lexique::getInstance(), SIGNAL(progressionConstruction(int)), _instance, SLOT(_progressionConstruction(int)));
    connect(Lexique::getInstance(), SIGNAL(progressionMinimisation(int)), _instance, SLOT(_progressionMinimisation(int)));
    connect(Lexique::getInstance(), SIGNAL(constructionTerminee()),       _instance, SLOT(_constructionTerminee()));
}


// PRIVATE SLOTS:

void Correction::_progressionConstruction(int progressionPourcent) {
    emit progressionConstruction(progressionPourcent);
}

void Correction::_progressionMinimisation(int progressionPourcent) {
    emit progressionMinimisation(progressionPourcent);
}

void Correction::_constructionTerminee() {
    emit constructionTerminee();
}