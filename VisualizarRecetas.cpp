#include "Datos.h"
#include "Pantalla.h"
#include "VisualizarRecetas.h"

#include <iostream>
#include <iomanip>
using namespace std;


void tipoRegion(int id){
	
	switch(id){
	case 1:
		cout << "Italiana";
		break;
	case 2:
		cout << "Rumana";
		break;
	case 3:
		cout << "Japonesa";
		break;
	case 4:
		cout << "Argentina";
		break;
	case 5:
		cout << "Mexicana";
		break;
		
	}
}
	
	
	void tipoPlato (int id){
		
		switch(id){
		case 1:
			cout << "Entrada";
			break;
		case 2:
			cout << "Principal";
			break;
		case 3:
			cout << "Postre";
			break;
		case 4:
			cout << "Bebida";
			break;
		case 5:
			cout << "Guarnición";
			break;
			
		}
		
	}
		
		void mostrarReceta(listaDeRecetas lista, int id){
			
			int x=2, y=2, ax = 2 , ax1 = 2;
			
			//como las opciones son de 1-50 
			//se disminuye en una unidad
			id--;
			
			system("cls");
			dibujarmarco(0, 0, 50, 32);
			dibujarmarco(48, 0, 52, 32);
			//datos de la receta
			gotoxy(x, y);
			cout << "DATOS RECETA:";
			gotoxy(x, y+1);
			cout << "Nombre: " << lista.listaRecetas[id].nombre; 
			gotoxy(x, y+2);
			cout << "Tipo de plato:";
			gotoxy(x+15, y+2);
			tipoPlato(lista.listaRecetas[id].tipoPlato);
			gotoxy(x, y+3);
			cout << "Region:";
			gotoxy(x+8, y+3);
			tipoRegion(lista.listaRecetas[id].regionOrigen);
			gotoxy(x, y+4);
			cout << "-------------------------------------------"<<endl;	
			
			y+=4;
			
			for(int i=0; i < lista.listaRecetas[id].ingredientes.cantIngredientes; i++){
				gotoxy(x, y+1);
				cout << "Ingredientes: ";
				gotoxy(x, y+2+i);
				cout << " " << lista.listaRecetas[id].ingredientes.ingredientes[i].cantidad << " " << lista.listaRecetas[id].ingredientes.ingredientes[i].unidad << " de " << lista.listaRecetas[id].ingredientes.ingredientes[i].nombre;
				ax++;
			}
			
			for(int i=0; i < lista.listaRecetas[id].pasos.cantPasos; i++){
				gotoxy(x+51, 2);
				cout << "Pasos: " << endl;
				gotoxy(x+51, 2+i+1);
				cout << lista.listaRecetas[id].pasos.pasos[i].numero << ". " << lista.listaRecetas[id].pasos.pasos[i].descripcion;
				ax1++;
			}
			gotoxy(x+51, y+ax1);
			system("pause");
			
			
			
		}
			
