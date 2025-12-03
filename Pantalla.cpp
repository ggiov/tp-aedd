#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "Pantalla.h"
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void cambiarcolor(int color) {
	SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(short x, short y) {
	COORD cp = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void barradecarga(int x, int y, int longitud) {
	cambiarcolor(2545); 
	gotoxy(x, y);
	cout << "|";
	for (int i = 0; i < longitud; i++) cout << " ";
	cout << "|";
	
	gotoxy(x + 1, y);
	for (int i = 0; i < longitud; i++) {
		cout << char(177);
		Sleep(50);
	}
}

void dibujarmarco(int x0, int y0, int cols, int lines) {
	cambiarcolor(240); 
	int ancho = cols - 2;
	int alto = lines - 2;
	gotoxy(x0, y0);                     cout << char(218);
	gotoxy(x0 + ancho - 1, y0);         cout << char(191);
	gotoxy(x0, y0 + alto - 1);          cout << char(192);
	gotoxy(x0 + ancho - 1, y0 + alto - 1); cout << char(217);
	for (int i = 1; i < ancho - 1; i++) {
		gotoxy(x0 + i, y0);             cout << char(196);
		gotoxy(x0 + i, y0 + alto - 1);  cout << char(196);
	}
	for (int j = 1; j < alto - 1; j++) {
		gotoxy(x0, y0 + j);             cout << char(179);
		gotoxy(x0 + ancho - 1, y0 + j); cout << char(179);
	}
}

void esperarEnter() {
	int tecla = 0;
	while (tecla != 13) {
		tecla = _getch();
	}
}

void mostrarPastelito(int x, int y) {
	cambiarcolor(253); 
	gotoxy(x, y);     cout << "   ,,,,,";
	gotoxy(x, y + 1); cout << "   |||||";
	gotoxy(x, y + 2); cout << "  (~~~~~)";
	gotoxy(x, y + 3); cout << " (_______)";
	gotoxy(x, y + 4); cout << " |       |";
	gotoxy(x, y + 5); cout << " |_______|";
	gotoxy(x, y + 6); cout << "  \\_____/ ";
}

void mostrarSombreroChef(int x, int y) {
	cambiarcolor(246); 
	gotoxy(x, y);     cout << "     )   (    )";
	gotoxy(x, y + 1); cout << "  (    ___  (";
	gotoxy(x, y + 2); cout << "    _.'   `._  ) ";
	gotoxy(x, y + 3); cout << "  .'         `.";
	gotoxy(x, y + 4); cout << "_(_____________)___";
}

void mostrarPantallaBienvenida() {
	system("color F0");
	system("mode con: cols=100 lines=30");
	dibujarmarco(1, 4, 100, 20);
	
	int x = (100 - 74) / 2;
	int y = 7;
	
	cambiarcolor(249);
	gotoxy(x, y + 1); cout << " ______   ______  ______  ______ _______  ______   ______  _____  ______  ";
	gotoxy(x, y + 2); cout << "| |  | \\ | |     | |     | |       | |   | |  | | | |  | \\  | |  / |  | \\ ";
	gotoxy(x, y + 3); cout << "| |__| | | |---- | |     | |----   | |   | |__| | | |__| |  | |  | |  | | ";
	gotoxy(x, y + 4); cout << "|_|  \\_\\ |_|____ |_|____ |_|____   |_|   |_|  |_| |_|  \\_\\ _|_|_ \\_|__|_/ ";
	gotoxy(x, y + 5); cout << "                                                                          ";
	mostrarSombreroChef(3, 2); 
	mostrarPastelito(87, 17); 
	
	int largoBarra = 30;
	int xBarra = (100 - largoBarra - 2) / 2;
	int yBarra = y + 7;
	barradecarga(xBarra, yBarra, largoBarra);
	
	Sleep(600); 
	cambiarcolor(240);
	gotoxy((100 - 32) / 2, yBarra + 3);
	cout << "Presione ENTER para continuar...";
	esperarEnter();
	system("cls");
}
