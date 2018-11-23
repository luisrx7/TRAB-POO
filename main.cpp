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
using namespace std;


std::vector<char> ajuda;


void printmap(vector<char> &arr){
  for(unsigned int i=1;i<arr.size();i++){
    cout << arr.at(i-1);
    if(i%10 == 0) cout << endl;
  }
}



int main (int argc, char **argv) {




leFich("init.txt");
cout << map.getAsString() << endl;
Mapa map(nlinhas,ncols,ajuda);

/*for(int i =0;i<50;i++){
	mapa.push_back('+');
}*/

printmap(mapa);
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
