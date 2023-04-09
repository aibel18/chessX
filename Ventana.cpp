#include "Ventana.h"
#include "Botones.h"
#include "Grafo.h"
#include "Ajedrez.h"


Ventana::Ventana(WNDPROC winProc, const char *nombre, HINSTANCE hins){
	nombreVentana = nombre;
	IdAplicacion = hins;

	claseVentana.style = 0;
	claseVentana.lpfnWndProc= winProc;
	claseVentana.cbWndExtra =0;
	claseVentana.cbClsExtra =0;
	claseVentana.hInstance = IdAplicacion;
	claseVentana.hIcon =0;
	claseVentana.hCursor = LoadCursor(0,IDI_APPLICATION);
	claseVentana.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	claseVentana.lpszMenuName =0;
	claseVentana.lpszClassName =nombreVentana;
	registrar();
}
void Ventana::crearVentana(int ancho,int alto){

	IdVentana = CreateWindowEx(
		0,
		nombreVentana,
		nombreVentana,
		WS_OVERLAPPEDWINDOW|SS_BITMAP,
		100,
		20,
		ancho,
		alto,
		0,
		LoadMenu(IdAplicacion,"Menu"),
		IdAplicacion,
		0
		);
}
void Ventana::registrar(){
	if(!RegisterClass(&claseVentana)){
		MessageBox(NULL,"ESTADO_ERROR de creacion de la ventana.","ESTADO_ERROR",MB_OK|MB_ICONEXCLAMATION);
		return ;
	}
}
void Ventana::mostrar (int cmdShow)
{
        ShowWindow (IdVentana, cmdShow);
        UpdateWindow (IdVentana);
}

void Ventana::limpiar(){

	DestroyWindow(IdVentana);
	UnregisterClass(nombreVentana,IdAplicacion);
}
int Ventana::cicloMensaje(void)
{
	while (GetMessage (&Mensaje, NULL, 0, 0))
	{	TranslateMessage (&Mensaje) ;
		DispatchMessage (&Mensaje) ;
	}
	return Mensaje.wParam ;
}
/*
void dibujarTablero(HDC hdc){

/*		Rectangle(hdc,200,100,300,200);
		SetTextColor(hdc,RGB(0,0,255));

		char te [2];

		te[0]=n;
		te[1]='\0';

		TextOut(hdc,245+100*x,145+100*y,te,1);

/*


	hDC = BeginPaint (hwnd, &ps);
			celd.dibujar_contenido(hDC);
			linea = CreatePen(PS_SOLID, 1, RGB(0, 200, 250));
			SelectObject(hDC, linea);

			for(int i=0;i<8;i++){
				MoveToEx(hDC,100+i*100,240,0);
				LineTo(hDC,100+i*100,400);
			}
			for(int i=10;i<19;i++){
			MoveToEx(hDC,100,40+i*20,0);
			LineTo(hDC,800,40+i*20);
			}
			if(co.conf)
			{
			linea = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			SelectObject(hDC, linea);
			Rectangle(hDC, co.x,co.y, co.x+100, co.y+20);

			}

			co.conf=false;
			EndPaint (hwnd, &ps);
			return 0;*/
//}


#define ID 100
#define ID1 101
#define ID2 102

//procesos de la ventana principal
LRESULT CALLBACK  procesos(HWND hwnd, UINT message, WPARAM wParam, LPARAM
							lParam)
{
	static HINSTANCE hi =((LPCREATESTRUCT)lParam)->hInstance;

	static PAINTSTRUCT ps;
	static HDC hdc;

	static HINSTANCE instancia;

	static Imagen imagen(hi,hwnd);

	static Juego juego;

	static Fichas movidas;

	static int * X;

	static int * Y;

	switch (message)
	{

		case WM_CREATE:{

			X = new int;
			Y = new int;

			//imagen.cargarImagen("tablero.bmp",0,20,600,600);
			//juego.ajedrez->dibujar2(imagen);

			return 0;
		}

		case WM_LBUTTONDOWN:{

			int posy = (LOWORD(lParam)-12) / 72 ;
			int posx = (HIWORD(lParam)-32) / 72;



			if(juego.ajedrez->tablero[posx][posy] < 0 ){

				movidas.eliminar();


				Ficha* temp = juego.ajedrez->fichasMin.inicio;
				while(temp){
					if(temp->posx == posx && temp->posy == posy){



						*X = posx;
						*Y = posy;
						break;
					}

					temp = temp->siguiente;
				}

				temp->mover2(movidas,&juego.ajedrez->tablero);

			}

			else{

				Ficha* temp = movidas.inicio;
				while(temp){
					if(temp->posx == posx && temp->posy == posy){

						if( juego.b == 2)
							juego.b++;



						juego.turnoUsuario(*X,*Y,posx,posy);
						//imagen.cargarImagen("tablero.bmp",0,20,600,600);
						//juego.ajedrez->dibujar2(imagen);
						InvalidateRect(hwnd,0,false);

						break;
					}

					temp = temp->siguiente;
				}

			}

			return 0;

		}
		case WM_LBUTTONUP:{

			if(!juego.turno){

                //Sleep(200);
                juego.ajedrez->dibujar2(imagen);
                imagen.cargarImagen("tablero.bmp",0,20,600,600);

				juego.turnoMaquina();

				//imagen.cargarImagen("tablero.bmp",0,20,600,600);

				//juego.ajedrez->dibujar2(imagen);


                //Sleep(200);

				InvalidateRect(hwnd,0,0);

			}

			return 0;

		}
		case WM_PAINT:{


			hdc = BeginPaint(hwnd, &ps);

			/*MoveToEx(hdc,12,0,0);
			LineTo(hdc,12,600);

			MoveToEx(hdc,84+0*72,0,0);
			LineTo(hdc,84+0*72,600);

			MoveToEx(hdc,84+1*72,0,0);
			LineTo(hdc,84+1*72,600);

			MoveToEx(hdc,84+2*72,0,0);
			LineTo(hdc,84+2*72,600);

			MoveToEx(hdc,84+3*72,0,0);
			LineTo(hdc,84+3*72,600);

			MoveToEx(hdc,84+4*72,0,0);
			LineTo(hdc,84+4*72,600);

			MoveToEx(hdc,84+5*72,0,0);
			LineTo(hdc,84+5*72,600);

			MoveToEx(hdc,84+6*72,0,0);
			LineTo(hdc,84+6*72,600);

			MoveToEx(hdc,84+7*72,0,0);
			LineTo(hdc,84+7*72,600);




			MoveToEx(hdc,0,32,0);
			LineTo(hdc,600,32);


			MoveToEx(hdc,0,104,0);
			LineTo(hdc,600,104);




			MoveToEx(hdc,0,104+72*1,0);
			LineTo(hdc,600,104+72*1);

			MoveToEx(hdc,0,104+72*2,0);
			LineTo(hdc,600,104+72*2);

			MoveToEx(hdc,0,104+72*3,0);
			LineTo(hdc,600,104+72*3);

			MoveToEx(hdc,0,104+72*4,0);
			LineTo(hdc,600,104+72*4);

			MoveToEx(hdc,0,104+72*5,0);
			LineTo(hdc,600,104+72*5);

			MoveToEx(hdc,0,104+72*6,0);
			LineTo(hdc,600,104+72*6);*/

			//juego.ajedrez->dibujar(hdc);


			juego.ajedrez->dibujar2(imagen);
			imagen.cargarImagen("tablero.bmp",0,20,600,600);

			EndPaint(hwnd, &ps);

			return 0;
		}

		case WM_DESTROY:
		{	PostQuitMessage (0);

			return 0;
		}
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}


