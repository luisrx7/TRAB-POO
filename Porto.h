#ifndef PORTO_H
#define PORTO_H

using namespace std;
class Porto{
  int x,y;
  char c;
  int nsoldados=0;
  int relacaoJogador=0;
  int relacaoPirata=0;
public:
  Porto(int x0,int y0,char c0);
  int getX()const;
  int getY()const;
  char getChar()const;
  int getnSoldados()const;
  int getRelacaoJogador()const;
  int getRelacaoPirata()const;

  void setX(int x0);
  void setY(int y0);
  void setChar(char c);
  void setNsoldados(int nsoldados0);
  void setRelacaoJogador(int relacaoJogador0);
  void setRelacaoPirata(int relacaoPirata0);
  string getAsString()const;
};

#endif
