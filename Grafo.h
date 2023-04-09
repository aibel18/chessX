#ifndef H_Grafo
#define H_Grafo

//clase Vertice
class Vertice{
public:
	void *contenido;//informacion
	int num_aristas;//numero de arsitas
	class Arista *aristas;//arreglode aristas

	//Vertice * padre;//vertice siguietne

	unsigned int profundidad:3;

	Vertice(void* con){
		num_aristas =0;

		contenido =con;
		aristas=0;
		profundidad = 0;
		//padre =0;
	}
};

//clase Arista
class Arista{
public:
	float contenido;//contenido de la arsita
	Vertice * destino;//vertice destino

	Arista * siguiente;//arista siguiente

	Arista(float con,Vertice *de){
		contenido = con;
		destino =de;

		siguiente =0;
	}
};

//clase Grafo
class Grafo{
public:

	Vertice* inicio;//vertice inicio

	int num_Vertices;//numero de vertices

	Grafo();

	//verifica si el nodo esta vacio
	bool GrafoVacio ();
	//inserta un vertice
	void InsertarVertice(void *);
	void InsertarVertice(Vertice*,void *);
	//inserta un arista
    void InsertarArista(Vertice *, Vertice *, float );
	//inserta una arista y la ordena con respecto alas demas
	void InsertarAristaO(Vertice *&, Vertice *&, float );
	//busca una arista
	Arista* buscaArista(Vertice *, Vertice *);
	//busca un vertice
	Vertice* buscarVertice (void*);

	//borra una arsita
    void BorrarArista (Vertice *, Vertice *);
	
	//ordena las aristas de mayor a menor las aristas de un vertice
	void OrdenarArista(Vertice*&);
	//desconecta el vertie
    void DesconectarVertice (Vertice *);
	//eleimina el vertice
	void EliminarVertice(Vertice*);




	//eliminar aristas del todos los vertices
	void EliminarAristas();

	void EliminarAristasRestantes(int&,Arista*);
	//elimina el grafo
	void EliminarGrafo(Vertice*&);
	//muestra el grafo
	void MostrarGrafo();

	//copia un grafo 
    void CopiarGrafo (Grafo gr);
	//destructor
    ~Grafo();

};

#endif