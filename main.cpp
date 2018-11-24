#include <string>
#include <stdio.h>
#include <iostream>
#include "consola.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Mapa.h"
#include <vector>
#include "Jogador.h"
using namespace std;


vector<char> ajuda;


int main (int argc, char **argv) {
Settings defs;
Jogador p1;

leFich("init.txt",defs,p1);
Mapa map(defs.getLinhas(),defs.getColunas(),ajuda);
cout << map.getAsString() << endl;
cout << p1.getAsString() << endl;

/*for(int i =0;i<50;i++){
	mapa.push_back('+');
}*/

//printmap(mapa,defs.getColunas());
//printmap(mapa);
/*
vector<string> tokens;
while(1){
	cout << "comando: ";
	  string command;
		getline (cin,command);
    istringstream iss(command);
    string token;
    while (getline(iss, token, ' ')){
				tokens.push_back(token);
        cout << token << endl;
    }
    if (tokens[0] == "config"){
        cout << "blyat" << endl;
            leFich(tokens[1]);
    }

    }
*/
    return 0;
}
