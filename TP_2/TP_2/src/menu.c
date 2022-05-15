/*
 * menu.c
 *
 *  Created on: 29 abr. 2022
 *      Author: manu
 */


#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu() {
	int opcion;

	printf("\n");
	printf("\n\n1 - ALTA\n");
	printf("\n2 - MODIFICAR\n");
	printf("\n3 - BAJA\n");
	printf("\n4 - INFORMAR\n");
	printf("\n5 - SALIR\n");

	opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,5);

	return opcion;
}

int subMenuModificar(){

	int opcion;
		printf("\n\n");
		printf("\nQUE DESEA MODIFICAR?\n");

		printf("\n1 - NOMBRE\n");
		printf("\n2 - APELLIDO\n");
		printf("\n3 - PRECIO DEL VUELO\n");
		printf("\n4 - CODIGO DE VUELO\n");
		printf("\n5 - TIPO DE PASAJERO\n");
		printf("\n5 - ESTADO DE VUELO\n");
		printf("\n6 - SALIR\n");


		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,6);

		return opcion;
}

int subMenuInformes(){
	int opcion;
			printf("\n\n");
			printf("\nQUE INFORME DESEA VER?\n");

			printf("\n1 - Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
			printf("\n2 - Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n");
			printf("\n3 - Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
			printf("\n4 - Salir");

			printf("\nElija una opcion: \n");
			scanf("%d", &opcion);

			return opcion;

}
