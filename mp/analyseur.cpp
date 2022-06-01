#include "analyseur.h"
#include "statistique.h"
#include <vector>
#include <string>

float analyseur::calculocc(std::vector<std::string*> vectmots,std::string *mot)
{
    float s = 0.0;
    std::string mott= *mot;
    for (int i = 0; i < vectmots.size(); i++)
    {
        std::string ch=*vectmots[i];
        if (mott.compare(ch) == 0)
            s++;
    }
    float k = s / ((float)vectmots.size());
    return (k * 100);
}
std::vector<stat*> analyseur::calcul(std::vector<std::string*> mots,std::string *fichier)
{

    float x;
    std::vector <stat*> ver;
    for (int i = 0; i < mots.size(); i++)
    {
        stat *statistique=new stat ;
        statistique->cheminfich=*fichier;
        statistique->mot=*mots[i];
        statistique->occ=calculocc(mots, mots[i]);
        ver.push_back(statistique);
        delete statistique;
    }
    return ver;
}
std::vector<stat*> analyseurfreq::calcul(std::vector<std::string*> mots,std::string *fichier)
{

    float x;
    std::vector <stat*> ver;
    for (int i = 0; i < mots.size(); i++)
    {
        stat *statistique=new stat;
        statistique->cheminfich=*fichier;
        statistique->mot=*mots[i];
        statistique->occ=calculfreq(mots, mots[i]);
        ver.push_back(statistique);
        delete statistique;
    }
    return ver;
}
float analyseurfreq::calculfreq(std::vector<std::string*> vectmots, std::string *mot)
{
    float s = 0.0;
    std::string c=*mot;
    for (int i = 0; i < vectmots.size(); i++)
    {
        std::string h=*vectmots[i];
        if (c.compare(h) == 0)
            s++;
    }
    return (s);
}
