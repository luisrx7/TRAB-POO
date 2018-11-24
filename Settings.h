#ifndef SETTINGS_H
#define SETTINGS_H
using namespace std;
class Settings{
   int ncols,nlinhas,probpirata;
   //moedas=1000,probpirata=20,preconavio=100,precosoldado=1,precovendpeixe=1,precocompmercad=2,precovendmercad=3,soldadosport=100,probevento=30,probtempestade=30,probsereias=30,probalmaria=20,probmotim=20;

public:
  Settings();
  int getLinhas()const;
	int getColunas()const;
  int getProbpirata()const;


	void setLinhas(int linhas0);
	void setColunas(int colunas0);
  void setProbpirata(int probpirata0);

};

#endif
