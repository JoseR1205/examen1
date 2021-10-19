#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salon.h"
#include "arcade.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/** \brief El menu que muestra las opciones para ser seleccionadas
* \param sala Salon*
* \param arcade Arcade*
* \param len int
* \param len intA
*/
void menu(Salon *sala,Arcade *arcade, int len, int lenA);
/** \brief elimina el arcade
* \param arcade Arcade*
* \param len intA
*/
void eliminarArcadeSala(Arcade *arcade,int lenA,int idEliminado);
#endif /* FUNCIONES_H_ */
