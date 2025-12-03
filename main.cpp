#include <iostream>
#include "Pantalla.h"
#include "Login.h"
#include "Menu.h"
#include "datos.h"

using namespace std;

int main() {
	
	mostrarPantallaBienvenida();
	if (login()) {
		menuprincipal();
	}
	
	
	
	

	return 0;
}
