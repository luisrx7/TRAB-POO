#ifndef SHIP_H
#define SHIP_H


#include "Settings.h"

using namespace std;
class Ship{
  int x,y;
  int id;
  char tipo;
  static int conta;
  int velocidade;
  int Tpeixe = 0;
  int agua;
  int nsoldados = 0;

public:
  Ship(int x0,int y0,char tipo0);
  int geraId();

  int getX()const;
  int getY()const;
  int getId()const;
  char getTipo()const;
  int getVelocidade()const;
  int getTpeixe()const;
  int getAgua()const;
  int getNsoldados()const;

  void setX(int x0);
  void setY(int y0);
  void setId(int id0);
  void setVelocidade(int velocidade0);
  void setTpeixe(int tpeixe0);
  void setAgua(int agua0);
  void setNsoldados(int nsoldados0);
  string getAsString()const;
  string getAsString2()const;

};

#endif
