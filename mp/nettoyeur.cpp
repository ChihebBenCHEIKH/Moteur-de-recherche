#include <string>
#include "nettoyeur.h"
using namespace Nettoyer;
using namespace std;

string* nettoyeurSymbole::elimine(string *n)
{
    string *ch = new string;
    *ch="";
    for (int i = 0; i < n->size(); i++)
    {
        if (n->at(i) != '&' && n->at(i) != '(' && n->at(i) != '[' && n->at(i) != ')' &&  n->at(i) != ']' && n->at(i)  != '{' && n->at(i)  != '}' && n->at(i)  != '_' && n->at(i)  != '=' && n->at(i)  != '$' && n->at(i)  != '"' && n->at(i)  != '/' && n->at(i)  != '*' && n->at(i)  != '-' && n->at(i)  != '+' && n->at(i)  != '#' && n->at(i)  != '~' && n->at(i)  != '\\' && n->at(i)  != '?' && n->at(i)  != '@' && n->at(i)  != '%' && n->at(i)  != ';' && n->at(i) != ':' && n->at(i)  != ',' && n->at(i)  != '^' && n->at(i)  != '\'')
        {
            *ch += n->at(i) ;
        }
    }
    delete n;
    return ch;
}
bool nettoyeurPoint::test(string *p)
{
    for (int i = 1; i < p->size(); i++)
    {
        if (p->at(i) == '.')
            return true;
    }
    return false;
}
string* nettoyeurPoint::elimine(string *p)
{
    string *ch=new string ;
    *ch="";
    if (p->at(0)== '.')
    {
        for (int i = 0; i < p->size() - 1; i++)
        {
            *ch += p->at(i+1);
        }
        return ch;
    }
    if (test(p) == true)
    {
        for (int i = 1; i < p->size() - 1; i++)
        {
            if (p->at(i) == '.' && p->at(i-1) >= 'a' && p->at(i-1) <= 'z' && p->at(i+1) >= 'a' && p->at(i+1) <= 'z' || p->at(i-1) >= 'A' && p->at(i-1) <= 'Z' && p->at(i+1) >= 'A' && p->at(i-1) <= 'Z')
            {
                p->at(i) = ' ';
            }
        }
    }
    return p;
}
string* nettoyeurMajuscule::elimine(string *p)
{
    for (int i = 0; i < p->size(); i++)
    {
        if (p->at(i) >= 'A' && p->at(i) <='Z')
            p->at(i) +=32;
    }
    return p;
}