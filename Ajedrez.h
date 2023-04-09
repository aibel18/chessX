#ifndef H_Ajedrez
#define H_Ajedrez

#include "Grafo.h"
#include "Botones.h"

#include <windows.h>

struct ocho{
	int numero:8;

	void operator=( int n){

		numero = n;

	}
	bool operator <( int n){

		return numero < n;

	}
	bool operator>( int n){

		return numero > n;

	}
	bool operator>=( int n){

		return numero >= n;

	}
	bool operator<=( int n){

		return numero <= n;

	}

	bool operator==( int n){

		return numero == n;

	}

	bool operator!=( int n){

		return numero != n;

	}


};

void operator+=( float &f ,ocho &o);


class Ficha{
public:

	int posx:4,posy:4;
	Ficha *siguiente;


	Ficha(int x,int y){

		posx = x;
		posy = y;

		siguiente =0;
	}

	void setValores(int,int);
	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8])){}
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8])){}

	virtual void nuevo(class Ficha*&){}

	virtual void evaluar(float & f,ocho ((*tablero) [8][8])){}

	virtual Ficha* buscar(){ return 0;}
	virtual void dibujar(Imagen&,int){ }

};

class Fichas{
public:

	Ficha *inicio;
	Ficha *fin;

	int num;

	Fichas(){
		inicio=0;
		fin =0;
		num = 0;
	}

	~Fichas(){
		eliminar();
	}

	void insertar(int ,int);
	void insertar(class Peon&);
	void insertar(class Caballo&);
	void insertar(class Alfil&);
	void insertar(class Torre&);
	void insertar(class Reyna&);
	void insertar(class Rey&);

	void eliminar();

	void borrar(int ,int);

	void operator = (Fichas &);

};


class Peon : public Ficha{
public:

	Peon(int x,int y):Ficha(x,y){
	}

	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void nuevo(Ficha* &f){

		f = new Peon(posx,posy);
	}

	virtual void evaluar(float &,ocho ((*tablero) [8][8]));
	virtual void dibujar(Imagen&,int);

};


class Caballo : public Ficha{
public:
	Caballo(int x,int y):Ficha(x,y){
	}

	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));

	virtual void nuevo(Ficha* &f){

		f = new Caballo(posx,posy);
	}
	virtual void evaluar(float &,ocho ((*tablero) [8][8]));
	virtual void dibujar(Imagen&,int);

};
class Alfil : public Ficha{
public:
	Alfil(int x,int y):Ficha(x,y){
	}
	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));

	virtual void nuevo(Ficha* &f){

		f = new Alfil(posx,posy);
	}
	virtual void evaluar(float &,ocho ((*tablero) [8][8]));
	virtual void dibujar(Imagen&,int);

};
class Torre : public Ficha{
public:
	Torre(int x,int y):Ficha(x,y){
	}
	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));

	virtual void nuevo(Ficha* &f){

		f = new Torre(posx,posy);
	}
	virtual void evaluar(float &,ocho ((*tablero) [8][8]));

	virtual void dibujar(Imagen&,int);

};
class Reyna : public Ficha{
public:
	Reyna(int x,int y):Ficha(x,y){
	}
	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));

	virtual void nuevo(Ficha* &f){

		f = new Reyna(posx,posy);
	}
	virtual void evaluar(float &,ocho ((*tablero) [8][8]));
	virtual void dibujar(Imagen&,int);

};
class Rey : public Ficha{
public:
	Rey(int x,int y):Ficha(x,y){
	}
	virtual void mover1(class Fichas&,ocho ((*tablero) [8][8]));
	virtual void mover2(class Fichas&,ocho ((*tablero) [8][8]));

	virtual void nuevo(Ficha* &f){

		f = new Rey(posx,posy);
	}
	virtual void evaluar(float &,ocho ((*tablero) [8][8]));
	virtual Ficha* buscar(){
		return this;
	}
	virtual void dibujar(Imagen&,int);

};

class Ajedrez{

public:
	ocho tablero[8][8];

	Fichas fichasMax;
	Fichas fichasMin;

	Ajedrez(ocho ((*ta) [8][8])){

		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				tablero[i][j] = (*ta)[i][j];
	}

	void cargar(ocho ((*ta)[8][8])){

		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				tablero[i][j] = (*ta)[i][j];
	}

	void inicializar();

	float funcion();

	void jugadasMax(Grafo&, Vertice*);
	void jugadasMin(Grafo&, Vertice*);

	void dibujar(HDC& );
	void dibujar2(Imagen& imagen );

};

class Juego{
public:

	int b;

	Ajedrez *ajedrez;
	Grafo grafo;
	bool turno;
	Juego(){

		b=0;
		ocho tableroI [8][8]= {{4 ,1,0,0,0,0,-1,-4}
							 ,{3 ,1,0,0,0,0,-1,-3}
							 ,{3 ,1,0,0,0,0,-1,-3}
							 ,{10,1,0,0,0,0,-1,-10}
							 ,{50,1,0,0,0,0,-1,-50}
							 ,{3 ,1,0,0,0,0,-1,-3}
							 ,{3 ,1,0,0,0,0,-1,-3}
							 ,{4 ,1,0,0,0,0,-1,-4}};

		ajedrez = new Ajedrez(&tableroI);

		ajedrez->inicializar();

		turno = true;

	}

	void jugar(int,int,int,int);

	void turnoMaquina();

	void turnoMaquina2();

	void turnoUsuario(int,int,int,int);

};
void sucesoresMax(Grafo &g , Vertice *v);
void sucesoresMin(Grafo &g , Vertice *v);
float valorNodo(Vertice*);
bool limiteProfundidad( Vertice*);
float alphaBetaMax(Grafo&, Vertice* v, float x , float b);
float alphaBetaMin(Grafo&, Vertice* v, float x , float b);

Ajedrez* buscar( float &f, Vertice *v );


#endif
