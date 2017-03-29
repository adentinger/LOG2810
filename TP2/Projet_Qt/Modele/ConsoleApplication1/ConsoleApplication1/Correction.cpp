/****************************************************************************
 * Fichier: Correction.cpp
 * Auteurs: Philippe Courtemanche, Anthony Dentinger et Marc-Gaël Hounto
 * Date: 28 mars 2017
 * Description: Implémentation de la classe Correction
 ****************************************************************************/
#include "Correction.h"

Correction::Correction()
{
}

Correction::~Correction()
{
}

std::vector<string> Correction::corrigerMot(string mot) 
{
	if (Lexique::getInstance()->existe(mot))
	{
		motsCorriges.push_back(mot);;
	}
	else
	{
		for (int i = 0;i < mot.size();i++)
		{
			char reserve = mot[i];
			for (int j = 0;j < 26;j++)
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