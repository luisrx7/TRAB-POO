#include "Celula.h"
#include <vector>
#define LOT 100 //lotacao maxima

Celula::Celula(int x0, int y0, char c0):x(x0),y(y0),c(c0){
	switch (c) {
 case '.': //mar
		peixe = 1000;
	 lot = 1;
	 break;
 case '+': //terra
	peixe = 0;
	 lot = 0;
	 break;
 default: //porto
	peixe = 1000;
	 lot = LOT;
	 break;
 }
}


void Celula::setX(int x0) {
	x = x0;
}
void Celula::setY(int y0) {
	y = y0;
}

void Celula::setCaract(char c0){
	 c = c0;
}
void Celula::addId(int id){
	ids.push_back(id);
}


int Celula::getId()const{
	return ids[0];
}

int Celula::getqntbarcos()const{
	return ids.size();
}


void Celula::removeId(int id){
	for(unsigned int i=0;i<ids.size();i++){
		if(id== ids[i]){
			ids.erase(ids.begin()+i);
		}
	}
}

vector<int> Celula::getidsNavios()const{
	return ids;
}

int Celula::getX()const {
	return x;
}
int Celula::getY()const {
	return y;
}

char Celula::getCaract() const{
	return c;
}

// obter um objecto string com a descricao textual do seu conteudo (formato  (x  / y) ).
string Celula::getAsString()const {
	ostringstream oss;
	oss << " ( " << x << "," << y << ") ";
	return oss.str();
}
