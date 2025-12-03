#include "ConsultarReceta.h"
#include "Pantalla.h"
#include "TipoPlato.h"
#include "RegionOrigen.h"
#include "datos.h"
#include <iostream>
#include <windows.h>
using namespace std;


// ORDENAMIENTO ALFABÉTICO

void ordenarPorNombre(Receta recetas[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (recetas[i].nombre > recetas[j].nombre) {
				Receta aux = recetas[i];
				recetas[i] = recetas[j];
				recetas[j] = aux;
			}
		}
	}
}


// MOSTRAR RECETA COMPLETA

void mostrarReceta(const Receta& receta) {
	system("cls");
	dibujarmarco(10, 3, 90, 25);
	cambiarcolor(253);
	
	gotoxy(12, 5); cout << "Nombre: " << receta.nombre;
	gotoxy(12, 6); cout << "Tipo de plato ID: " << receta.tipoPlato;
	gotoxy(12, 7); cout << "Region ID: " << receta.regionOrigen;
	gotoxy(12, 8); cout << "Tradicion familiar: "
		<< (receta.tradicionFamiliar ? "SI" : "NO");
	
	
	gotoxy(12, 10); cout << "Ingredientes:";
	for (int i = 0; i < receta.ingredientes.cantIngredientes; i++) {
		gotoxy(14, 11 + i);
		cout << "- " << receta.ingredientes.ingredientes[i].nombre << " "
			<< receta.ingredientes.ingredientes[i].cantidad << " "
			<< receta.ingredientes.ingredientes[i].unidad;
	}
	
	
	int y = 12 + receta.ingredientes.cantIngredientes;
	gotoxy(12, y); cout << "Pasos:";
	for (int i = 0; i < receta.pasos.cantPasos; i++) {
		gotoxy(14, y + i + 1);
		cout << receta.pasos.pasos[i].numero << ". "
			<< receta.pasos.pasos[i].descripcion;
	}
	
	gotoxy(12, y + receta.pasos.cantPasos + 2);
	cout << "Presione ENTER para volver...";
	esperarEnter();
}


// CONSULTA POR TIPO DE PLATO

void consultarPorTipoDePlato() {
	system("cls");
	dibujarmarco(10, 3, 90, 25);
	cambiarcolor(253);
	
	gotoxy(12, 5); cout << "CONSULTA POR TIPO DE PLATO";
	
	mostrarTiposDePlato();
	
	gotoxy(12, 18); cout << "Ingrese ID: ";
	int id; cin >> id;
	

	Receta filtradas[50];
	int cantFiltradas = 0;
	
	for (int i = 0; i < miRecetario.cantRecetas; i++) {
		if (miRecetario.recetario[i].tipoPlato == id) {
			filtradas[cantFiltradas] = miRecetario.recetario[i];
			cantFiltradas++;
		}
	}
	
	if (cantFiltradas == 0) {
		gotoxy(12, 20); cout << "No hay recetas de ese tipo.";
		Sleep(2000);
		return;
	}
	
	
	ordenarPorNombre(filtradas, cantFiltradas);
	
	
	int y = 20;
	for (int i = 0; i < cantFiltradas; i++) {
		gotoxy(12, y + i);
		cout << (i + 1) << ". " << filtradas[i].nombre;
	}
	
	gotoxy(12, y + cantFiltradas + 1);
	cout << "Seleccione receta: ";
	int opcion; cin >> opcion;
	
	if (opcion > 0 && opcion <= cantFiltradas) {
		mostrarReceta(filtradas[opcion - 1]);
	} else {
		gotoxy(12, y + cantFiltradas + 3);
		cambiarcolor(79);
		cout << "Opcion invalida. No existe esa receta.";
		cambiarcolor(253);
		Sleep(2000);
	}
	
}


// CONSULTA POR REGION DE ORIGEN

