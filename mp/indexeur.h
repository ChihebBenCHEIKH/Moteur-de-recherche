#pragma once
#ifndef INDEXEUR_H_INCLUDED
#define INDEXEUR_H_INCLUDED
#include <string>
#include <vector>
#include <map>
#include "analyseur.h"
#include "statistique.h"
using namespace std;

class indexe // indexgeneral
{
public:
    virtual void indexer(vector<stat*> &) = 0; // méthode virtuelle pure
    virtual vector<stat*> obtenirToutstat(const string cheminfich) = 0; // méthode virtuelle pure
    virtual float obtenirstat(const string &) = 0;// méthode virtuelle pure
};
class indexdict : public indexe // indexgeneral
{
public:
    map<string, float> dict = {}; //dictionnaire qui contient les statistiques des mots

public:
    void indexer(vector<stat*> &); //stocker les statistiques des mots dans le dictionnaire
    vector<stat*> obtenirToutstat(const string cheminrep); //retourne le vecteur contenant le statistique de chaque mot
    float obtenirstat(const string &); //obtenir le statistique d'une mot donnée
};
class indexvector : public indexe
{
public:
    vector<stat*> vect = {}; //vecteur qui contient les statistique des mots

public:
    void indexer(vector<stat*> &);//stocker les statistiques des mots dans le vecteur
    vector<stat*> obtenirToutstat(const string cheminfich);//retourne le vecteur contenant le statistique de chaque mot
    float obtenirstat(const string &);  //obtenir le statistique d'une mot donnée
};
#endif
