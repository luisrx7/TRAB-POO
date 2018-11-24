#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "Settings.h"
#include "Jogador.h"
using namespace std;

void printmap(vector<char> &arr);
vector <char> leFich(string nomeFich,Settings & defs,Jogador & p1);


#endif
