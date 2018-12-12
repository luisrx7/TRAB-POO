#include "Mapa.h"
#include "Celula.h"
#include <ctype.h>
#include "Porto.h"
#include "Consola.h"
#include "Jogador.h"
#include "ObjetosGlobais.h"
/*___________________Mapa______________________________________________*/
Mapa::Mapa( int linhas0,  int colunas0, vector<char> m):linhas(linhas0), colunas(colunas0)//,map(nullptr)
{
  Celula *c1;
  Porto *p1;
  int x=0,y=0;
  for(unsigned int i=0;i<m.size();i++){
    c1 = new Celula(x,y,m[i]);
	  /*c1->setCaract(m[i]);
	  c1->setY(y);
	  c1->setX(x);*/
    grelha.push_back(*c1);
  /*  grelhagrelha[i].setCar(m[i]);
    grelha[i].setY(y));
    grelha[i].setX(x);*/
    x++;
    if(x==colunas) {
      x=0;
      y++;
    }
  }
  x=0;y=0;
  for(unsigned int i=0;i < grelha.size();i++){

    if(isalpha(grelha[i].getCaract())!=0){
      p1 = new Porto(x,y,grelha[i].getCaract());
      if(isupper(grelha[i].getCaract())!=0){
        p1->setRelacaoJogador(1);
      }
      else{
        p1->setRelacaoJogador(-1);
      }
      Portos.push_back(*p1);
    }

    x++;
    if(x==colunas) {
      x=0;
      y++;
    }
  }

}

//Mapa::~Mapa(){
//}

int Mapa::getLinhas() const{
	return linhas;
}

int Mapa::getColunas() const{
	return colunas;
}

vector <int> Mapa::getPortoPrinc()const{
  vector<int> pos;
  for(unsigned int i =0;i<Portos.size();i++){
    if(isalpha(Portos[i].getChar())!=0 &&
     isupper(Portos[i].getChar())!=0 &&
     Portos[i].getRelacaoJogador() > 0) {
       pos.push_back(Portos[i].getX());
       pos.push_back(Portos[i].getY());
       return pos;
    }
    else{
      pos.push_back(-1);
      return pos;
    }

  }
}

void Mapa::setLinhas(int linhas0)
{
	if (linhas0 < 10)
		linhas0 = 10;
	linhas = linhas0;
}

void Mapa::setColunas(int colunas0)
{
	if (colunas0 < 20)
		colunas0 = 20;
	colunas = colunas0;
}

char Mapa::getCelula(int x, int y) const {
	return grelha[x].getCaract();
}


vector<Porto> Mapa::getPortos() const{
	return Portos;
}

void Mapa::printPortos()const{
  for(unsigned int i = 0;i<Portos.size();i++){
    cout << Portos[i].getAsString();
  }
}



void Mapa::printmapa()const{
  int x=0,y=0;
  Consola::setScreenSize((colunas*2)+80,(linhas*2)+20);
  Consola::SetColorAndBackground(Consola::BRANCO,Consola::PRETO);
  Consola::gotoxy(0,0);
  cout << p1.getAsString();
  Consola::gotoxy(0,1);
  for(int i=0,c=0;i<colunas;i++){
    if(i%2==0){
      Consola::gotoxy(2+(i*2),1);
      cout << c;
      c+=2;
    }
  }
  Consola::gotoxy(0,2);
  for(int i=0,c=0;i<linhas;i++){
    if(i%2==0){
      Consola::gotoxy(0,2+(i*2));
      cout << c;
      c+=2;
    }
  }
  bool pinta = false;
for( int j=1;j<=(linhas);j++){
  cout << endl;
  pinta = !pinta;
  for( int i=1;i<=(colunas);i++){

    if(pinta==true){
      Consola::SetColorAndBackground(Consola::PRETO,Consola::BRANCO_CLARO);
    }
    else{
      Consola::SetColorAndBackground(Consola::PRETO,Consola::BRANCO);
    }
    pinta = !pinta;

    Consola::gotoxy(i*2,j*2);
    if(grelha[((j-1)*colunas)+(i-1)].getCaract() == '.' && grelha[((j-1)*colunas)+(i-1)].getqntbarcos() ==1){ //se tirver barco e se for mar
      Consola::SetColorAndBackground(Consola::PRETO,Consola::VERDE_CLARO);
      int id = grelha[((j-1)*colunas)+(i-1)].getId();
      cout << id;
      Consola::gotoxy(i*2,(j*2)+1);
      cout << p1.getTipoNavviaID(id) << ' ';
    }
    else{ //resto incluindo mar sem navio
      cout << ' '<< ' ';
      Consola::gotoxy(i*2,(j*2)+1);
      cout << grelha[((j-1)*colunas)+(i-1)].getCaract() << ' ';
    }
    x+=2;
    if(x==colunas*2) {
      x=0;
      y++;
    }
  }
}
Consola::SetColorAndBackground(Consola::BRANCO,Consola::PRETO); //texto  backgroud
  p1.printNavios((colunas*2) + 5 ,2);
  Consola::gotoxy(0,linhas*2+1);
}

int Mapa::getidNavioemCelulaXY(int x0,int y0)const{
  return grelha[x0+colunas*y0].getId();
}

void Mapa::removeidemCelulaXY(int x0,int y0,int id0){
    grelha[x0+colunas*y0].removeId(id0);
}

void Mapa::addidemCelulaXY(int x0,int y0,int id0){
    grelha[x0+colunas*y0].addId(id0);
}

vector<int> Mapa::checkpos(int x,int y,int xobj,int yobj){
  int x0=x, y0=y;
  vector<int> pos;
  if(y==0 && yobj == -1) y = linhas-1;  //limite superior
  if(y==linhas-1 && yobj == 1) y = 0;  //limite inferior
  if(x==0 && xobj == -1) x = colunas-1;  //limite esq
  if(x==colunas-1 && xobj == 1) x = 0;  //limite dir

  if(x==x0)x=x+xobj;
  if(y==y0)y=y+yobj;

  if(grelha[x+colunas*y].getCaract() == '.' && grelha[x+colunas*y].getqntbarcos() ==0){ //verificar que é mar e nao tem barco
    pos.push_back(x);
    pos.push_back(y);
  }
  else{
    pos.push_back(-1);
  }
  return pos;
}

void Mapa::addIdtoCelula(int x0,int y0,int id){
  grelha[x0 + colunas*y0].addId(id);
}

void Mapa::remIdtoCelula(int x0,int y0,int id){
  grelha[x0 + colunas*y0].removeId(id);
}

void Mapa::printIdCelula(int x0,int y0){
  vector<int> idsRecebidos = grelha[x0 + colunas*y0].getidsNavios();
  for(unsigned int i=0;i<idsRecebidos.size();i++){
    cout << idsRecebidos[i] << "  ";
  }
}

string Mapa::getAsString() const
{
	ostringstream oss;
	oss << "\n" << "Mapa: " //<< id_mapa
		<< "	dimensao: " << linhas
		<< " " << colunas
		<< endl;
		return oss.str();
}
