#include "Login.h"
#include "Pantalla.h"
#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <limits>  
using namespace std;

bool legajovalido(int legajo){
	bool valido;
	if(legajo >= 10000 && legajo <= 99999){
		valido = true;
	}
	else {
		valido = false;
	}
	return valido;
}
	
	void flashPantalla() {
		system("color 0A"); Sleep(200);
		system("color "); Sleep(200);
	}
	
	// determinar contraseña usando los primos menores al año actual	
	bool esprimo(int n){ //verifica si el nro es primo
		bool primo = true;
		
		if (n < 2){ 
			primo = false;
		} else {
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0){
					primo = false;
				}
			}
		}
		
		return primo;
	}
		
		int sumaprimos(){// devuelve la suma de primos menores a los últimos dos díg del 2025
			int year = 2025;
			int limite = year % 100;  // extrae 25
			int suma = 0;
			
			for (int num = 2; num < limite; num++) {
				if (esprimo(num)) {
					suma += num;
				}
			}
			
			return suma;
		}		
			
			int contrasenavalida(int legajo){
				int contrasena, primerd, tercerd, quintod, N, ultimosdig;
				int suma_primos = sumaprimos();
				
				primerd = legajo / 10000; 
				tercerd = (legajo / 100) % 10;
				quintod = legajo % 10;
				
				N = (primerd * 100) + (tercerd * 10) + quintod;
				
				ultimosdig = legajo % 1000;
				
				contrasena = ((N + suma_primos) * 1000) + ultimosdig;
				
				return contrasena;
			}
				
				int ingresarcontrasenaoculta(int x, int y) {
					int contrasena = 0;
					char tecla; //guarda la tecla presionada por el usuario
					int digitos = 0;
					bool enterPresionado = false;
					
					gotoxy(x, y); //posiciona el cursor donde se ingresa la contraseña
					
					while (!enterPresionado) {
						tecla = _getch(); //lee la tecla sin mostrarla en pantalla
						
						if (tecla == 13) {
							enterPresionado = true; // Enter fue presionado
						} else if (tecla == 8 && digitos > 0){ // Si la tecla es backspace (borrar digito)
							contrasena /= 10; // elimina el último dígito
							digitos--; //decrementa el contador
							cout << "\b \b"; // mueve el cursor un lugar atrás, borra el asterisco y mueve cursor otra vez atrás
						} else if (tecla >= '0' && tecla <= '9' && digitos < 10){ //si la tecla es un nro y no se superan los 10 digitos 
							// aceptamos hasta 10 dígitos por seguridad
							int digito = tecla - '0'; //convierte el caracter al valor numerico
							contrasena = contrasena * 10 + digito; //agrega el digito a la contraseña (como un nro)
							digitos++;
							cout << '*';
						}
					}
					
					return contrasena;
				}
				bool login() {
					int legajo, contrasena;
					int contador = 0;
					bool accesoconcedido = false;
					
					while (contador < 3 && !accesoconcedido) {
						system("cls");
						dibujarmarco(15, 5, 70, 20);
						
						cambiarcolor(253);
						gotoxy(28, 4); cout << " o __  o  _  o  _     _  _  _  o  _ __  " << endl;
						gotoxy(28, 5); cout << " | | | | (_  | (/_   _> (/__>  | (_)| | " << endl;
						
						gotoxy(27, 9); cout << "Ingrese su usuario: ";
						cin >> legajo;
						
						gotoxy(27, 11); cout << "Ingrese su contraseña: ";
						contrasena = ingresarcontrasenaoculta(50, 11);
						
						//validacion 
						gotoxy(41,14); cout << "Validando datos";
						
						for (int i = 0; i < 3; i++) {
							cout << "."; Sleep(500);
						}
						
						gotoxy(41, 14); cout << "                      ";
						
						//condiciones	
						
						if(legajovalido(legajo)){
							
							if(contrasena == contrasenavalida(legajo)){
								accesoconcedido = true;
								
								for (int i = 0; i < 5; i++) {
									// mostrar mensaje en verde 
									cambiarcolor(175); 
									gotoxy(36, 14); cout << "ACCESO CONCEDIDO. BIENVENIDO!";
									Sleep(400);
									
									// borrar mensaje (simula parpadeo)
									cambiarcolor(160); // fondo blanco
									gotoxy(36, 14); cout << "                             ";
									Sleep(250);
									
								}
								cambiarcolor(253);
								menuprincipal();
								
							} else {
								gotoxy(38, 14); cout << "Contraseña incorrecta.";
								contador++;
							}
							
						} else {
							gotoxy(41, 14); cout << "Usuario inválido.";
							contador++;
						}
						
						
						if(!accesoconcedido && contador < 3){
							int intentosrestantes = 3 - contador;
							Sleep(1500);
							gotoxy(39, 15); cout << "Le " << (intentosrestantes == 1 ? "queda " : "quedan ") << intentosrestantes << " intento" << (intentosrestantes == 1 ? "" : "s") << "."; //elije entre dos opciones segun la condicion
							Sleep(2000);
							//restablecer cin
							cin.clear();
							cin.ignore(30,'\n');
						}
						
						if(contador == 3 && !accesoconcedido){
							for (int i = 0; i < 5; i++) {
								// mostrar mensaje en rojo 
								cambiarcolor(79); 
								gotoxy(31, 17); cout << "ACCESO DENEGADO. DEMASIADOS INTENTOS.";
								Sleep(400);
								
								// borrar mensaje (simula parpadeo)
								cambiarcolor(64); // fondo blanco
								gotoxy(31, 17); cout << "                                     ";
								Sleep(250);
								cambiarcolor(253);
							}
							cambiarcolor(253);
							gotoxy(31, 18); cout << "                                     ";
							gotoxy(31, 19); cout << "                                     ";
							gotoxy(31, 20); cout << "                                     ";
							gotoxy(31, 21); cout << "                                     ";
							cambiarcolor(253);
						}
					}
					
					return accesoconcedido;
				}
