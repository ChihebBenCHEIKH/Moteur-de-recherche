#include <iostream>
#include <ostream>
#include "nettoyeur.h"
#include "lecteur.h"
#include "statistique.h"
#include "indexeur.h"
#include "moteur.h"
#include "ord.hpp"
#include "analyseur.h"
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include <fstream>
#include <bits/stdc++.h>
using std::filesystem::directory_iterator;
using namespace std;
int main(int argc, char *argv[])
{
    
    analyseurr *analy = new analyseurfreq;
    lecteur *l = new lecteur;
    indexe *i = new indexdict;
    indexe *ss = new indexvector;
    ordonnance *o = new ordonnance;
    Nettoyer::nettoyeur *nett=new Nettoyer::nettoyeurMajuscule;
    Moteur m(l, ss, o, analy, nett);
    if (strcmp(argv[1], "indexefich") == 0) // indexer un fichier et enregistrer les données dans un fichier index.txt
    {
        m.indexerfich(argv);

    }
    else if (strcmp(argv[1], "indexerep") == 0) // indexer un répertoire et enregistrer les données dans un fichier indexrep.txt
    {
        m.indexerRepertoire(argv);
    }
    else if(strcmp(argv[1],"indexerrepavecdict")==0)
    {
        m.indexerRepertoiredict(argv);
    }
    else if (strcmp(argv[1], "recherche") == 0) // rechercher des mots dans le fichier indexer
    {
        if (strcmp(argv[2], "-rep") == 0) // rechercher dans indexrep.txt
        {
            m.moteurRechercheToutFich(argv, argc);
        }
        if (strcmp(argv[2],"-fich") == 0) // rechercher dans index.txt
        {
            m.moteurRechercheFich(argv, argc);
        }
    }
    else if (strcmp(argv[1], "--aide") == 0)
    {
        cout << "\033[0;31mindexefich \033[0m       :      indexer un fichier et enregistrer les données dans un fichier index.txt\n";
        cout << "\033[0;31mindexerep \033[0m        :      indexer un répertoire et enregistrer les données dans un fichier indexrep.txt\n";
        cout << "\033[0;31mrecherhcer -rep\033[0m   :      rechercher les mots donn\ée dans indexrep.txt\n";
        cout << "\033[0;31mrecherhcer -fich\033[0m  :      rechercher les mots donn\ée dans index.txt\n";
    }
    else
    {
        cout<<"\033[0;31mErreur de saisie!!! Requette invalide !!\033[0m\n";
    }

    return EXIT_SUCCESS;
}
