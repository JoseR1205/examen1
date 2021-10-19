#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"
#include "salon.h"
#ifndef INFORMES_H_
#define INFORMES_H_

void compararJuego(Arcade *arcade, int lenA);
void pesosFicha(Salon *sala, int len, Arcade *arcade, int lenA);
void printCantArcadeSalon(Salon *sala,Arcade *arcade,int len, int lenA);
void idSalonPrintArcade(Salon *sala, Arcade *arcade, int len, int lenA);
void informes(Salon *sala, Arcade *arcade, int len, int lenA);
void listarSalonArcades(Salon *sala, int len, Arcade *arcade, int lenA);
void listarArcadeJugadores(Salon *sala,int len,Arcade *arcade,int lenA);
void salonArcadeNumero(Salon *sala, Arcade *arcade, int len, int lenA);
#endif
