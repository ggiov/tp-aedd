#ifndef DATOS_H
#define DATOS_H
#include <string>
using namespace std;

struct Ingrediente {
	string nombre;
	float cantidad;
	string unidad;
};

struct ListaDeIngredientes {
	Ingrediente ingredientes[20];
	int cantIngredientes;
};

struct Paso {
	int numero;
	string descripcion;
};

struct ListaDePasos {
	Paso pasos[20];
	int cantPasos;
};

struct Receta {
	string nombre;
	int tipoPlato;
	ListaDeIngredientes ingredientes;
	ListaDePasos pasos;
	bool tradicionFamiliar;
	int regionOrigen;
	int compartidoCon[10];
	int tlCompartidoCon;
	bool esFavorita;
};

struct Recetario {
	Receta recetario[50];
	int cantRecetas;
	int legajo;
};

extern Recetario miRecetario; // se declara como global

#endif
