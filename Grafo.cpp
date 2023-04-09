#include "Grafo.h"
#include "Ajedrez.h"
#include <iostream>

using namespace std;

Grafo::Grafo(){
	inicio = 0;
	num_Vertices=0;
}
Grafo::~Grafo(){
	EliminarGrafo(inicio);

	inicio =0;	
}
bool Grafo::GrafoVacio(){

	return inicio==0;
}
//inserta un vertice
void Grafo::InsertarVertice(void * dato){
	if(inicio==0){
		inicio = new Vertice(dato);		

		num_Vertices =1;
	}
	
}

void Grafo::InsertarVertice(Vertice* v,void * dato){

	Vertice * nuevo = new Vertice(dato);

	InsertarArista(v,nuevo,0);

	num_Vertices++;

}

//inserta una arsita
void Grafo::InsertarArista(Vertice *o, Vertice *d, float valor){


	Arista* nuevo = new Arista(valor,d);

	nuevo->siguiente = o->aristas;

	d->profundidad = o->profundidad+1;

	o->aristas = nuevo;
	o->num_aristas++;

}
//inserta una arsita ordenada
void Grafo::InsertarAristaO(Vertice *&o, Vertice *&d, float valor){

	if(o->aristas==0){
		o->aristas = new Arista(valor,d);

	}
	else{
		Arista* temp = o->aristas;
		Arista* p_temp = 0;
		while(temp->contenido > valor){
			p_temp = temp;
			temp = temp->siguiente;
			if(temp==0){
				p_temp->siguiente =new Arista(valor,d);
				o->num_aristas++;
				return;
			}
		}
		if(p_temp==0){
			Arista* nuevo = new Arista(valor,d);
			nuevo->siguiente = temp;
			o->aristas = nuevo;
		}
		else{
			Arista* nuevo = new Arista(valor,d);
			nuevo->siguiente = temp;
			p_temp->siguiente =nuevo;
		}		
	}
	o->num_aristas++;
}
//busca una arista entre dos vertices
Arista* Grafo::buscaArista(Vertice* o,Vertice *d){

	Arista* temp = o->aristas;

	while(temp != 0){
		if(temp->destino ==d)
			return temp;
		temp=temp->siguiente;
	}
	return 0;
}

//borra una arista entre dos vertices
void Grafo::BorrarArista(Vertice *o, Vertice *d){

	Arista* temp = o->aristas;
	Arista* p_temp = 0;

	while(temp != 0){
		if(temp->destino ==d)
			break;
		p_temp = temp;
		temp = temp->siguiente;
	}
	if(temp){

		if(p_temp!=0)
			p_temp->siguiente = temp->siguiente;
			
		else
			o->aristas = temp->siguiente;

		temp->siguiente =0;
		temp->destino = 0;

		temp->contenido =0;
		delete temp;
		temp=0;
		o->num_aristas--;
	}
}
//ordena las aristas de un veritce de mayor a menor
void Grafo::OrdenarArista(Vertice* &v){

	Arista* temp = v->aristas;
	Arista* temp2 = v->aristas->siguiente;
	v->aristas = temp2;
	Arista* p_temp2 = 0;
	while(temp2 && temp->contenido < temp2->contenido){
		p_temp2 = temp2;
		temp2=temp2->siguiente;
	}
	if(p_temp2){
		temp->siguiente = p_temp2->siguiente;
		p_temp2->siguiente = temp;
		return ;
	}
	else{
		v->aristas = temp;
		return;
	}
}

void Grafo::EliminarAristasRestantes(int & n , Arista* a){

	Arista * b_temp = 0;

	while(a){
		b_temp = a;		

		a = a->siguiente;

		b_temp->destino->contenido;

		delete ((Ajedrez*)b_temp->destino->contenido);
		b_temp->destino->contenido =0;

		delete b_temp->destino;
		b_temp->destino = 0;

		num_Vertices--;


		b_temp->siguiente =0;

		b_temp->contenido =0;
		delete b_temp;
		b_temp=0;
		n--;
	}

}
//desconecta un vertice del grafo
void Grafo::DesconectarVertice(Vertice *v){
	
	Arista * b_temp = 0;

	while(v->aristas){
		b_temp = v->aristas;
		v->aristas = v->aristas->siguiente;

		b_temp->siguiente =0;
		b_temp->destino = 0;

		b_temp->contenido =0;
		delete b_temp;
		b_temp=0;
		
	}
	v->num_aristas=0;
}


//elimina todo el arbol
void Grafo::EliminarGrafo(Vertice * &v ){
	
	Vertice * b_temp = v;

	if(b_temp){

		Arista * a_temp = b_temp->aristas;

		while(a_temp){

			EliminarGrafo(a_temp->destino);
			a_temp = a_temp->siguiente;		
		}
		DesconectarVertice(b_temp);

		delete ((Ajedrez*)b_temp->contenido);
		b_temp->contenido =0;

		delete b_temp;
		b_temp=0;

//		num_Vertices--;
	}
	num_Vertices =0;
}

