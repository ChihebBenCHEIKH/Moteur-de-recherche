#pragma once
#ifndef ORDONNANCEUR_H_INCLUDED
#define ORDONNANCEUR_H_INCLUDED
#include "statistique.h"
#include <vector>
#include <map>
#include <string>

bool compareStatpt(stat *, stat *);//comparer deux statistiques de deux mots

class ordonnance
{
public:
    std::vector<stat*> triervect(std::vector<stat*> ); // trier le vecteur de statistique
    std::vector<stat*> trierdict(std::map<std::string,float>&,std::string cheminfich); // déplacer le contenu du dictionnaire dans un vecteur puis le trier
};

#endif
