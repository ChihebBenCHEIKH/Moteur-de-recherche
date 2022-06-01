#pragma once
#ifndef NETTOYEUR_H_INCLUDED
#define NETTOYEUR_H_INCLUDED
#include <string>
using namespace std;
namespace Nettoyer
{
    class nettoyeur // class abstraite
    {
    public:
        virtual string* elimine(string *)=0; //méthode abstraite de class
    };
    class nettoyeurSymbole :public nettoyeur//class fille 
    {
    public:
        string* elimine(string *);// méthode qui élimine les symboles d'une chaine donnée
    };
    class nettoyeurPoint: public nettoyeur//class fille
    {
    public:
        bool test(string *p);// méthode test si la chaine contient des points
        string* elimine(string *);// méthode qui élimine les points d'une chaine donnée
    };
    class nettoyeurMajuscule:public nettoyeur//classe fille
    {
    public:
        string* elimine(string *);// méthode qui élimine les majuscules d'une chaine donnée
    };
}
#endif
