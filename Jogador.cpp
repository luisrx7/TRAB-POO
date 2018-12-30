#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Jogador.h"
#include "Ship.h"
using namespace std;

Jogador::Jogador(){
moedas=1000;
}

int Jogador::compranav(int x0,int y0,char tipo0){
	Ship *barco;
	barco = new Ship(x0,y0,tipo0);
	Navios.push_back(*barco);
	return barco->getId();
}

char Jogador::getTipoNavviaID(int id0)const{
	for(unsigned int i=0;i<Navios.size();i++){
			if(Navios[i].getId() == id0){
				return Navios[i].getTipo();
			}
	}
}

int Jogador::getMoedas() const{
	return moedas;
}

void Jogador::setMoedas(int moedas0)
{
	moedas = moedas0;
}


vector<Ship> Jogador::getNavios()const{
	return Navios;
}

void Jogador::printNavios()const{
  for(unsigned int i = 0;i<Navios.size();i++){
    cout << Navios[i].getAsString2();
  }
}

string Jogador::getAsString() const
{
	ostringstream oss;
	oss
    << "Moedas: " << moedas
		<< endl;
		return oss.str();
}
