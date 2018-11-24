#include "Mapa.h"
#include "Celula.h"

/*___________________Mapa______________________________________________*/
Mapa::Mapa( int linhas0,  int colunas0, vector<char> m):linhas(linhas0), colunas(colunas0)//,map(nullptr)
{
  vector<Celula> mapa;

  int x=0,y=0;
  for(int i=0;i<m.size();i++){

    mapa[i].setCar(m[i]);
    mapa[i].setY(y));
    mapa[i].setX(x);
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
	return this->cells[x][y].getCaract();
}
char Mapa::getMapPos(int x, int y) const {
	return 'c'; //[DEBUG] estava isto.. mas é para alterar ((map + x) + y);
}
//
//void Mapa::setMapPos(char * aux[]/*int x, int y, char c*/){
//	*(*(map+x)+y) = c;
//	**map = **aux;		//trying
//}
//
//void Mapa::setMap() {
//	for (int i = 0; i < getColunas(); i++) {
//		for (int j = 0; j < getLinhas(); j++) {
//			//map[i][j] = '.';
//			//setMapPos(i, j, '.');
//		}
//	}
//}

void Mapa::novoVect() {
	cells.push_back(vector<Celula>());
}

void Mapa::adicionaCell( int x, int y, char tipo){
	//Celula celulas = new Celula(x, y,tipo);

	cells[x].push_back(Celula(x, y, tipo));
}

/*_________________Posicao___________________________________________*/
//bool Mapa::estaVazia(const Ponto &posicao) const
//{
//	vector <Porto> portos;
//	Porto por(x, y, tipo);
//	portos.push_back(por);
//}

// Ponto Mapa::getPosicaoVaziaAleat() const
// {
// 	int x, y;
//
// 	//Ponto posicao( x, y);
// 	do {
// 		x = rand() % 1 + linhas;
// 		y = rand() % 1 + colunas;
// 	} while (!estaVazia(/*posicao*/1));
// 	return 1/*posicao*/;
// }
/*_________________Puxa coisas___________________________________________*/
/*vector<Navio*> Mapa::getNavios() const{
	 return navios;
}*/

//vector<Porto*> Mapa::getPortos() const{
//	return portos;
//}

/*_________________Imprime para teste_____________________________________*/
string Mapa::getAsString() const
{
	ostringstream oss;
	oss << "Mapa: " //<< id_mapa
		<< "	dimensao: " << linhas
		<< " " << colunas
		<< endl;
		return oss.str();
}



// [DEBUG] para apagar
//void Mapa::adicionaMar(int x, int y){
//	//Mar aux(x, y);
//	Mar * pa = new Mar(x,y);
//
//	//*pa = aux;
//	//*aux.ne;
//
//	mares.push_back(pa);
//}
//
//void Mapa::adicionaTerra(int x, int y) {
//	Terra aux(x, y);
//
//	terras.push_back(aux);
//}
