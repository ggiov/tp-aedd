
#include "datos.h"
#include "listasOrdenadas.h"
#include "Pantalla.h"
#include <iostream>
#include "TipoPlato.h"
#include "VisualizarRecetas.h"
#include "RegionOrigen.h"
using namespace std;

//visualizacion de la lista de las recetas ordenadas
void mostrarlista(int tl, listaDeRecetas lista, int& id){
	
	int x=13, y=3, aux = 0;
	system("cls");
	dibujarmarco(10, 2, 60, 30);
	
	for(int i=0; i < tl; i++){
		gotoxy(x, y);
		cout << "Recetas del tipo seleccionado: ";
		gotoxy(x, y+1+i);
		cout << i+1 << ". " << lista.listaRecetas[i].nombre;
		aux++;
	}
	
	gotoxy(13,y+1+aux);
	cout << "INGRESE RECETA PARA VISUALIZAR:";
	gotoxy(44, y+1+aux);
	cin >> id;
	
}	
	//ordenamiento burbuja mejorado
	void OrdenarAlfabetico(listaDeRecetas& lista, int& tl){
		
		Receta recetaAux;
		
		int pasada, k;
		
		for(pasada = 1; pasada < tl; pasada++){
			
			for(k=0; k < tl - pasada; k++)
				if(lista.listaRecetas[k].nombre > lista.listaRecetas[k+1].nombre ){
				
				recetaAux = lista.listaRecetas[k];
				lista.listaRecetas[k] = lista.listaRecetas[k+1];
				lista.listaRecetas[k+1] = recetaAux;
				
			}
		}
	}
		//busqueda de la receta seleccionada
		Receta busquedaReceta(listaDeRecetas& lista, int id){
			
			int aux;
			// se hace esto para que la primera posicion es 0, asi figura como 1
			if(id==1){
				aux = 0;
			}else{
				aux = id;
			}
			return lista.listaRecetas[aux];
		}
			
			
			void ListaPorTipoDePlato(){
				
				int id;
				
				listaDeRecetas lista;
				
				lista.tl = 0;
				
				system("cls");
				dibujarmarco(15, 5, 70, 20);
				
				cambiarcolor(253);
				mostrarTiposDePlato();	
				
				cambiarcolor(253);
				gotoxy(18, 20);
				cout << "INGRESE EL TIPO DE PLATO QUE DESEE:" << endl;
				gotoxy(54, 20);
				cin >> id;
				
				for(int i=0; i < miRecetario.cantRecetas; i++){
					
					if(miRecetario.recetario[i].tipoPlato == id){
						
						lista.listaRecetas[lista.tl] = miRecetario.recetario[i];
						lista.tl++;
						
					}
					
				}
				//la lista tiene tl > 0 expresa que existe un elemento por lo menos  
				if(lista.tl > 0){
					
					OrdenarAlfabetico(lista,lista.tl);
					mostrarlista(lista.tl,lista,id);
					mostrarReceta(lista,id);
					
				}else{
					system("cls");
					dibujarmarco(15, 5, 70, 20);
					gotoxy(18, 10);
					cout << "NO HAY ELEMENTOS CON ESTA ESPECIFICACION" << endl;
					gotoxy(18, 11);
					system("pause");
					
				}
			}
				
				void listaPorRegion(){
					
					int id;
					listaDeRecetas lista;
					
					lista.tl = 0;
					
					system("cls");
					dibujarmarco(15, 5, 70, 20);
					
					cambiarcolor(253);
					mostrarRegiones();	
					
					gotoxy(18, 20);
					cout << "INGRESE LA REGION QUE DESEE:" << endl;
					gotoxy(54, 20);
					cin >> id;
					
					for(int i=0; i < miRecetario.cantRecetas; i++){
						
						if(miRecetario.recetario[i].regionOrigen == id){
							
							lista.listaRecetas[lista.tl] = miRecetario.recetario[i];
							lista.tl++;
							
						}
					}
					
					if(lista.tl > 0){
						
						OrdenarAlfabetico(lista,lista.tl);
						mostrarlista(lista.tl,lista,id);
						mostrarReceta(lista,id);
						
					}else{
						
						system("cls");
						dibujarmarco(15, 5, 70, 20);
						gotoxy(18, 10);
						cout << "NO HAY ELEMENTOS CON ESTA ESPECIFICACION" << endl;
						gotoxy(18, 11);
						system("pause");
						
					}
				}
					
					void listaTradicionFamiliar(){
						
						int id;
						listaDeRecetas lista;
						
						lista.tl = 0;
						system("cls");
						dibujarmarco(15, 5, 70, 20);
						
						for(int i=0; i < miRecetario.cantRecetas; i++){
							
							if(miRecetario.recetario[i].tradicionFamiliar){
								
								lista.listaRecetas[lista.tl] = miRecetario.recetario[i];
								lista.tl++;
								
							}
							
						}
						
						if(lista.tl > 0){
							
							OrdenarAlfabetico(lista,lista.tl);
							
							mostrarlista(lista.tl,lista,id);
							
							mostrarReceta(lista,id);
							
						}else{
							
							system("cls");
							dibujarmarco(15, 5, 70, 20);
							gotoxy(18, 10);
							cout << "NO HAY ELEMENTOS CON ESTA ESPECIFICACION" << endl;
							gotoxy(18, 11);
							system("pause");
						}
						
					}
						
						Receta accederElemento(int tl,listaDeRecetas& lista){
							
							
							return lista.listaRecetas[tl];
							
						}
							void accederLista(listaDeRecetas& v, int i);
							
							
							
							