void consultarPorRegion() {
	system("cls");
	dibujarmarco(10, 3, 90, 25);
	cambiarcolor(253);
	
	gotoxy(12, 5); cout << "CONSULTA POR REGION DE ORIGEN";
	mostrarRegiones();
	
	gotoxy(12, 18); cout << "Ingrese ID: ";
	int id; cin >> id;
	
	
	Receta filtradas[50];
	int cantFiltradas = 0;
	
	for (int i = 0; i < miRecetario.cantRecetas; i++) {
		if (miRecetario.recetario[i].regionOrigen == id) {
			filtradas[cantFiltradas] = miRecetario.recetario[i];
			cantFiltradas++;
		}
	}
	
	if (cantFiltradas == 0) {
		gotoxy(12, 20); cout << "No hay recetas de esa region.";
		Sleep(2000);
		return;
	}
	

	ordenarPorNombre(filtradas, cantFiltradas);
	

	int y = 20;
	for (int i = 0; i < cantFiltradas; i++) {
		gotoxy(12, y + i);
		cout << (i + 1) << ". " << filtradas[i].nombre;
	}
	
	gotoxy(12, y + cantFiltradas + 1);
	cout << "Seleccione receta: ";
	int opcion; cin >> opcion;
	
	if (opcion > 0 && opcion <= cantFiltradas) {
		mostrarReceta(filtradas[opcion - 1]);
	} else {
		gotoxy(12, y + cantFiltradas + 3);
		cambiarcolor(79);
		cout << "Opcion invalida. No existe esa receta.";
		cambiarcolor(253);
		Sleep(2000);
	}
}


// CONSULTA DE RECETAS DE TRADICION FAMILIAR


void consultarTradicionFamiliar() {
	system("cls");
	dibujarmarco(10, 3, 90, 25);
	cambiarcolor(253);
	
	gotoxy(12, 5); 
	cout << "CONSULTA DE RECETAS DE TRADICION FAMILIAR";
	
	Receta familiares[50];
	int cantFamiliares = 0;
	
	
	for (int i = 0; i < miRecetario.cantRecetas; i++) {
		if (miRecetario.recetario[i].tradicionFamiliar) {
			familiares[cantFamiliares] = miRecetario.recetario[i];
			cantFamiliares++;
		}
	}
	
	if (cantFamiliares == 0) {
		gotoxy(12, 7); 
		cout << "No hay recetas de tradición familiar.";
		Sleep(2000);
		return;
	}
	
	
	ordenarPorNombre(familiares, cantFamiliares);
	
	int y = 10;
	for (int i = 0; i < cantFamiliares; i++) {
		gotoxy(12, y + i);
		cout << (i + 1) << ". " << familiares[i].nombre;
	}
	
	gotoxy(12, y + cantFamiliares + 1);
	cout << "Seleccione receta: ";
	int opcion; 
	cin >> opcion;
	
	if (opcion > 0 && opcion <= cantFamiliares) {
		mostrarReceta(familiares[opcion - 1]);
	} else {
		gotoxy(12, y + cantFamiliares + 3);
		cambiarcolor(79);
		cout << "Opcion invalida. No existe esa receta.";
		cambiarcolor(253);
		Sleep(2000);
	}
}


// CONSULTA DE RECETAS FAVORITAS

void consultarFavoritas() {
	system("cls");
	dibujarmarco(10, 3, 90, 25);
	cambiarcolor(253);
	
	gotoxy(12, 5); cout << "CONSULTA DE RECETAS FAVORITAS";
	

	Receta favoritas[50];
	int cantFavoritas = 0;
	
	for (int i = 0; i < miRecetario.cantRecetas; i++) {
		if (miRecetario.recetario[i].esFavorita) {
			favoritas[cantFavoritas] = miRecetario.recetario[i];
			cantFavoritas++;
		}
	}
	
	if (cantFavoritas == 0) {
		gotoxy(12, 7); cout << "No tiene recetas favoritas.";
		Sleep(2000);
		return;
	}
	

	ordenarPorNombre(favoritas, cantFavoritas);
	

	int y = 10;
	for (int i = 0; i < cantFavoritas; i++) {
		gotoxy(12, y + i);
		cout << (i + 1) << ". " << favoritas[i].nombre;
	}
	
	gotoxy(12, y + cantFavoritas + 1);
	cout << "Seleccione receta: ";
	int opcion; cin >> opcion;
	
	if (opcion > 0 && opcion <= cantFavoritas) {
		mostrarReceta(favoritas[opcion - 1]);
	} else {
		gotoxy(12, y + cantFavoritas + 3);
		cambiarcolor(79);
		cout << "Opcion invalida. No existe esa receta.";
		cambiarcolor(253);
		Sleep(2000);
	}
}

