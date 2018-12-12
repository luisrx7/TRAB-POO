#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Mapa.h"
#include "utils.h"
#include "Settings.h"
#include "Jogador.h"
using namespace std;

//unsigned int ncols,nlinhas,moedas=1000,probpirata=20,preconavio=100,precosoldado=1,precovendpeixe=1,precocompmercad=2,precovendmercad=3,soldadosport=100,probevento=30,probtempestade=30,probsereias=30,probalmaria=20,probmotim=20;


void printmap(vector<char> &arr,int ncols){
  cout << endl;
  for(unsigned int i=1;i<arr.size();i++){
    cout << arr[i-1];
    if(i%(ncols+1) ==0) cout << endl;
  }
}

vector <char> leFich(string nomeFich,Settings & defs,Jogador & p1){
  vector <char> dummy;
  ifstream file(nomeFich);
  string str;
  int n;
  while (getline(file,str)){
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

      defs.setColunas(stoi(tokens[1]));
      //map.setColunas(ncols);
    }
    if(tokens[0]=="linhas")
    {

      defs.setLinhas(stoi(tokens[1]));
      //map.setLinhas(nlinhas);
    }
    if(tokens[0].size()==defs.getColunas() && tokens.size() == 1){  //...............+++++
      //falta limitar leitura de linha
     char char_array[tokens[0].length()+1];
     strcpy(char_array, tokens[0].c_str());

   for (unsigned int i=0; i<tokens[0].length(); i++){
       dummy.push_back(char_array[i]);
      // cout << char_array[i];
      }
      nx++;
    cout << endl;
  }
    if(tokens[0]=="moedas")
    {
      p1.setMoedas(stoi(tokens[1]));
    }
    if(tokens[0]=="probpirata")
    {
      defs.setProbpirata(stoi(tokens[1]));
    }
    if(tokens[0]=="soldadosport")
    {
      defs.setSoldadosPort(stoi(tokens[1]));
    }
    if(tokens[0]=="preconavio")
    {
      defs.setPrecoNavio(stoi(tokens[1]));
    }

    str="";
  }
  return dummy;

}
