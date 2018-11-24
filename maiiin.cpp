#include <string>
#include <stdio.h>
#include <iostream>
#include "consola.h"
//#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Mapa.h"
#include "Celula.h"
#include <vector>
using namespace std;

vector<char> ajuda;


void printmap(vector<char> &arr){
  cout << endl;
  for(unsigned int i=1;i<arr.size();i++){
    cout << arr[i-1];
    if(i%(ncols+1) ==0) cout << endl;
  }
}

vector <char> leFich(string nomeFich){
  vector <char> dummy;
  ifstream file(nomeFich);
  string str;
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
      ncols=stoi(tokens[1]);
      //map.setColunas(ncols);
    }
    if(tokens[0]=="linhas")
    {

      nlinhas=stoi(tokens[1]);
      //map.setLinhas(nlinhas);
    }
    if(tokens[0].size()==ncols && tokens.size() == 1){  //...............+++++

     char char_array[tokens[0].length()+1];
     strcpy(char_array, tokens[0].c_str());

   for (unsigned int i=0; i<tokens[0].length()+1; i++){
       dummy.push_back(char_array[i]);
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

    str="";
  }
  return dummy;

}

int main (int argc, char **argv) {
  ajuda = leFich("init.txt");
  printmap(ajuda);

  Mapa map(10,20,ajuda);
  cout << map.getAsString() << endl;


  /*for(int i =0;i<50;i++){
  	mapa.push_back('+');
  }*/
}
