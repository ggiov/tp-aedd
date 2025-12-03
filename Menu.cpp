#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h> 
#include <cctype>
#include "Pantalla.h"
#include "datos.h"
#include "TipoPlato.h"
#include "RegionOrigen.h"
#include "CargarReceta.h"
#include "ConsultarReceta.h"


using namespace std;

void cargarrecetas() {
	char opcion;
	
	do {
		
		
		cin.clear();
		cin.ignore(200,'\n');
		
		system("cls");
		dibujarmarco(15, 5, 70, 20);
		cambiarcolor(253);
		
		gotoxy(18, 3);  cout << "                                    .                  ,       ";
		gotoxy(18, 4);  cout << " ._ _  _ ._ . .   _. _.._. _  _.   _| _   ._. _  _. _ -+- _. __";
		gotoxy(18, 5);  cout << " [ | )(/,[ )(_|  (_.(_][  (_](_]  (_](/,  [  (/,(_.(/, | (_]_) ";
		gotoxy(18, 6);  cout << "                          ._|                                  ";
		
		gotoxy(35,8); cout << "1.- Ver Tipos de Platos";
		gotoxy(35,9); cout << "2.- Ver Regiones de Origen";
		gotoxy(35,10); cout << "3.- Cargar Receta Individual";
		gotoxy(35,11); cout << "4.- Cargar Receta de Tradición Familiar";
		gotoxy(35,12); cout << "X.- Volver al Menú Principal";

		
		gotoxy(35,15); cout << "Ingrese una opción: ";
		
		opcion = cin.get(); // lee un solo carácter
		cin.clear();
		//si el siguiente carácter NO es '\n', entonces ingresaron más de uno
		if (cin.peek() != '\n'){ //lee el 2do caracter y si no es el /n lo toma como invalido
			cin.ignore(200, '\n'); // limpiar resto de caracteres
			gotoxy(32, 18); cambiarcolor(79);
			cout << "Opcion inválida. Intente nuevamente." << endl;
			Sleep(1500);
			gotoxy(32, 20); cambiarcolor(253);
			cout << "Presione ENTER para continuar.";
			cambiarcolor(253);
			continue; // vuelve al inicio del do sin evaluar la opción
		}
		opcion = toupper(opcion); //para q acepte mayusc y minusc 
		
		if (opcion == '1') {
			
			system("cls");
			dibujarmarco(15, 5, 70, 20);
			cambiarcolor(253);
			mostrarTiposDePlato(); 
			gotoxy(18, 19); cout << "Presione ENTER para volver al menu...";
			esperarEnter();   
		}
		else if (opcion == '2') {
			
			system("cls");
			dibujarmarco(15, 5, 70, 20);
			cambiarcolor(253);
			mostrarRegiones();
			gotoxy(18, 19); cout << "Presione ENTER para volver al menu...";
			esperarEnter();   
		}
		else if (opcion == '3') {
			
			gotoxy(36, 19); cambiarcolor(240);
			
			cargarRecetaIndividual(false); 
		}
		else if (opcion == '4') {
			
			gotoxy(36, 19); cambiarcolor(240);
			
			cargarRecetaIndividual(true); 
		}
		
		else if (opcion != 'X') {
			gotoxy(32, 19); cambiarcolor(79);
			cout << "Opción inválida. Intente nuevamente.";
			Sleep(1500);
			cambiarcolor(253);
		}
		
	} while (opcion != 'X');
}

