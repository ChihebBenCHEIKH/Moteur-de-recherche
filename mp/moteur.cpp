#include "moteur.h"
#include <string>
#include <vector>
#include "statistique.h"
#include "indexeur.h"
#include "lecteur.h"
#include "nettoyeur.h"
#include "listefichiers.h"
#include "ord.hpp"
#include <iostream>
#include <map>
#include <sstream>
#include <filesystem>
#include <type_traits>
#include <bits/stdc++.h>
#include <fstream>
using std::filesystem::directory_iterator;
using namespace std;
Moteur::Moteur(lecteur *l, indexe *i, ordonnance *o, analyseurr *a, Nettoyer::nettoyeur *n)
{
    this->l = l;
    this->i = i;
    this->o = o;
    this->a = a;
    this->n = n;
}
void Moteur::moteurRechercheFich(char **argv, int argc)
{
    clock_t debut, fin;
    debut = clock();
    vector<string *> p;
    vector<string> v;
    // lecteur *li;
    v.reserve(argc);
    for (int i = 3; i < argc; i++)
    {
        Nettoyer::nettoyeurPoint g;
        Nettoyer::nettoyeurSymbole li;
        Nettoyer::nettoyeurMajuscule t;
        string *c = new string;
        *c = string(argv[i]);
        if (g.test(c) == true)
        {
            c = g.elimine(c);
            c = li.elimine(c);
            c = t.elimine(c);
            stringstream ss(*c);
            string h;
            while (getline(ss, h, ' '))
            {
                v.push_back(h);
                h.erase(h.size());
            }
            delete c;
        }
        else
        {
            c = g.elimine(c);
            c = li.elimine(c);
            c = t.elimine(c);
            string h = *c;
            v.push_back(h);
        }
        p = l->separeMot("/home/chiheb/Documents/.vscode/MP/index.txt");
        for(int i=0;i<p.size();i++)
        {
            p[i]=n->elimine(p[i]);
        }
        for (int j = 0; j < v.size(); j++)
        {
            for (int i = 1; i < p.size(); i = i + 2)
            {
                string *p0 = p[i];
                string ch = *p0;
                string *p1 = p[i - 1];
                string *p2 = p[i + 1];
                if (ch.compare(v[j]) == 0)
                {
                    cout << *p1 << endl
                         << *p0 << endl
                         << *p2 << endl;
                }
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }
    fin = clock();
    double temps_execution = double(fin - debut) / double(CLOCKS_PER_SEC);
    cout << "Temps d\'\éxecution total est : " << temps_execution << setprecision(5) << "s\n";
}

void Moteur::moteurRechercheToutFich(char **argv, int argc)
{
    clock_t debut, fin;
    debut = clock();
    vector<string *> p;
    vector<string> v;
    // lecteur *li;
    v.reserve(argc);
    for (int i = 4; i < argc; i++)
    {
        Nettoyer::nettoyeurPoint g;
        Nettoyer::nettoyeurSymbole li;
        Nettoyer::nettoyeurMajuscule t;
        string *c = new string;
        *c = string(argv[i]);
        if (g.test(c) == true)
        {
            c = g.elimine(c);
            c = li.elimine(c);
            c = t.elimine(c);
            stringstream ss(*c);
            string h;
            while (getline(ss, h, ' '))
            {
                v.push_back(h);
                h.erase(h.size());
            }
            delete c;
        }
        else
        {
            c = g.elimine(c);
            c = li.elimine(c);
            c = t.elimine(c);
            v.push_back(argv[i]);
        }
        p = l->separeMot("indexrep.txt");
        for (int i = 0; i < p.size(); i++)
        {
            p[i] = n->elimine(p[i]);
        }
        for (int i = 1; i < p.size(); i = i + 2)
        {
            for (int j = 0; j < v.size(); j++)
            {
                string *p0 = p[i];
                string ch = *p0;
                string *p1 = p[i - 1];
                string *p2 = p[i + 1];
                if (ch.compare(v[j]) == 0)
                {
                    cout << *p1 << endl
                         << *p0 << endl
                         << *p2 << endl;
                }
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }
    fin = clock();
    double temps_execution = double(fin - debut) / double(CLOCKS_PER_SEC);
    cout << "Temps d\'\éxecution total est : " << temps_execution << setprecision(5) << "s\n";
}
void Moteur::indexerfich(char **argv)
{
    clock_t debut, fin;
    debut = clock();
    fstream monfich;
    monfich.open("index.txt", ios::app);
    vector<string *> p;
    p = l->separeMot(argv[2]);
    for (int i = 0; i < p.size(); i++)
    {
        p[i] = n->elimine(p[i]);
    }
    vector<stat *> ver;
    vector<stat *> ve;
    string *h = new string;
    *h = argv[2];
    Nettoyer::nettoyeurMajuscule *s;
    ver = a->calcul(p, h);
    delete h;
    i->indexer(ver);
    ve = i->obtenirToutstat(argv[2]);
    ve = o->triervect(ve);
    if (monfich.is_open())
    {
        for (int i = 0; i < p.size(); i++)
        {
            string *y = p[i];
            stat *pp = ve[i];
            monfich << ve[i]->mot << " " << ve[i]->cheminfich << " " << ve[i]->occ << endl;
            cout << ve[i]->mot << " " << ve[i]->cheminfich << " " << ve[i]->occ << endl;
        }
        cout << "\n";
    }
    for (int i = 0; i < ve.size(); i++)
    {
        delete ve[i];
    }
    ve.clear();
    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }
    p.clear();
    monfich.close();
    fin = clock();
    double temps_execution = double(fin - debut) / double(CLOCKS_PER_SEC);
    cout << "Temps d\'\éxecution total est : " << temps_execution << setprecision(5) << "s\n";
}
void Moteur::indexerRepertoire(char **argv)
{
    clock_t debut, fin;
    debut = clock();
    fstream file;
    file.open("indexrep.txt", ios::app);
    vector<stat *> ver;
    vector<stat *> st;
    vector<string *> p;
    for (const auto &file : directory_iterator(argv[2]))
    {
        p = l->separeMot(file.path());
        for(int i=0;i<p.size();i++)
        {
            p[i]=n->elimine(p[i]);
        }
        string *pp = new string;
        *pp = file.path();
        ver = a->calcul(p, pp);
        delete pp;
        i->indexer(ver);
    }
    st = i->obtenirToutstat("ch");
    st = o->triervect(st);
    if (file.is_open())
    {
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i]->cheminfich << " " << st[i]->mot << " " << st[i]->occ << endl;
            file << st[i]->cheminfich << " " << st[i]->mot << " " << st[i]->occ << endl;
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        delete st[i];
    }
    st.clear();
    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }
    file.close();
    fin = clock();
    double temps_execution = double(fin - debut) / double(CLOCKS_PER_SEC);
    cout << "Temps d\'\éxecution total est : " << temps_execution << setprecision(5) << "s\n";
}
void Moteur::indexerRepertoiredict(char **argv)
{
    clock_t debut, fin;
    debut = clock();
    fstream file;
    file.open("indexrep.txt", ios::app);
    vector<stat *> ver;
    vector<stat *> st;
    vector<string *> p;
    for (const auto &file : directory_iterator(argv[2]))
    {
        p = l->separeMot(file.path());
        for(int i=0;i<p.size();i++)
        {
            p[i]=n->elimine(p[i]);
        }
        string *pp = new string;
        *pp = file.path();
        ver = a->calcul(p, pp);
        delete pp;
        i->indexer(ver);
    }
    
    st = i->obtenirToutstat(argv[2]);
    st = o->triervect(st);
    if (file.is_open())
    {
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i]->cheminfich << " " << st[i]->mot << " " << st[i]->occ << endl;
            file << st[i]->cheminfich << " " << st[i]->mot << " " << st[i]->occ << endl;
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        delete st[i];
    }
    st.clear();
    for (int i = 0; i < p.size(); i++)
    {
        delete p[i];
    }
    file.close();
    fin = clock();
    double temps_execution = double(fin - debut) / double(CLOCKS_PER_SEC);
    cout << "Temps d\'\éxecution total est : " << temps_execution << setprecision(5) << "s\n";
}

