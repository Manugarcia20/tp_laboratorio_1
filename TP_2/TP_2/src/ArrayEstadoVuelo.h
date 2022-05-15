/*
 * ArrayEstadoVuelo.h
 *
 *  Created on: 13 may. 2022
 *      Author: manu
 */

#ifndef ARRAYESTADOVUELO_H_
#define ARRAYESTADOVUELO_H_

typedef struct{
int idEstado;
char descEstado[20];
} eEstadoVuelo;


#endif /* ARRAYESTADOVUELO_H_ */



int listarEstados(eEstadoVuelo estadoVuelo[], int tam);
void MostrarUnEstado(eEstadoVuelo unVuelo);
int CargarDescripcionEstado(eEstadoVuelo estadoVuelo[], int tam, int id, char descEstado[]);
