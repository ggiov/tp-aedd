#ifndef LISTASORDENADAS_H
#define LISTASORDENADAS_H
#include "ListasOrdenadas.h"

struct listaDeRecetas{
	
	Receta listaRecetas[50];
	int tl;
	
};

void OrdenarAlfabetico(listaDeRecetas& lista,int& tl);

void ListaPorTipoDePlato();

void listaPorRegion();

void listaTradicionFamiliar();

Receta accederElemento(listaDeRecetas& lista, int i);

void accederLista();

void mostrarlista(int tl, listaDeRecetas lista, int& id);

void agregarLista (int ttl, Receta receta);

Receta busquedaReceta(listaDeRecetas& lista, int id);



#endif
