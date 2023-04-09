#include "Ajedrez.h"
#include "Botones.h"


void operator+=( float &f ,ocho &o){

		f +=o.numero;

};

void Fichas::insertar(int x, int y){
	if(!inicio){
		inicio =  new Ficha(x,y);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Ficha(x,y);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Peon& p){
	if(!inicio){
		inicio =  new Peon(p.posx,p.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Peon(p.posx,p.posy);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Caballo& c){
	if(!inicio){
		inicio =  new Caballo(c.posx,c.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Caballo(c.posx,c.posy);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Alfil& c){
	if(!inicio){
		inicio =  new Alfil(c.posx,c.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Alfil(c.posx,c.posy);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Torre& c){
	if(!inicio){
		inicio =  new Torre(c.posx,c.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Torre(c.posx,c.posy);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Reyna& c){
	if(!inicio){
		inicio =  new Reyna(c.posx,c.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Reyna(c.posx,c.posy);
		fin = fin->siguiente;
		num++;
	}
}
void Fichas::insertar(Rey& c){
	if(!inicio){
		inicio =  new Rey(c.posx,c.posy);
		fin = inicio;
		num=1;
	}
	else{
		fin->siguiente = new Rey(c.posx,c.posy);
		fin = fin->siguiente;
		num++;
	}
}


void Fichas::operator =( Fichas & f){

	eliminar();

	Ficha* temp = f.inicio;

	temp->nuevo(inicio);

	fin = inicio;
	temp = temp->siguiente;

		while( temp){
			temp->nuevo(fin->siguiente);

			fin = fin->siguiente;

			temp = temp->siguiente;
		}
	num = f.num;
}

void Fichas::eliminar(){

	Ficha* temp = inicio;
	Ficha* eliminar;
	while( temp){

		eliminar = temp;

		temp = temp->siguiente;

		eliminar->siguiente =0;

		delete eliminar;
		eliminar =0;


	}
	inicio = fin =  0;
	num=0;

}

void Fichas::borrar(int x,int y){


	Ficha* temp = inicio;
	Ficha* p_temp = 0;

	while(temp != 0){
		if(temp->posx == x && temp->posy == y)
			break;
		p_temp = temp;
		temp = temp->siguiente;
	}
	if(temp){

		if(p_temp!=0)
			p_temp->siguiente = temp->siguiente;

		else
			inicio = temp->siguiente;

		temp->siguiente =0;
		temp->posx = temp->posy  =0;
		delete temp;
		temp=0;
		num--;
	}
}

void Ficha::setValores(int x, int y){

	posx = x; posy = y;

}

void Peon::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	if( (*tablero)[posx][posy+1] == 0 ){
		f.insertar(posx,posy+1);

		if(posy == 1 && (*tablero)[posx][posy+2]== 0 )
			f.insertar(posx,posy+2);
	}

	if( posx - 1 > -1 && (*tablero)[posx - 1][posy+1] < 0 )
		f.insertar(posx -1,posy+1);

	if( posx + 1 < 8 && (*tablero)[posx +1][posy+1] < 0 )
		f.insertar(posx +1 ,posy+1);

}
void Peon::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+= (*tablero)[posx][posy].numero;;

}
void Peon::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	if( (*tablero)[posx][posy-1] == 0 ){
		f.insertar(posx,posy-1);

		if(posy == 6 && (*tablero)[posx][posy-2]== 0 )
			f.insertar(posx,posy-2);
	}


	if( posx - 1 > -1 && (*tablero)[posx - 1][posy-1] > 0 )
		f.insertar(posx -1,posy-1);


	if(posx + 1 < 8 && (*tablero)[posx +1][posy-1] > 0 )
		f.insertar(posx +1 ,posy-1);

}

void Peon::dibujar(Imagen& imagen,int i){

	if(i)
		imagen.cargarImagen("peonB.bmp",posy*72+30,posx*72 +40,50,60);
	else
		imagen.cargarImagen("peonN.bmp",posy*72+30,posx*72 +40,50,60);
}
void Caballo::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	int x = 1;
	int y = 2;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){

				if( posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0 ){
					f.insertar(posx+x,posy+y);
				}

				x = -x;
			}
			y = -y;
		}
		x = 2;
		y = 1;
	}


}
void Caballo::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	int x = 1;
	int y = 2;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){

				if( posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0 ){
					f.insertar(posx+x,posy+y);
				}

				x = -x;
			}
			y = -y;
		}
		x = 2;
		y = 1;
	}
}
void Caballo::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+=(*tablero)[posx][posy];;

}
void Caballo::dibujar(Imagen& imagen,int i){
;
	if(i)
		imagen.cargarImagen("caballoB.bmp",posy*72+30,posx*72+40,50,60);
	else
		imagen.cargarImagen("caballoN.bmp",posy*72+30,posx*72+40,50,60);
}
void Alfil::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx =1, x = 1;
	int ty =1, y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] < 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty;

		}
		y = ty = -ty;
	}

}
void Alfil::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx =1, x = 1;
	int ty =1, y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] > 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty;

		}
		y = ty = -ty;
	}


}
void Alfil::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+=(*tablero)[posx][posy];;

}
void Alfil::dibujar(Imagen& imagen,int i){

	if(i)
		imagen.cargarImagen("alfilB.bmp",posy*72+30,posx*72+40,50,60);
	else
		imagen.cargarImagen("alfilN.bmp",posy*72+30,posx*72+40,50,60);
}
void Torre::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx = 1, x = 1;
	int ty = 0, y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] < 0)
					//comido
					break;


				x +=tx;
				y +=ty;


			}
			x = tx = -tx;
			y = ty = -ty;

		}
		ty = y = x;
		tx = x = 0;

	}

}
void Torre::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx = 1, x = 1;
	int ty = 0, y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] > 0)
					//comido
					break;


				x +=tx;
				y +=ty;



			}
			x = tx = -tx;
			y = ty = -ty;

		}
		ty = y = x;
		tx = x = 0;

	}

}
void Torre::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+=(*tablero)[posx][posy];;

}
void Torre::dibujar(Imagen& imagen,int i){

	if(i)
		imagen.cargarImagen("torreB.bmp",posy*72+30,posx*72+40,50,60);
	else
		imagen.cargarImagen("torreN.bmp",posy*72+30,posx*72+40,50,60);
}
void Reyna::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx =1, x = 1;
	int ty =1, y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] < 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty;

		}
		y = ty = -ty;
	}

	tx = x = 1;
	ty = y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

				if((*tablero)[posx+x][posy+y] < 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty = -ty;

		}
		ty = y = x;
		tx = x = 0;

	}

}
void Reyna::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	int tx =1, x = 1;
	int ty =1, y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);
				if((*tablero)[posx+x][posy+y] > 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty;

		}
		y = ty = -ty;
	}

	tx = x = 1;
	ty = y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			while(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);
				if((*tablero)[posx+x][posy+y] > 0)
					//comido
					break;

				x +=tx;
				y +=ty;

			}
			x = tx = -tx;
			y = ty = -ty;

		}
		ty = y = x;
		tx = x = 0;

	}

}
void Reyna::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+=(*tablero)[posx][posy];

}
void Reyna::dibujar(Imagen& imagen,int i){

	if(i)
		imagen.cargarImagen("reynaB.bmp",posy*72+30,posx*72+40,50,60);
	else
		imagen.cargarImagen("reynaN.bmp",posy*72+30,posx*72+40,50,60);
}
void Rey::mover1(class Fichas& f,ocho ((*tablero) [8][8])){

	int x = 1;
	int y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			if(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

			}
			x = -x;
		}
		y = -y;
	}

	x = 1;
	y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			if(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] <= 0){

				f.insertar(posx+x,posy+y);

			}
			x = -x;
			y = -y;

		}
		y = x;
		x = 0;

	}

}
void Rey::mover2(class Fichas& f,ocho ((*tablero) [8][8])){

	int x = 1;
	int y = 1;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			if(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);

			}
			x = -x;
		}
		y = -y;
	}

	x = 1;
	y = 0;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			if(posx+x >= 0 && posx+x < 8 && posy+y >=0 && posy+y < 8 && (*tablero)[posx+x][posy+y] >= 0){

				f.insertar(posx+x,posy+y);

			}
			x = -x;
			y = -y;

		}
		y = x;
		x = 0;

	}

}
void Rey::evaluar(float& f,ocho ((*tablero) [8][8])){

	f+=(*tablero)[posx][posy];

	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){

			if(posx+j >= 0 && posx+j < 8 && posy+i >=0 && posy+i < 8)
				f += (*tablero)[posx+j][posy+i];

		}

	}

}

