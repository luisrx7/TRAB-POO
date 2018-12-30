#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Ship.h"
#include "Settings.h"
#include "ObjetosGlobais.h"
using namespace std;



int Ship::conta = 9;

Ship::Ship(int x0,int y0,char tipo0):x(x0),y(y0),tipo(tipo0){
  id = geraId();
  switch (tipo) {
  Tpeixe = 0;
  case 'F': //Fragata
  velocidade = defs.velVMAX;
  agua = defs.capAguaFMAX;
  break;
  case 'G': //Galeao
  velocidade = defs.velGMAX;
  agua = defs.capAguaGMAX;
  break;
  case 'E': //Escuna
  velocidade = defs.velEMAX;
  agua = defs.capAguaEMAX;
  break;
  case 'V': //Ship
  velocidade = defs.velVMAX;
  agua = defs.capAguaVMAX;
  break;
  case 'S': //special
  velocidade = defs.velSMAX;
  agua = defs.capAguaSMAX;
  break;
  }
}

int Ship::geraId(){
  conta++;
  return conta;
}

int Ship::getX()const{
  return x;
}
int Ship::getY()const{
  return y;
}
int Ship::getId()const{
  return id;
}

char Ship::getTipo()const{
  return tipo;
}

int Ship::getVelocidade()const{
  return velocidade;
}
int Ship::getNsoldados()const{
  return nsoldados;
}
int Ship::getTpeixe()const{
  return Tpeixe;
}
int Ship::getAgua()const{
  return agua;
}

void Ship::setX(int x0){
  x = x0;
}
void Ship::setY(int y0){
  y = y0;
}
void Ship::setId(int id0){
  id=id0;
}
void Ship::setVelocidade(int velocidade0){
    velocidade = velocidade0;
}
void Ship::setTpeixe(int tpeixe0){
  Tpeixe = tpeixe0;
}
void Ship::setAgua(int agua0){
  agua = agua0;
}
void Ship::setNsoldados(int nsoldados0){
  nsoldados=nsoldados0;
}
string Ship::getAsString()const{
  	ostringstream oss;
    oss << "Posicao: (" << x << "," << y << ") " << endl <<
    "Id: " << id << endl <<
    "Num soldados: " << nsoldados << endl <<
    "velocidade: " << velocidade << endl <<
    "Tpeixe: "<< Tpeixe << endl <<
    "Agua: "<< agua << endl;
  		return oss.str();
}
string Ship::getAsString2()const{
  	ostringstream oss;
    oss << tipo << id << " (" << x << "," << y << ") " <<
    " tripul: " << nsoldados <<
    "   V: " << velocidade <<
    "   T: "<< Tpeixe <<
    "   A: "<< agua;
  		return oss.str();
}
