#include "Ventana.h"

int WINAPI WinMain(	HINSTANCE hInst,HINSTANCE hPrevInst,
				   char* cmdParam,int cmdShow)
{
	Ventana ven(procesos,"Mi Ventana",hInst);
	ven.crearVentana(616,658);
	ven.mostrar(cmdShow);
	
	return ven.cicloMensaje();
	
}