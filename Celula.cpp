#include "Celula.h"

#define LOT 100

Celula::Celula(int x0, int y0, char c0):x(x0),y(y0), c(c0){
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
