#include "informes.h"
#include "salon.h"
#include "arcade.h"
#include "biblioteca.h"

void informes(Salon *sala, Arcade *arcade, int len, int lenA){
	int subOpcion;
	while(subOpcion!=8){
		utn_getInt(&subOpcion, "\n1_Listar los salones con más de 4 arcades.\n2_Listar los arcades para más de 2 jugadores\n3_Listar toda la información de un salón en específico ingresando su ID\n4_Listar todos los arcades de un salón determinado ingresando su ID.\n5_Imprimir el salón con más cantidad de arcades\n6_Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos\n7_Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen\n", "\nerror", 1, 8, 5);
		switch(subOpcion){
				case 1:
					listarSalonArcades(sala, len, arcade, lenA);
					break;
				case 2:
					listarArcadeJugadores(sala, len, arcade, lenA);
					break;
				case 3:
					salonArcadeNumero(sala, arcade, len, lenA);
					break;
				case 4:
					idSalonPrintArcade(sala, arcade, len, lenA);
					break;
				case 5:
					printCantArcadeSalon(sala, arcade, len, lenA);
					break;
				case 6:
					pesosFicha(sala, len, arcade, lenA);
					break;
				case 7:
					compararJuego(arcade, lenA);
					break;
			}
	}
}
void compararJuego(Arcade *arcade, int lenA){
	char juegoIngresado[61];
	int cont=0;
	if(utn_getChar(juegoIngresado, "\nIngresar juego\n","\nError", 61, 5)==0){
		for(int i = 0; i<lenA;i++){
			if(arcade[i].isEmpty==1 && strcmp(juegoIngresado,arcade[i].juego)==0){
				cont++;
			}
		}
		printf("\n%d contienen el juego ingresado",cont);
	}
}
void pesosFicha(Salon *sala, int len, Arcade *arcade, int lenA){
	int id;
	int pesos;
	int acumulador=0;
	int total;
	if(utn_getInt(&id, "\ningresar Id salon\n", "\nError", 1, 9999, 5)==0){
		id=buscarId(sala, len, id);
		if(sala[id].isEmpty==1 && utn_getInt(&pesos, "\nIngresar Valor de fichas en pesos\n", "\nerror", 1, 5000, 5)==0){
			for(int i = 0; i<lenA;i++){
				if(arcade[i].isEmpty==1 && arcade[i].idSalon==sala[id].id){
					acumulador = acumulador + arcade[i].fichasMax;
				}
			}
			total = acumulador * pesos;
			printf("\nLos maximo a recaudar es : %d pesos", total);
		}
	}
}

void listarSalonArcades(Salon *sala, int len, Arcade *arcade, int lenA){
	for(int i = 0;i<len;i++){
		if(sala[i].isEmpty==1){
			int cont=0;
			for(int x = 0;x<lenA;x++){
				if(arcade[x].isEmpty==1 && sala[i].id==arcade[x].idSalon){
					cont++;
				}
			}
			if(cont>4){
				printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[i].id,sala[i].nombre,sala[i].direccion);
				if(sala[i].tipo==1){
					printf("Tipo|SHOPPING|");
				}else{
					printf("Tipo|LOCAL|");
				}
				printf(" cantidad de arcades:|%d|",cont);
			}
		}
	}

}

void listarArcadeJugadores(Salon *sala,int len,Arcade *arcade,int lenA){
	for(int i = 0; i<lenA;i++){
		if(arcade[i].isEmpty==1&&arcade[i].cantJugadores>2){
			printf("\nId:|%d|juego:|%s|jugadores:|%d| Nombre salon |%s|", arcade[i].id, arcade[i].juego,arcade[i].cantJugadores,sala[buscarId(sala, len, arcade[i].idSalon)].nombre);
		}
	}
}

void salonArcadeNumero(Salon *sala, Arcade *arcade, int len, int lenA){
	int idOpcion;
	int aux;
	utn_getInt(&idOpcion,"\nIngresar id salon\n", "error", 1, 10000, 5);
		aux = buscarId(sala, len, idOpcion);
		if(sala[aux].isEmpty==1){
			int cont=0;
			printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[aux].id,sala[aux].nombre,sala[aux].direccion);
			if(sala[aux].tipo==1){
				printf("Tipo|SHOPPING|");
			}else{
				printf("Tipo|LOCAL|");
			}
			for(int x = 0;x<lenA;x++){
				if(sala[aux].id==arcade[x].idSalon){
					cont++;
				}
			}
			printf("cantidad de arcades|%d|",cont);
		}
}

void idSalonPrintArcade(Salon *sala, Arcade *arcade, int len, int lenA){
	int idOpcion;
	int aux;
	utn_getInt(&idOpcion,"\nIngresar id salon\n", "error", 1, 10000, 5);
		aux = buscarId(sala, len, idOpcion);
		if(sala[aux].isEmpty==1){
			printf("\nnombre:|%s|",sala[aux].nombre);
			if(sala[aux].tipo==1){
				printf("Tipo|SHOPPING|");
			}else{
				printf("Tipo|LOCAL|");
			}
			for(int i = 0;i<len;i++){
				if(sala[aux].id==arcade[i].idSalon){
					if(arcade[i].isEmpty==1){
						printf("\n  -Id:|%d|nacionalidad:|%s|juego:|%s|jugadores:|%d|fichas|%d|", arcade[i].id, arcade[i].nacionalidad,arcade[i].juego,arcade[i].cantJugadores,arcade[i].fichasMax);
						if(arcade[i].tipoS==1){
							printf("Sonido:|mono|");
						}else{
							printf("Sonido:|estereo|");
						}
					}
				}
			}
		}else{
			printf("\nEse id no existe\n");
		}
}
void printCantArcadeSalon(Salon *sala,Arcade *arcade,int len, int lenA){
	int cant=0;
	int idSave;
	int idAux;
	for(int i = 0;i<len;i++){
		if(sala[i].isEmpty==1){
			int cont=0;
			for(int x = 0 ; x<lenA;x++){
				if(arcade[x].isEmpty==1&&arcade[x].idSalon==sala[i].id){
					cont++;

				}
			}
			if(cont > cant){
				cant = cont;
				idSave = sala[i].id;
			}
		}
	}
	idAux = buscarId(sala, len, idSave);
	printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[idAux].id,sala[idAux].nombre,sala[idAux].direccion);
	if(sala[idAux].tipo==1){
		printf("Tipo|SHOPPING|");
	}else{
		printf("Tipo|LOCAL|");
	}
	printf("Catidad de Arcades:|%d|",cant);
}


