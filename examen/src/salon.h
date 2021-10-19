
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SALON_H_
#define SALON_H_

typedef struct
{
int id;
char nombre[51];
char direccion[51];
int tipo;
int isEmpty;
}Salon;
/** \brief Se ingresa el salon
* \param sala Salon*
* \param len int
* \return int
*/
int ingresarSalon(Salon *salon,int len);
/** \brief inicializa el salon
* \param sala Salon*
* \param len int
* \return int
*/
int initSalon(Salon * sala, int len);
/** \brief Carga el salon
* \param sala Salon*
* \param len int
*/
void cargarsalon(Salon *salon, int ubi);
/** \brief autogenera id
* \return id
*/
int autoIdSalon();
/** \brief se busca la posicion en el array por id
* \param sala Salon*
* \param len int
* \return int
*/
int buscarId(Salon* sala, int len,int id);
/** \brief Muestra las salas
* \param sala Salon*
* \param len int
* \param len tipo
* \return int
*/
int printSalas(Salon* sala, int len,int tipo);
/** \brief Elimina el salon
* \param sala Salon*
* \param len int
* \param len id
* \return
*/
int eliminarSalon(Salon* sala, int len, int id);
#endif
