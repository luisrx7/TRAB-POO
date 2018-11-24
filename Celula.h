#ifndef CELULA_H
#define CELULA_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Celula{
int x,y;
char c;
int peixe;
int lot;

public:

  Celula(int x0, int y0, char c0);
  void setX(int x0);
  void setY(int y0);
  void setCaract(char c0);
  int getX()const;
  int getY()const;
  char getCaract() const;
  string getAsString()const;

};



#endif
