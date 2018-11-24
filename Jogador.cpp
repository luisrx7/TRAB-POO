#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Jogador.h"
using namespace std;

Jogador::Jogador(){
moedas=1000;
}

int Jogador::getMoedas() const{
	return moedas;
}

void Jogador::setMoedas(int moedas0)
{
	moedas = moedas0;
}
string Jogador::getAsString() const
{
	ostringstream oss;
	oss
    << "Numero moedas: " << moedas
		<< endl;
		return oss.str();
}
