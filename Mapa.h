#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Celula.h"
using namespace std;

class Celula;
class Porto;

class Mapa //serve so para ver; nao altera
{
	int linhas, colunas;
	vector<Porto> Portos;
	vector<Celula> grelha;

public:
	Mapa( int linhas0, int colunas0, vector <char> m);
	int getLinhas()const;
	int getColunas()const;
	vector <int> getPortoPrinc()const;
	void setLinhas(int linhas0);
	void setColunas(int colunas0);
	void printmapa()const;
	void printPortos()const;

	//retorna portos contidos no Mapa
	vector<Porto>getPortos()const;
	void addIdtoCelula(int x0,int y0,int id);
	void remIdtoCelula(int x0,int y0,int id);
	char getCelula(int x, int y) const;
	vector<int> checkpos(int x,int y,int xobj,int yobj);
	int getidNavioemCelulaXY(int x0,int y0)const;
	void removeidemCelulaXY(int x0,int y0,int id0);
	void addidemCelulaXY(int x0,int y0,int id0);
	void printIdCelula(int x0,int y0);
	string getAsString() const;
};
#endif
