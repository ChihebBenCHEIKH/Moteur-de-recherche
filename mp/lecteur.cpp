#include <string>
#include <fstream>
#include <vector>
#include "lecteur.h"
#include "nettoyeur.h"
#include <cstring>
#include <sstream>
using namespace std;
vector<string *> lecteur::separeMot(const string &p)
{
    vector<string *> v;
    fstream fichier;
    fichier.open(p, ios::in); // le mode de lire
    if (fichier.is_open())
    {
        string ligne;
        while (getline(fichier, ligne))// lire du fichier ligne par ligne 
        {
            stringstream ss(ligne);
            string *mot = new string;
            string r;
            while (getline(ss, r, ' '))// mettre les mots séparés par un espace dans le vecteur v
            {

                v.push_back(new string(r));
            }
        }
    }
    fichier.close();

return v;
}