void Rey::dibujar(Imagen& imagen,int i){

	if(i)
		imagen.cargarImagen("reyB.bmp",posy*72+30,posx*72+40,50,60);
	else
		imagen.cargarImagen("reyN.bmp",posy*72+30,posx*72+40,50,60);
}
void Ajedrez::jugadasMax(Grafo& g, Vertice* vp){

	Ficha *temp = fichasMax.inicio;

	Fichas fichasNuevas;
	Ficha * nueva;

	int tempX,tempY;

	while( temp ){

		nueva =0;
		temp->mover1(fichasNuevas,&tablero);

		nueva = fichasNuevas.inicio;

		tempX = temp->posx;
		tempY = temp->posy;

		while( nueva ){

			Ajedrez *ajedrez = new Ajedrez(&tablero);

			temp->setValores(nueva->posx,nueva->posy);


			ajedrez->fichasMax = fichasMax;

			ajedrez->fichasMin = fichasMin;

			if(tablero[nueva->posx][nueva->posy] < 0 )

				ajedrez->fichasMin.borrar(nueva->posx,nueva->posy);

			ajedrez->tablero[tempX][tempY] = 0;

			ajedrez->tablero[nueva->posx][nueva->posy] = tablero[tempX][tempY];

			g.InsertarVertice(vp,ajedrez);

			nueva = nueva->siguiente;

		}
		temp->setValores(tempX,tempY);
		fichasNuevas.eliminar();

		temp = temp->siguiente;
	}
}
void Ajedrez::jugadasMin(Grafo& g, Vertice* vp){

	Ficha *temp = fichasMin.inicio;

	Fichas fichasNuevas;
	Ficha * nueva;

	int tempX,tempY;

	while( temp ){

		nueva =0;
		temp->mover2(fichasNuevas,&tablero);

		nueva = fichasNuevas.inicio;

		tempX = temp->posx;
		tempY = temp->posy;

		while( nueva ){

			Ajedrez *ajedrez = new Ajedrez(&tablero);
			temp->setValores(nueva->posx,nueva->posy);

			ajedrez->fichasMin = fichasMin;

			ajedrez->fichasMax = fichasMax;

			if(tablero[nueva->posx][nueva->posy] > 0 )

				ajedrez->fichasMax.borrar(nueva->posx,nueva->posy);

			ajedrez->tablero[tempX][tempY] = 0;

			ajedrez->tablero[nueva->posx][nueva->posy] = tablero[tempX][tempY];

			g.InsertarVertice(vp,ajedrez);

			nueva = nueva->siguiente;

		}
		temp->setValores(tempX,tempY);
		fichasNuevas.eliminar();

		temp = temp->siguiente;
	}
}


