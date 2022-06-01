#pragma once
#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED

#include <string>
#include <vector>
#include "nettoyeur.h"
using namespace std;
class lecteur
{
public:
    vector<string*> separeMot(const string &);   // prendre un fichier.txt en paremetre et retourne un vecteur contenant tout les mots de ce fichier
};
#endif
