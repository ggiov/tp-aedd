#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "Pantalla.h"
using namespace std;
const int CANTIDAD_REGIONES = 5;

struct RegionOrigen {
	int id;
	string nombre;
	string caracteristicaPrincipal;
};
RegionOrigen regiones[] = 
{{1,"Italiana", {"Pizza, Pasta Carbonara, Risotto, Lasagna"}}, 
{2, "Rumana", {"Sarmale, Ciorba, Mamaliga, Cozonac"}},
{3, "Japonesa", {"Sushi, Ramen, Okonomiyaki, Tempura"}},
{4, "Argentina", {"Asado, Empanadas, Locro, Milanesa"}},
{5, "Mexicana", {"Tacos, Enchiladas, Guacamole, Mole"}}};

void mostrarRegiones() {
	gotoxy(18, 8); cout << "Listado de Regiones de Origen:\n";
	
	for (int i = 0; i < CANTIDAD_REGIONES; i++) {
		gotoxy(18, 11 + i);  
		cout<< regiones[i].id << "- " << regiones[i].nombre << ": " << regiones[i].caracteristicaPrincipal;
	}
	cout << endl;
	
}
