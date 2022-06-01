#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "analyseur.h"
#include "indexeur.h"
#include "statistique.h"
#include <filesystem>
#include <type_traits>
#include <bits/stdc++.h>
#include <fstream>
using std::filesystem::directory_iterator;

void indexdict::indexer(std::vector<stat*> &vecteurstat)
{
  for (int i = 0; i < vecteurstat.size(); i++)
  {
    dict.insert(std::pair<string, float>(vecteurstat[i]->mot, vecteurstat[i]->occ));
  }
}
vector<stat*> indexdict::obtenirToutstat(const std::string cheminrep)
{
  vector<stat*> ver;
  for (const auto &file : directory_iterator(cheminrep))
    {
  for(auto pair:dict)
  {
    stat *s=new stat;
    s->cheminfich=file.path();
    s->mot=pair.first;
    s->occ=pair.second;
    ver.push_back(s);
  }
    }
  return ver;

}
void indexvector::indexer(std::vector<stat*> &vecteurstat)
{
  for (int i = 0; i < vecteurstat.size(); i++)
  {
    vect.push_back(vecteurstat[i]);
  }
}
std::vector<stat*> indexvector::obtenirToutstat(const std::string cheminfich) 
{
  return vect;
}
float indexdict::obtenirstat(const string &mot)
{
  for (auto pair : dict)
  {
    if (pair.first.compare(mot) == 0)
    {
      return (pair.second);
    }
  }
  return 0;
}
float indexvector::obtenirstat(const string &mot)
{
  for (int i=0;i<vect.size();i++)
  {
    if (vect[i]->mot.compare(mot) == 0)
    {
      return (vect[i]->occ);
    }
  }
  return 0;
}

