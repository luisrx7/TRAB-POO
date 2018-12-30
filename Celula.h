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
vector<int> ids;//vetor com ids dos barcos que estao nas celulas

public:

  Celula(int x0, int y0, char c0);
  void setX(int x0);
  void setY(int y0);
  void setCaract(char c0);
  void addId(int id);
  void removeId(int id);
  vector<int> getidsNavios()const;
  int getX()const;
  int getY()const;
  int getId()const;
  int getqntbarcos()const;
  char getCaract() const;
  string getAsString()const;
  vector <int> getIds()const;
};



#endif
