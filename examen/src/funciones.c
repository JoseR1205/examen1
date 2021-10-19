
#include "funciones.h"
#include "biblioteca.h"
#include "salon.h"
#include "arcade.h"
#include "informes.h"
void menu(Salon *sala,Arcade *arcade, int len, int lenA){
	int opcion;
	int idSeleccionado;
	int idaux;
	int flagOpcion=0;
	int flagOpcion2=0;
	if(sala != NULL && len > 0){
		while(opcion != 10){
			if(utn_getInt(&opcion, "\n1)Alta de salon\n2)Eliminar salon\n3)imprimir salones\n4)Incorporar arcade\n5)Modificar arcade\n6)Eliminar arcade\n7)Imprimir Arcade\n8)Imprimir juegos\n9)Informes\n10)Salir\n", "Error", 1, 10, 5)==0){
				switch(opcion){
					case 1:
						ingresarSalon(sala, len);
						flagOpcion=1;
						break;
					case 2:
						if(flagOpcion==1){
							printSalas(sala, len, -1);
							if(utn_getInt(&idSeleccionado, "\n ingresar id del salon para eliminar\n", "\nerror.", 1, 10000, 5)==0){
								idaux = buscarId(sala, len, idSeleccionado);
								if(eliminarSalon(sala, len, idaux)==0){
									printf("\nSe elimino correctamente\n");
									eliminarArcadeSala(arcade, lenA, idaux);
								}else{
									printf("\nerror volviendo al menu...\n");
								}
							}
						}
						break;
					case 3:
						if(flagOpcion==1){
							printSalas(sala, len, 0);
						}
						break;
					case 4:
						if(flagOpcion==1){
							ingresarArcade(arcade, lenA, sala, len);
							flagOpcion2=1;
						}
						break;
					case 5:
						if(flagOpcion2==1 && flagOpcion==1){
							printArcade(arcade, lenA);
							modificarArcade(arcade, lenA);
						}
						break;
					case 6:
						if(flagOpcion2==1 && flagOpcion==1){
							if(printArcadeSalon(arcade, lenA, sala, len)==0){
								eliminarArcade(arcade, lenA);
							}
						}
						break;
					case 7:
						if(flagOpcion2==1 && flagOpcion==1){
							printArcade(arcade, lenA);
						}
						break;
					case 8:
						if(flagOpcion2==1 && flagOpcion==1){
							mostrarjuegosSinrepetir(arcade, lenA);
						}
						break;
					case 9:
						if(flagOpcion2==1 && flagOpcion==1){
							informes(sala, arcade, len, lenA);
						}
						break;
				}
			}
		}
	}
}



void eliminarArcadeSala(Arcade *arcade,int lenA,int idEliminado){
	for(int i = 0;i<lenA;i++){
		if(arcade[i].idSalon==idEliminado){
			arcade[i].isEmpty=0;
		}
	}
}


