#ifndef PANTALLA_H
#define PANTALLA_H

void cambiarcolor(int color);
void gotoxy(short x, short y);
void barradecarga(int x, int y, int longitud);
void dibujarmarco(int x0, int y0, int cols, int lines);
void esperarEnter();
void mostrarPastelito(int x, int y);
void mostrarSombreroChef(int x, int y);
void mostrarPantallaBienvenida();

#endif