float Ajedrez::funcion(){

	Ficha * temp = fichasMax.inicio;

	float valor = 0.f;


	while(temp){
		temp->evaluar(valor,&tablero);

		temp = temp->siguiente;
	}


	temp = fichasMin.inicio;

	while(temp){
		temp->evaluar(valor,&tablero);
		temp = temp->siguiente;
	}

	return valor;

}
void Ajedrez::inicializar(){

	for(int i=0; i< 8 ;i++){
				fichasMax.insertar(Peon(i,1));
			}

			fichasMax.insertar(Torre(0,0));
			fichasMax.insertar(Alfil(2,0));
			fichasMax.insertar(Torre(7,0));

			fichasMax.insertar(Alfil(5,0));



			fichasMax.insertar(Caballo(1,0));


			fichasMax.insertar(Rey(4,0));
			fichasMax.insertar(Reyna(3,0));
			fichasMax.insertar(Caballo(6,0));


			for(int i=0; i< 8 ;i++){
				fichasMin.insertar(Peon(i,6));
			}


			fichasMin.insertar(Torre(0,7));
			fichasMin.insertar(Alfil(2,7));
			fichasMin.insertar(Torre(7,7));
			fichasMin.insertar(Alfil(5,7));

			fichasMin.insertar(Caballo(1,7));
			fichasMin.insertar(Rey(4,7));

			fichasMin.insertar(Reyna(3,7));
			fichasMin.insertar(Caballo(6,7));






}

