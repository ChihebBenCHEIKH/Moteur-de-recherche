#include <map>
#include <vector>
#include "ord.hpp"
#include "statistique.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

bool compareStatpt(stat* i1, stat *i2)
{
    return (i1->occ > i2->occ);
}


std::vector<stat*> ordonnance::triervect(std::vector<stat*> v)
{

    std::sort(v.begin(), v.end(), compareStatpt);
    return v;
}
std::vector<stat*> ordonnance::trierdict(std::map<std::string,float>&dict,string cheminfich)
{
    vector<stat*> vecttrie;
    for(auto &it: dict)
    {
        stat *p=new stat;
        p->cheminfich=cheminfich;
        p->mot=it.first;
        p->occ=it.second;
        vecttrie.push_back(p);
        delete p;
    }
    std::sort(vecttrie.begin(),vecttrie.end(),compareStatpt);
    return vecttrie;
}
