#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Settings.h"
using namespace std;

Settings::Settings(){
nlinhas=10;
ncols=20;
probpirata=0;
soldadosport=0;
preconavio=100;
}

int Settings::getLinhas() const{
	return nlinhas;
}

int Settings::getColunas() const{
	return ncols;
}

int Settings::getProbpirata()const{
  return probpirata;
}

int Settings::getSoldadosPort()const{
  return soldadosport;
}

int Settings::getPrecoNavio()const{
  return preconavio;
}

void Settings::setLinhas(int linhas0)
{
	if (linhas0 < 10)
		linhas0 = 10;
	nlinhas = linhas0;
}

void Settings::setColunas(int colunas0)
{
	if (colunas0 < 20)
		colunas0 = 20;
	ncols = colunas0;
}


void Settings::setProbpirata(int probpirata0)
{
  if (probpirata0 < 0 || probpirata0 > 100){
		probpirata0 = 20;}

	probpirata = probpirata0;
}

void Settings::setSoldadosPort(int soldadosport0)
{
  if (soldadosport0 < 0){
		soldadosport0 = 100;}

	soldadosport = soldadosport0;
}

void Settings::setPrecoNavio(int preconavio0){
	if (preconavio0 < 0){
		preconavio0 = 100;
	}
	preconavio = preconavio0;
}