void consultarrecetario(){
	char opcion;
	
	do {
		
		cin.clear();
		cin.ignore(200,'\n');
		
		system("cls");
		dibujarmarco(15, 5, 70, 20);
		cambiarcolor(253);
		
		gotoxy(18, 3);  cout << "                   .                    . ,       ";
		gotoxy(18, 4);  cout << " ._ _  _ ._ . .   _| _    _. _ ._  __. .|-+- _. __";
		gotoxy(18, 5);  cout << " [ | )(/,[ )(_|  (_](/,  (_.(_)[ )_) (_|| | (_]_) ";
		gotoxy(18, 6);  cout << "                                                  ";
		
		gotoxy(35,10); cout << "1.- Recetas por Tipo de Plato";
		gotoxy(35,11); cout << "2.- Recetas por Regiones de Origen";
		gotoxy(35,12); cout << "3.- Recetas de Tradicion Familiar";
		gotoxy(35,13); cout << "4.- Recetas Favoritas del Usuario";
		gotoxy(35,14); cout << "X.- Volver al Menú Principal";
		
		gotoxy(35,16); cout << "Ingrese una opción: ";
		opcion = cin.get(); // lee un solo carácter
		cin.clear();
		//si el siguiente carácter NO es '\n', entonces ingresaron más de uno
		if (cin.peek() != '\n'){ //lee el 2do caracter y si no es el /n lo toma como invalido
			cin.ignore(200, '\n'); // limpiar resto de caracteres
			gotoxy(32, 17); cambiarcolor(79);
			cout << "Opcion inválida. Intente nuevamente." << endl;
			Sleep(1500);
			gotoxy(32, 19); cambiarcolor(253);
			cout << "Presione ENTER para continuar.";
			cambiarcolor(253);
			continue; // vuelve al inicio del do sin evaluar la opción
		}
		opcion = toupper(opcion); //para q acepte mayusc y minusc 
		
		if (opcion == '1') {
			
			consultarPorTipoDePlato(); 
		}
		else if (opcion == '2') {
			
			consultarPorRegion();
		}
		else if (opcion == '3') {
			
			consultarTradicionFamiliar();
		}
		else if (opcion == '4') {
			
			consultarFavoritas();
		}
		else if (opcion != 'X') {
			gotoxy(32, 19); cambiarcolor(79);
			cout << "Opción inválida. Intente nuevamente.";
			Sleep(1500);
			cambiarcolor(253);
		}
		
	} while (opcion != 'X');
}
	
	void menuprincipal() {
		char opcion;
		
		do {
			
			cin.clear();
			cin.ignore(100,'\n');
			
			system("cls");
			dibujarmarco(15, 5, 70, 20);	
			
			cambiarcolor(253);
			gotoxy(26, 3);  cout << "              ,             ._         .       ";
			gotoxy(26, 4);  cout << " ._. _  _. _ -+- _.._.* _   |, _.._ _ *|* _.._.";
			gotoxy(26, 5);  cout << " [  (/,(_.(/, | (_][  |(_)  | (_][ | )|||(_][  ";
			
			
			gotoxy(35,9); cout << "1.- Cargar Recetas";
			gotoxy(35,10); cout << "2.- Consultar Recetario";
			gotoxy(35,11); cout << "X.- Salir de la aplicación";
			
			gotoxy(35,14); cout << "Ingrese una opción: ";
			opcion = cin.get(); // lee un solo carácter
			cin.clear();
			//si el siguiente carácter NO es '\n', entonces ingresaron más de uno
			if (cin.peek() != '\n'){ //lee el 2do caracter y si no es el /n lo toma como invalido
				cin.ignore(200, '\n'); // limpiar resto de caracteres
				gotoxy(32, 17); cambiarcolor(79);
				cout << "Opcion inválida. Intente nuevamente." << endl;
				Sleep(1500);
				gotoxy(32, 19); cambiarcolor(253);
				cout << "Presione ENTER para continuar.";
				cambiarcolor(253);
				continue; // vuelve al inicio del do sin evaluar la opción
			}
			opcion = toupper(opcion);
			
			if (opcion == '1') {
				cargarrecetas();   // acá se cargan recetas y se guardan en miRecetario
			}
			else if (opcion == '2') {
				if (miRecetario.cantRecetas > 0) {
					consultarrecetario();
				} else {
					gotoxy(23, 16); cambiarcolor(79);
					cout << "No hay recetas cargadas aun. Use la opcion 1 primero.";
					Sleep(2000);
					cambiarcolor(253);
				}
			}
			
			else if (opcion == 'X') {
				cambiarcolor(244);
				gotoxy(30, 16); cout << "¿Está seguro que desea salir? (S/N): ";
				char confirmar;
				cin >> confirmar;
				
				confirmar = toupper(confirmar);
				
				cin.ignore(50, '\n');  
				if (confirmar == 'S') {
					gotoxy(28, 18); cambiarcolor(223);
					cout << "Gracias por usar el sistema. ¡Hasta luego!";
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cambiarcolor(240);
					Sleep(2000);
					opcion = 'X';
				} else {
					opcion = '0'; // fuerza a que no salga del do-while
				}
			}
			else {
				gotoxy(30, 16); cambiarcolor(79);
				cout << "Opción inválida. Intente nuevamente.";
				Sleep(1500);
				cambiarcolor(253);
			}
			
		} while (opcion != 'X');
	}
