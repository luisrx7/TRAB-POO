#include <string>
#include <stdio.h>
#include <iostream>
#include "consola.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Mapa.h"
#include <vector>
#include "Jogador.h"
#include "Porto.h"
#include "Ship.h"
#include "ObjetosGlobais.h"
using namespace std;


vector<char> ajuda;
//Jogador p1;
//Settings defs;
int main (int argc, char **argv) {



/*Porto porto1(0,0,'P');
porto1.setNsoldados(120);
cout << porto1.getAsString() << endl;*/

/*Ship v1(2,1,22);
cout << v1.getAsString() << endl;*/

bool play=false,debug=false,continua=false;

//leFich("init.txt",defs,p1);
//Mapa map(defs.getLinhas(),defs.getColunas(),ajuda);

//cout << map.getAsString() << endl;
//cout << p1.getAsString() << endl;



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
		if (tokens[0] == "help"){
				cout << "config <config file>" << endl;
				cout << "debug" << endl;
				cout << "exit" << endl;
		}
    if (tokens[0] == "debug"){
        debug = true;
        cout << "debug ON" << endl;
    }
    if (tokens[0] == "config"){
        ajuda = leFich(tokens[1],defs,p1);
        play = true;
        break;
    }
		if (tokens[0] == "cd"){
        ajuda = leFich("init.txt",defs,p1);
        play = true;
        break;
    }
    if (tokens[0] == "exit"){
      cout << "\n Sair" << endl;
			exit(0);
    }

    tokens.erase (tokens.begin(),tokens.end());
  }

ajuda = leFich(tokens[1],defs,p1);
play = true;
tokens.erase (tokens.begin(),tokens.end());

if (play==true){
  Mapa map(defs.getLinhas(),defs.getColunas(),ajuda);
  Consola::clrscr();
  //Consola::gotoxy(0,0);
  map.printPortos();
  Consola::getch();

  //Consola::setScreenSize(defs.getLinhas()+5,defs.getColunas()+10);

  /*Consola::clrscr();
  map.printmapa();*/
	while(1){
    Consola::clrscr();
    map.printmapa();
		cout << "\n\n Comando: ";
		  string command;
			getline (cin,command);
	    istringstream iss(command);
	    string token;
	    while (getline(iss, token, ' ')){
					tokens.push_back(token);
	        //cout << token << endl;
	    }
      if(continua == true){
      /*  Consola::clrscr();
        map.printmapa();*/
      }
			if (tokens[0] == "help"){
					cout << "config <config file> -> ficheiro de definicoes do jogo" << endl;
					cout << "compranav <tipo> -> compra navio do tipo especificado" << endl;
					cout << "compranavdb <x> <y> <tipo> -> compra navio do tipo na pos x y" << endl;
					cout << "prox -> avanca para proximo turno" << endl;
					cout << "exit -> sai do jogo" << endl;
			}
	    if (tokens[0] == "config"){
	        ajuda = leFich(tokens[1],defs,p1);
	    }

			if (tokens[0] == "prox"){
        defs.turnos++;
        for(unsigned int i=0;i<p1.Navios.size();i++){
          //fazer movimento para todos os navios

          int randVel;
          if(p1.Navios[i].getVelocidade()==2){
            randVel = 2;//rand()%2;
          }
          else{
            randVel = rand()%1;
          }

          for(int j=0;j<randVel;j++){
          int randdir=rand()%7; //varia entre 0-8
          vector<int> retpos;
          switch (randdir) {
            case 0: //cima
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),0,-1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 1: //cimadir
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),1,-1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 2: //dir
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),1,0);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 3: //baixodir
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),1,1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 4: //baixo
            retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),0,1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 5: //baixoesq
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),-1,1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 6: //esq
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),-1,0);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
            case 7: //cimaesq
              retpos = map.checkpos(p1.Navios[i].getX(), p1.Navios[i].getY(),-1,-1);
              if(retpos[0]!=-1){
                int id = map.getidNavioemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY());
                map.removeidemCelulaXY(p1.Navios[i].getX(),p1.Navios[i].getY(),id);
                map.addidemCelulaXY(retpos[0],retpos[1],id);
                p1.Navios[i].setX(retpos[0]);
                p1.Navios[i].setY(retpos[1]);
              }
            break;
          }
        }
        }
        continua=true;
	    }
			if (tokens[0] == "compranav"){
        if((p1.getMoedas()-defs.getPrecoNavio()) >=0){
          if(tokens[1] == "V" || tokens[1] == "G" ||
          tokens[1] == "E" ||tokens[1] == "F" ||
          tokens[1] == "S"){

            //passar primeiro caracter de tokens[1] para char
            char cDummy[1]; strcpy(cDummy, tokens[1].c_str());
            char c = cDummy[0];

            vector <int> pos  = map.getPortoPrinc();
            if(pos[0]==-1){
              //nao pode comprar porque nao tem portos amigos;
              cout << "erro na compra";
              Consola::getch();
            }
            else{
              int id = p1.compranav(pos[0],pos[1],c);
              p1.setMoedas((p1.getMoedas()-defs.getPrecoNavio()));
              map.addIdtoCelula(pos[0],pos[1],id);
              //p1.printNavios((map.getColunas()*2) + 5,2);
              //map.printIdCelula(pos[0],pos[1]);
              //Consola::getch();
            }
          }

        }
        else{
          // moedas insuficientes;
					cout << "erro na compra - moedas insuficientes";
        }
	    }if (tokens[0] == "compranavdb"){ //compranavdb x y tipo
          int x=stoi(tokens[1]);
          int y=stoi(tokens[2]);

          //passar primeiro caracter de tokens[1] para char
          char cDummy[1]; strcpy(cDummy, tokens[3].c_str());
          char c = cDummy[0];

          int id = p1.compranav(x,y,c);
          map.addIdtoCelula(x,y,id);

	    }
			if (tokens[0] == "vendenav"){

	    }
			if (tokens[0] == "lista"){

	    }
			if (tokens[0] == "compra"){

	    }
			if (tokens[0] == "vende"){

	    }
			if (tokens[0] == "move"){

	    }
			if (tokens[0] == "auto"){

	    }
			if (tokens[0] == "stop"){

	    }
			if (tokens[0] == "evpos"){

	    }
			if (tokens[0] == "evnav"){

	    }
			if (tokens[0] == "moedas"){

	    }
			if (tokens[0] == "vaipara"){

	    }
			if (tokens[0] == "vaipara"){

	    }
			if (tokens[0] == "comprasold"){

	    }
			if (tokens[0] == "saveg"){

	    }
			if (tokens[0] == "loadg"){

	    }
			if (tokens[0] == "delg"){

	    }

	    if (tokens[0] == "exit"){
	      cout << "\n Sair"
				<<"Pontuacao: "<< p1.getMoedas()/*+preço de custo dos navios*/
				<< endl;
				exit(0);
	    }



	    tokens.erase (tokens.begin(),tokens.end());
	    }




}
    return 0;
}
