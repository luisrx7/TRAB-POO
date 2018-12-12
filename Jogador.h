#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <vector>
#include "Ship.h"
using namespace std;
class Jogador{
   int moedas;

public:
  vector<Ship> Navios;
  Jogador();
  int compranav(int x0,int y0,char tipo0);
  int getMoedas()const;
  char getTipoNavviaID(int id0)const;
  vector<Ship> getNavios()const;

  void printNavios(int x, int y)const;
	void setMoedas(int moedas0);
  string getAsString() const;
};

#endif
