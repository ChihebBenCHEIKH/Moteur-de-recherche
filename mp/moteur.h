#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED
#include "statistique.h"
#include "indexeur.h"
#include "lecteur.h"
#include "ord.hpp"
#include "analyseur.h"

class Moteur
{
public:
    lecteur *l;
    indexe *i;
    ordonnance *o;
    analyseurr *a;
    Nettoyer::nettoyeur *n;

public:
    Moteur(lecteur *l, indexe *i, ordonnance *o, analyseurr *a,Nettoyer::nettoyeur *n);
    void moteurRechercheFich(char **argv, int argc);//rechercher les mots donnée par l'utilisateur dans le fichier contenant les statistiques de chaque mot du fichier indexer
    void moteurRechercheToutFich(char **argv, int argc); //rechercher les mots donnée par l'utilisateur dans le fichier contenat les statistiques des mots de chaque fichier du repertoire indexer
    void indexerfich(char**); // indexer un fichier donnée en paramétre
    void indexerRepertoire(char**); // indexer une repertoire donnée en paramétre
    void indexerRepertoiredict(char**); // indexer une repertoire donnée en paramétre dans un dictionnaire
    };
#endif
