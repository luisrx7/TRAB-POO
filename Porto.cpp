#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Porto.h"
using namespace std;

Porto::Porto(int x0,int y0,char c0):x(x0),y(y0),c(c0){
}
int Porto::getX()const{
  return x;
}
int Porto::getY()const{
  return y;
}
char Porto::getChar()const{
  return c;
}
int Porto::getnSoldados()const{
  return nsoldados;
}
int Porto::getRelacaoJogador()const{
  return relacaoJogador;
}
int Porto::getRelacaoPirata()const{
  return relacaoPirata;
}

void Porto::setX(int x0){
  x = x0;
}
void Porto::setY(int y0){
  y = y0;
}
void Porto::setChar(char c0){
  c = c0;
}
void Porto::setNsoldados(int nsoldados0){
  nsoldados = nsoldados0;
}
void Porto::setRelacaoJogador(int relacaoJogador0){
  relacaoJogador=relacaoJogador0;
}
void Porto::setRelacaoPirata(int relacaoPirata0){
  relacaoPirata = relacaoPirata0;
}
string Porto::getAsString()const{
  	ostringstream oss;
    oss << "Posicao: (" << x << "," << y << ") " << endl <<
    "letra: " << c << endl <<
    "Num soldados: " << nsoldados << endl <<
    "Relacao jogador: " << relacaoJogador << endl <<
    "Relacao pirata: "<< relacaoPirata << endl;
  		return oss.str();
}
