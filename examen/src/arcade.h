
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salon.h"

#ifndef ARCADE_H_
#define ARCADE_H_

typedef struct
{
int id;
char nacionalidad[51];
char juego[63];
int cantJugadores;
int fichasMax;
int tipoS;
int idSalon;
int isEmpty;
}Arcade;

void eliminarArcade(Arcade *arcade, int lenA);
int printArcadeSalon(Arcade *arcade, int lenA, Salon *sala, int len);
void mostrarjuegosSinrepetir(Arcade* arcade,int lenA);
void modificarArcade(Arcade* arcade, int lenA);
int buscarIdArcade(Arcade* arcade, int len,int id);
void mostrarjuegosSinrepetir(Arcade* arcade,int lenA);
int printArcade(Arcade* arcade, int len);
int ingresarArcade(Arcade *arcade,int len,Salon *sala,int lenSalon);
void cargarArcade(Arcade *arcade,int ubi,Salon *sala,int lenSalon);
int validarSalonArcade(Arcade *arcade,Salon *sala,int idingresado,int ubi,int len);
int autoIdArcade();
int initArcade(Arcade * arcade, int len);
#endif