void  Ajedrez::dibujar(HDC& hdc){

	char te [2];

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){

//			te[0]='0'+tablero[i][j];
			te[1]='\0';

			TextOut(hdc,50+72*j,60+72*i,te,1);
}


}

void  Ajedrez::dibujar2(Imagen& imagen){

	Ficha * temp = fichasMax.inicio;

	while(temp){

		temp->dibujar(imagen,1);
		temp = temp->siguiente;
	}

	temp = fichasMin.inicio;

	while(temp){

		temp->dibujar(imagen,0);
		temp = temp->siguiente;
	}
}

void Juego::turnoMaquina(){


	Ajedrez *nuevo = new Ajedrez(&ajedrez->tablero);


	nuevo->fichasMax = ajedrez->fichasMax;

	nuevo->fichasMin = ajedrez->fichasMin;


	grafo.InsertarVertice(nuevo);



	float xx = alphaBetaMax(grafo,grafo.inicio,-100,100);

	Ajedrez *temp = buscar(xx,grafo.inicio);


	ajedrez->cargar(&temp->tablero);



	ajedrez->fichasMax = temp->fichasMax;
	ajedrez->fichasMin = temp->fichasMin;



	grafo.EliminarGrafo(grafo.inicio);

	grafo.inicio =0;

	b++;

	turno = true;


}

void Juego::turnoUsuario(int iniX,int iniY,int finX,int finY){


	Ficha* temp = ajedrez->fichasMin.inicio;
	while(temp){

		if(temp->posx == iniX && temp->posy == iniY){
			temp->setValores(finX,finY);
			break;
		}

		temp = temp->siguiente;
	}

	if( ajedrez->tablero[finX][finY] > 0){

		ajedrez->fichasMax.borrar(finX,finY);
		b = false;
	}



	ajedrez->tablero[finX][finY] = ajedrez->tablero[iniX][iniY];

	ajedrez->tablero[iniX][iniY] = 0;

	turno = false;

}

void Juego::jugar(int iniX,int iniY,int finX,int finY){

	turnoUsuario(iniX,iniY,finX,finY);

	turnoMaquina();

}
float valorNodo(Vertice* v){

	return ((Ajedrez*) v->contenido)->funcion();
}
bool limiteProfundidad(Vertice* v){

	return 3 == v->profundidad;
}
float maximo(float x1, float x2){

	if( x2 > x1)return x2;
	return x1;
}
float minimo(float x1, float x2){

	if( x2 > x1)return x1;

	return x2;
}
void sucesoresMax( Grafo &g , Vertice *v){

	((Ajedrez*)v->contenido)->jugadasMax(g,v);

}
void sucesoresMin( Grafo &g , Vertice *v){

	((Ajedrez*)v->contenido)->jugadasMin(g,v);

}
float alphaBetaMax(Grafo &g, Vertice *v,float x , float b){

	if(limiteProfundidad( v))
		return valorNodo(v);

	sucesoresMax(g,v);

	Arista * temp = v->aristas;
	while(temp){

		x = maximo(x,alphaBetaMin(g,temp->destino,x,b));
		temp->contenido = x;

		if( x >= b){
			g.EliminarAristasRestantes(v->num_aristas,temp->siguiente);
			temp->siguiente = 0;
			return b;
		}

		temp = temp->siguiente;

	}
	return x;

}
float alphaBetaMin(Grafo &g, Vertice *v, float x , float b){

	if(limiteProfundidad( v))
		return valorNodo(v);

	sucesoresMin(g,v);

	Arista * temp = v->aristas;
	while(temp){

		b = minimo(b,alphaBetaMax(g, temp->destino,x,b ));
		temp->contenido = b;

		if( x >= b){
			g.EliminarAristasRestantes(v->num_aristas,temp->siguiente);
			temp->siguiente = 0;
			return x;
		}

		temp = temp->siguiente;
	}
	return b;
}

Ajedrez* buscar( float &f, Vertice *v ){

	Arista* temp = v->aristas;

	while(temp ){

		if( temp->contenido == f )
			return ((Ajedrez*)temp->destino->contenido);

		temp = temp->siguiente;
	}
	return 0;

}

