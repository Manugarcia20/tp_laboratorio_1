/*
 * ArrayDatosVuelo.c
 *
 *  Created on: 11 may. 2022
 *      Author: manu
 */

#include "ArrayTipoPasajero.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>



void MostrarUnTipo(eTipo unPasajero){
	printf("%d    %s  \n", unPasajero.id, unPasajero.descTipo);

}



int listarTipos(eTipo tipoPasajero[], int tam)
{
	int isOk = 0;

if(tipoPasajero != NULL && tam > 0)
{

	printf("\n\n\n");
	printf("*** LISTA DE TIPOS DE PASAJERO ***		\n");
	printf("-------------------------------------------\n");
	printf("ID	 DESCRIPCION \n");
	printf("-------------------------------------------\n");

	for (int i = 0; i < tam; i++)
	{
		MostrarUnTipo(tipoPasajero[i]);

	}

     printf("\n\n");
     isOk = 1;

}

	return isOk;
}

int CargarDescripcionTipo(eTipo tipoPasajero[], int tam, int id, char descripcion[])
{
	int isOk = 0;

	if(tipoPasajero != NULL && tam > 0 && id >= 5000 && id <= 5002 && descripcion != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(tipoPasajero[i].id == id)
			{
				strcpy(descripcion,tipoPasajero[i].descTipo);
				break;
			}
		}

		isOk = 1;
	}


	return isOk;
}
