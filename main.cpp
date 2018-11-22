#include <string>
#include <stdio.h>
#include <iostream>
#include "consola.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Mapa.h"
using namespace std;

vector<char> mapa;
void printmap(vector<char> &arr){
  for(unsigned int i=1;i<arr.size();i++){
    cout << arr.at(i-1);
    if(i%10 == 0) cout << endl;
  }
}



int main (int argc, char **argv) {


Mapa map;

leFich("init.txt",&map);
cout << map.getAsString() << endl;

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
