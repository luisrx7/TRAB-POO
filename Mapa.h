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

class Mapa //serve so para ver; nao altera
{
	int linhas, colunas;
	vector<Celula> grelha;

public:
	/*___________________Mapa______________________________________________*/
	Mapa( int linhas0, int colunas0, vector <char> m);
	//Mapa(vector<string> dados, int linhas0, int colunas0);
	//~Mapa();
	/*_________________Configs_______________________*/
	int getLinhas()const;
	int getColunas()const;
	void setLinhas(int linhas0);
	void setColunas(int colunas0);

	char getMapPos(int x, int y) const;
	void setMapPos(char * aux[]/*int x, int y, char c*/);
	/*_______________Inicialzia��o_________________*/
	//int getFlatVectorIndex(int aIndexX, int aIndexY);
	void novoVect();
	char getCelula(int x, int y) const;

	/*_________________Posicao___________________________________________*/
	//bool estaVazia(const Ponto &posicao) const; //PROBLEMATICA
	//Ponto getPosicaoVaziaAleat()const; //PROBLEMATICA

	/*_________________Puxa coisas_______________________________________*/
	//retorna navios contidos no Mapa
	//vector<Navio *>getNavios()const;

	//retorna portos contidos no Mapa
	//vector<Porto *>getPortos()const;

	/*_________Adicionar Navio_______________________*/
	void adicionaNavio(int x, int y, char tipo) const;
	/*_________Adicionar Celula_______________________*/
	void adicionaCell(int x, int y, char tipo);

	///*_________Adicionar Porto_______________________*/
	//void adicionaPorto(int x, int y, char tipo) const;
	///*_________Adicionar Mar_______________________*/
	//void adicionaMar(int x, int y);
	///*_________Adicionar Terra_______________________*/
	//void adicionaTerra(int x, int y);
	/*________Compra Navio___________________________*/



	/*__________________Ficheiros________________________________________*/
//static bool leMapaDeFicheiro(ifstream &f, Mapa & r);
//static bool gravarMapaEmFicheiro(ofstream &f, const Mapa & r);

/*_________Ficheiro_______________________*/
	bool leMapaficheiro() const;
	//bool gravaMapaficheiro() const;

	/*_________________Imprime para teste____________*/
	string getAsString()const;
};

#endif
