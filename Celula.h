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
public:
  Celula::Celula(int x0, int y0, char c0) :x(x0),y(y0), c(c0){
  	switch (c) {
  	case '.': //mar
      peixe = 1000;
  		lot = 1;
  		break;
  	case '+': //terra
    peixe = 0;
  		lot = 0;
  		break;
  	default: //porto
    peixe = 1000;
  		lot = LOT;
  		break;
  	}
  }


  void Celula::setX(int x0);
  void Celula::setY(int y0);
  char Celula::setCaract(char c0);
  int Celula::getX()const;
  int Celula::getY()const;
  char Celula::getCaract() const;
  string Celula::getAsString()const;
}



#endif
