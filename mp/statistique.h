#pragma once
#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <string>
class stat
{
public:
    std::string mot;
    std::string cheminfich;
    float occ;
};
typedef struct motocc
{
    std::string mot;
    std::string fich;
}motocc;
#endif