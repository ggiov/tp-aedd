#include "CargarReceta.h"
#include "datos.h"
#include "Pantalla.h"
#include "TipoPlato.h"
#include "RegionOrigen.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h> 
#include <cctype>
#include <string>

using namespace std;


void cargarRecetaIndividual(bool esTradicionFamiliar){
	if (miRecetario.cantRecetas >= 50) {
		system("cls");
		dibujarmarco(15, 5, 70, 20);
		cambiarcolor(253);
		gotoxy(25, 8); cout << "No se pueden cargar mas recetas (tope alcanzado).";
		Sleep(2000);
		return;
	}
	
	Receta nueva;
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	cambiarcolor(253);
	
	
	if (esTradicionFamiliar) {
		gotoxy(18, 3);  cout << "  .    .___.        .             .___         .       ";
		gotoxy(18, 4);  cout << " _| _    |  ._. _. _|* _.* _ ._   [__  _.._ _ *|* _.._.";
		gotoxy(18, 5);  cout << "(_](/,   |  [  (_](_]|(_.|(_)[ )  |   (_][ | )|||(_][  ";
		gotoxy(18, 6);  cout << "                                                       ";
	} else {
		gotoxy(18, 3);  cout << "._.     .        .      .";
		gotoxy(18, 4);  cout << " | ._  _|*.  ,* _|. . _.|";
		gotoxy(18, 5);  cout << "_|_[ )(_]| |/ |(_](_|(_]|";
		gotoxy(18, 6);  cout << "                         ";
	}
	
	// nombre
	gotoxy(18, 8); cout << "Nombre de la receta: ";
	cin.ignore();
	getline(cin, nueva.nombre);
	
	// tipo de plato
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	cambiarcolor(253);
	gotoxy(18, 6); cout << "TIPOS DE PLATO DISPONIBLES";
	mostrarTiposDePlato();
	gotoxy(18, 20); cout << "Ingrese ID del tipo de plato: ";
	cin >> nueva.tipoPlato;
	
	// región
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	cambiarcolor(253);
	mostrarRegiones();
	gotoxy(18, 20); cout << "Ingrese ID de la region de origen: ";
	cin >> nueva.regionOrigen;
	
	// ingredientes
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	cambiarcolor(253);
	gotoxy(18, 8); cout << "Cantidad de ingredientes (max 20): ";
	cin >> nueva.ingredientes.cantIngredientes;
	cin.ignore();
	
	for (int i = 0; i < nueva.ingredientes.cantIngredientes; i++) {
		system("cls");
		dibujarmarco(15, 5, 70, 20);
		cambiarcolor(253);
		gotoxy(18, 8); cout << "Ingrediente " << (i+1) << " de " << nueva.ingredientes.cantIngredientes;
		
		gotoxy(18, 10); cout << "Nombre: ";
		getline(cin, nueva.ingredientes.ingredientes[i].nombre);
		
		gotoxy(18, 12); cout << "Cantidad: ";
		cin >> nueva.ingredientes.ingredientes[i].cantidad;
		cin.ignore();
		
		gotoxy(18, 14); cout << "Unidad: ";
		getline(cin, nueva.ingredientes.ingredientes[i].unidad);
	}
	
	// pasos
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	cambiarcolor(253);
	gotoxy(18, 8); cout << "Cantidad de pasos (max 20): ";
	cin >> nueva.pasos.cantPasos;
	cin.ignore();
	for (int i = 0; i < nueva.pasos.cantPasos; i++) {
		system("cls");
		dibujarmarco(15, 5, 70, 20);
		cambiarcolor(253);
		gotoxy(18, 8); cout << "Paso " << (i+1) << " de " << nueva.pasos.cantPasos;
		
		gotoxy(18, 10); cout << "Descripcion: ";
		getline(cin, nueva.pasos.pasos[i].descripcion);
		nueva.pasos.pasos[i].numero = i + 1;
	}
	
	//pregunta si es una receta favorita
	char fav;
	gotoxy(18, 18); cout << "¿Desea marcar esta receta como favorita? (S/N): ";
	cin >> fav;
	nueva.esFavorita = (toupper(fav) == 'S');
	
	
	nueva.tradicionFamiliar = esTradicionFamiliar;
	nueva.tlCompartidoCon = 0;
	
	// guardar
	miRecetario.recetario[miRecetario.cantRecetas] = nueva;
	miRecetario.cantRecetas++;
	
	system("cls");
	dibujarmarco(15, 5, 70, 20);
	
	for (int i = 0; i < 5; i++) {
		cambiarcolor(175);
		gotoxy(35, 12); cout << "Receta cargada exitosamente!";
		Sleep(400);
		
		cambiarcolor(160);
		gotoxy(35, 12); cout << "                             ";
		Sleep(250);
	}
	
	cambiarcolor(253);
	gotoxy(34, 15); cout << "Presione ENTER para continuar...";
}
