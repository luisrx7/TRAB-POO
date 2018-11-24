#ifndef JOGADOR_H
#define JOGADOR_H
using namespace std;
class Jogador{
   int moedas;

public:
  Jogador();
  int getMoedas()const;

	void setMoedas(int moedas0);
  string getAsString() const;
};

#endif
