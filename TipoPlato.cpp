#include <string>
#include <iostream>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "Pantalla.h"
using namespace std;
const int CANTIDAD_TIPOS = 5;
struct TipoPlato {
	int id;
	string nombre;
	string descripcion;
};

TipoPlato tipos[] = {{1, "Entrada", "Platos livianos para abrir el apetito"}, {2, "Principal", "Platos fuertes que constituyen la comida principal"} , {3, "Postre", "Platos dulces que se sirven al final"}, {4, "Bebida", "Líquidos para acompañar las comidas"}, {5, "Guarnición", "Acompañamientos del plato principal"}};

void mostrarTiposDePlato() {
	gotoxy(18, 8); cout << "Listado de Tipos de Plato:\n";
	
	for (int i = 0; i < CANTIDAD_TIPOS; i++) {
		gotoxy(18, 11 + i);  
		cout << tipos[i].id << "- " << tipos[i].nombre << ": " << tipos[i].descripcion;
	}
	cout << endl;
	
}
