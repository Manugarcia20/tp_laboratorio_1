/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	do {
			opcion = menu();

			switch (opcion) {
			case 1:
				printf("\nUsted eligio: ALTA\n");
				break;
			case 2:
				printf("\nUsted eligio: MODIFICAR\n");
				break;
			case 3:
				printf("\nUsted eligio: BAJA\n");
				break;
			case 4:
				printf("\nUsted eligio: INFORMAR\n");
				break;
			case 5:
				printf("\nUsted eligio: SALIR\n");
				break;
			default:
				printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
				break;
			}

		} while (opcion != 5);











	return EXIT_SUCCESS;
}
