#pragma once
#ifndef ANALYSEUR_H_INCLUDED
#define ANALYSEUR_H_INCLUDED
#include <vector>
#include "statistique.h"
#include <string>
class analyseurr //class abstraite
{
public:
    virtual std::vector<stat*> calcul(std::vector<std::string*> mots,std::string *fichier)=0; //méthode virtuelle pure

};

class analyseur : public analyseurr //class fille
{
public:
    std::vector<stat*> calcul(std::vector<std::string*> mots, std::string *fichier); // calculer l'occurrence du chaque mot du vecteur dans un fichier
    float calculocc(std::vector<std::string*> vectmots,std::string *mot);//calculer l'occurrence d'une seule mot donnée dans tout le fichier
};
class analyseurfreq : public analyseurr //class fille
{
public:
    std::vector<stat*> calcul(std::vector<std::string*> mots,std::string *fichier );/ calculer les statistiques du chaque mot du vecteur // calculer la fréquence du chaque mot du vecteur dans un fichier
    float calculfreq(std::vector<std::string*> v,  std::string *p);//calculer la fréquence d'une seule mot donnée dans tout le fichier
};
#endif
