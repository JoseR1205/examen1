#include "salon.h"
#include "biblioteca.h"

int eliminarSalon(Salon* sala, int len, int id)
{
	int retorno =-1;
	if(sala != NULL && id > -1){
		sala[id].isEmpty=0;
		retorno = 0;
	}
	return retorno;
}
int printSalas(Salon* sala, int len,int tipo)
{
	int retorno = -1;
	for(int i=0;i<len;i++){
		if(sala[i].isEmpty==1){
			printf("\nId:|%d| nombre:|%s| direccion:|%s|",sala[i].id,sala[i].nombre,sala[i].direccion);
			if(tipo==0){
				if(sala[i].tipo==1){
					printf("Tipo|SHOPPING|");
				}else{
					printf("Tipo|LOCAL|");
				}
			}
		}
	}
	return retorno;
}
int buscarId(Salon* sala, int len,int id)
{
	int idP = -1;
	if(sala != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(sala[i].id==id){
				idP = i;
				break;
			}
		}
	}
	return idP;
}

int ingresarSalon(Salon *salon,int len){
	int retorno =-1;
	if(salon != NULL && len>0){
		for(int i=0;i<len;i++){
			if(salon[i].isEmpty==0){
				cargarsalon(salon, i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void cargarsalon(Salon *salon, int ubi){
	if(utn_getChar(salon[ubi].nombre, "\ningresar nombre\n", "\nerror\n", 51, 5)==0){
		if(utn_getChar(salon[ubi].direccion, "\ningresar direccion\n", "\nerror\n", 51, 5)==0){
			if(utn_getInt(&salon[ubi].tipo, "\nIngresar tipo de salon\n1_SHOPPING\n2_LOCAL\n", "\nError", 1, 2, 20)==0){
				salon[ubi].id=autoIdSalon();
				salon[ubi].isEmpty=1;
			}
		}
	}
}

int initSalon(Salon * sala, int len)
{
	int retorno = -1;
	if(sala != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i<len ; i++){
			sala[i].isEmpty = 0;
		}
	}
	return retorno;
}

int autoIdSalon(){
	static int id =1;
	return id++;
}
