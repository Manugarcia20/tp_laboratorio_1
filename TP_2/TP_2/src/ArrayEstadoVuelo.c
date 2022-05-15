/*
 * ArrayEstadoVuelo.c
 *
 *  Created on: 13 may. 2022
 *      Author: manu
 */

#include "ArrayEstadoVuelo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


void MostrarUnEstado(eEstadoVuelo unVuelo){
	printf("%d        %s  \n", unVuelo.idEstado, unVuelo.descEstado);

}



int listarEstados(eEstadoVuelo estadoVuelo[], int tam)
{
	int isOk = 0;

if(estadoVuelo != NULL && tam > 0)
{

	printf("\n\n\n");
	printf("-------------------------------------------\n");
	printf("*** ESTADO DE VUELOS ***		\n");
	printf("-------------------------------------------\n");
	printf("ID	 DESCRIPCION \n");
	printf("-------------------------------------------\n");

	for (int i = 0; i < tam; i++)
	{
		MostrarUnEstado(estadoVuelo[i]);

	}

     printf("\n\n");
     isOk = 1;

}

	return isOk;
}

int CargarDescripcionEstado(eEstadoVuelo estadoVuelo[], int tam, int id, char descEstado[])
{
	int isOk = 0;

	if(estadoVuelo != NULL && tam > 0 && id >= 1 && id <= 3 && descEstado != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(estadoVuelo[i].idEstado == id)
			{
				strcpy(descEstado,estadoVuelo[i].descEstado);
				break;
			}
		}

		isOk = 1;
	}


	return isOk;
}
