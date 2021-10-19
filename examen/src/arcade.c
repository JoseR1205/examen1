#include "arcade.h"
#include "salon.h"
#include "biblioteca.h"

void eliminarArcade(Arcade *arcade, int lenA){
	int opcion;
	int idaux;
	if(utn_getInt(&opcion, "\nIngresar id a eliminar", "\nError\n", 1, 9999, 5)==0){
		idaux = buscarIdArcade(arcade, lenA, opcion);
		printf("\nId:|%d|nacionalidad:|%s|juego:|%s|jugadores:|%d|fichas|%d|", arcade[idaux].id, arcade[idaux].nacionalidad,arcade[idaux].juego,arcade[idaux].cantJugadores,arcade[idaux].fichasMax);
		if(arcade[idaux].tipoS==1){
			printf("Sonido:|mono|");
		}else{
			printf("Sonido:|estereo|");
		}
		if(utn_getInt(&opcion, "\nEsta seguro se eliminar ?\n1_Si\n2_no", "\nError", 1, 2, 5)==0){
			if(opcion == 1){
				arcade[idaux].isEmpty=0;
			}else{
				printf("\nVolviendo al menu...");
			}
		}
	}
}

int printArcadeSalon(Arcade *arcade, int lenA, Salon *sala, int len){
	int retorno = -1;
	if(arcade!=NULL && sala!=NULL && lenA>0 && len >0){
		for(int i=0;i<len;i++){
			if(sala[i].isEmpty==1){
				printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[i].id,sala[i].nombre,sala[i].direccion);
				if(sala[i].tipo==1){
					printf("Tipo|SHOPPING|");
				}else{
					printf("Tipo|LOCAL|");
				}
				for(int x = 0; x<lenA ;x++){
					if(arcade[x].isEmpty==1){
						printf("\n  -Id:|%d|nacionalidad:|%s|juego:|%s|jugadores:|%d|fichas|%d|", arcade[x].id, arcade[x].nacionalidad,arcade[x].juego,arcade[x].cantJugadores,arcade[x].fichasMax);
						if(arcade[x].tipoS==1){
							printf("Sonido:|mono|");
						}else{
							printf("Sonido:|estereo|");
						}
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

void modificarArcade(Arcade* arcade, int lenA){
	int opcion;
	int subopcion;
	if(utn_getInt(&opcion, "\nIngresar id a modificar\n", "\nerror", 1, 10000, 5)==0){
		if(utn_getInt(&subopcion, "\n1_Modificar cantidad de jugadores\n2_Modificar juego", "\nerror\n", 1, 2, 4)==0){
			if(subopcion==1){
				utn_getInt(&arcade[buscarIdArcade(arcade, lenA, opcion)].cantJugadores, "\nIngresar cantidad de juegadores", "\nerror\n", 1, 50000, 5);
			}else{
				mostrarjuegosSinrepetir(arcade, lenA);
				utn_getChar(arcade[buscarIdArcade(arcade, lenA, opcion)].juego, "\nIngresar el nuevo nombre del juego\n", "\nError\n", 63, 5);
			}
		}
	}
}

void mostrarjuegosSinrepetir(Arcade* arcade,int lenA){
	int copiaContador=0;
	char copia[20][63];
	int auxCont=0;
	for(int i = 0;i<lenA;i++){
		if(arcade[i].isEmpty==1){
			for(int x = 0;x<20;x++){
				if(strcmp(arcade[i].juego,copia[x])!=0){
					strcpy(copia[copiaContador],arcade[i].juego);
				}else{
					auxCont++;
				}
			}
		}
	}
	for(int f=0;f<auxCont;f++){
		printf("\n%s",copia[f]);
	}
}

int buscarIdArcade(Arcade* arcade, int len,int id)
{
	int idP = -1;
	if(arcade != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(arcade[i].id==id){
				idP = i;
				break;
			}
		}
	}
	return idP;
}
int printArcade(Arcade* arcade, int len)
{
	int retorno = -1;
	for(int i=0;i<len;i++){
		if(arcade[i].isEmpty==1){
			printf("\nId:|%d|nacionalidad:|%s|juego:|%s|jugadores:|%d|fichas|%d|", arcade[i].id, arcade[i].nacionalidad,arcade[i].juego,arcade[i].cantJugadores,arcade[i].fichasMax);
			if(arcade[i].tipoS==1){
				printf("Sonido:|mono|");
			}else{
				printf("Sonido:|estereo|");
			}
		}
	}
	return retorno;
}

int ingresarArcade(Arcade *arcade,int len,Salon *sala,int lenSalon){
	int retorno =-1;
	if(arcade != NULL && len>0){
		for(int i=0;i<len;i++){
			if(arcade[i].isEmpty==0){
				cargarArcade(arcade, i, sala, lenSalon);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
void cargarArcade(Arcade *arcade,int ubi,Salon *sala,int lenSalon){
	int idaux;
	if(utn_getChar(arcade[ubi].nacionalidad, "\nIngresar nacionalidad del arcade\n", "\nError\n", 51, 5)==0){
		if(utn_getInt(&arcade[ubi].tipoS, "\nIngresar tipo de sonido:\n1_Mono\n2_Estereo", "\nerror opcion invalida\n", 1, 2, 5)==0){
			if(utn_getInt(&arcade[ubi].cantJugadores, "\nIngresar cantidad de jugadores\n", "\nError\n", 1, 20, 5)==0){
				if(utn_getInt(&arcade[ubi].fichasMax, "\nIngresar la cantidad maxima de fichas\n", "\nerror\n", 1, 5000, 5)==0){
					if(utn_getInt(&idaux, "\nIngesar id salon del arcade\n", "\nerror\n", 1, 10000, 5)==0 && validarSalonArcade(arcade, sala, idaux, ubi, lenSalon)==0){
						if(utn_getChar(arcade[ubi].juego, "\nIngresar juego\n", "\nerror\n", 63, 5)==0){
							arcade[ubi].id=autoIdArcade();
							arcade[ubi].isEmpty=1;
						}
					}else{
						printf("\nError el salon no existe.\nVovlviendo al menu\n");
					}
				}
			}
		}
	}
}
int validarSalonArcade(Arcade *arcade,Salon *sala,int idingresado,int ubi,int len){
	int retorno = -1;
	if(sala[buscarId(sala, len, idingresado)].isEmpty==1){
		arcade[ubi].idSalon=idingresado;
		retorno = 0;
	}
	return retorno;
}
int initArcade(Arcade * arcade, int len)
{
	int retorno = -1;
	if(arcade != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i<len ; i++){
			arcade[i].isEmpty = 0;
		}
	}
	return retorno;
}
int autoIdArcade(){
	static int id =1;
	return id++;
}
