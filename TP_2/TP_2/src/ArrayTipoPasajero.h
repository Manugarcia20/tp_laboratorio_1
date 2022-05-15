/*
 * ArrayDatosVuelo.h
 *
 *  Created on: 11 may. 2022
 *      Author: manu
 */

#ifndef ARRAYTIPOPASAJERO_H_
#define ARRAYTIPOPASAJERO_H_



typedef struct{
int id;
char descTipo[20];
} eTipo;


int listarTipos(eTipo tipoPasajero[], int tam);
void MostrarUnTipo(eTipo unPasajero);
int CargarDescripcionTipo(eTipo tipoPasajero[], int tam, int id, char descripcion[]);

#endif /* ARRAYTIPOPASAJERO_H_ */


