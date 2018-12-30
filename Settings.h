#ifndef SETTINGS_H
#define SETTINGS_H
using namespace std;
class Settings{
   int ncols,nlinhas,probpirata,soldadosport,preconavio;
   //moedas=1000,probpirata=20,preconavio=100,precosoldado=1,precovendpeixe=1,precocompmercad=2,precovendmercad=3,soldadosport=100,probevento=30,probtempestade=30,probsereias=30,probalmaria=20,probmotim=20;

public:
const  int tpeixeVMAX = 40,tpeixeGMAX = 70,tpeixeEMAX = 20,tpeixeFMAX = 0,tpeixeSMAX = 40;
const  int capAguaVMAX = 200, capAguaGMAX = 400,capAguaEMAX = 100,capAguaFMAX = 500,capAguaSMAX = 40;
const  int velVMAX = 2,velGMAX = 1,velEMAX = 1,velFMAX = 2,velSMAX = 2;
int turnos=0;

  Settings();
  int getLinhas()const;
	int getColunas()const;
  int getProbpirata()const;
  int getSoldadosPort()const;
  int getPrecoNavio()const;

	void setLinhas(int linhas0);
	void setColunas(int colunas0);
  void setProbpirata(int probpirata0);
  void setSoldadosPort(int soldadosport0);
  void setPrecoNavio(int preconavio0);


};

#endif
