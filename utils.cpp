#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Mapa.h"
using namespace std;

unsigned int ncols,nlinhas,moedas=1000,probpirata=20,preconavio=100,precosoldado=1,precovendpeixe=1,precocompmercad=2,precovendmercad=3,soldadosport=100,probevento=30,probtempestade=30,probsereias=30,probalmaria=20,probmotim=20;


int leSettings(string str,Mapa&map) {
  vector<string> tokens;
  static int nx = 0;
  istringstream iss( str );
  string token;
  while (getline(iss, token, ' ')){
    tokens.push_back(token);
    //cout << token << endl;
  }
  if(tokens[0]=="colunas")
  {
    ncols=stoi(tokens[1]);
    map.setColunas(ncols);
  }
  if(tokens[0]=="linhas")
  {
    
    nlinhas=stoi(tokens[1]);
    map.setLinhas(nlinhas);
  }
  if(tokens[0].size()==ncols && tokens.size() == 1){  //...............+++++

   char char_array[tokens[0].length()+1];
   strcpy(char_array, tokens[0].c_str());

 for (int i=0; i<tokens[0].length()+1; i++){
     map.adicionaCell(i,nx,char_array[i]);
     cout << char_array[i];
    }
    nx++;
  cout << endl;
}
  if(tokens[0]=="moedas")
  {
    moedas=stoi(tokens[1]);
  }
  if(tokens[0]=="probpirata")
  {
    probpirata=stoi(tokens[1]);
  }
  return(0);
}



void leFich(string nomeFich,Mapa &map){
  ifstream file(nomeFich);
  string str;
  while (getline(file,str)){
    leSettings(str, &map);
    str="";
  }

}
