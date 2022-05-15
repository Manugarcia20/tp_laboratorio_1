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
#include "ArrayPassenger.h"
#include "ArrayTipoPasajero.h"
#include "funciones.h"
#include "ArrayTipoPasajero.h"
#include "ArrayEstadoVuelo.h"
#define TAM 5
#define TAM_T 3
#define TAM_E 3




int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int informes;
	int orden;
	int IdPasajeroBaja;
	int IdPasajeroCambio;
	int pId = 1;
	int flagAlta = 0;



	ePasajero listaPasajeros[TAM];
	eTipo tipoPasajero[TAM_T] =
	{
			{5000, "Primera Clase"},
			{5001, "Segunda Clase"},
			{5002, "Clase Economica"},
	};

	eEstadoVuelo estadoVuelo[TAM_E] =
		{
			{1, "ACTIVO"},
			{2, "DEMORADO"},
			{3, "CANCELADO"},
		};


	InicializarPasajeros(listaPasajeros,TAM);

	do {

			opcion = menu();

			switch (opcion) {
			case 1:
				printf("\nUsted eligio: ALTA\n");

				if(AltaPasajero(listaPasajeros,TAM, &pId,tipoPasajero, TAM_T, estadoVuelo, TAM_E)){
					printf("\n*** PASAJERO CARGADO CON EXITO ***");
					flagAlta = 1;
				}else{
					printf("\n*** HUBO UN PROBLEMA AL CARGAR EL PASAJAJERO ***");
				}
				break;

			case 2:
				printf("\nUsted eligio: MODIFICAR\n");

				if(flagAlta == 1)
				{

				if(ModificarPasajeros(listaPasajeros,TAM,IdPasajeroCambio,tipoPasajero,TAM_T,estadoVuelo, TAM_E) == 0){
					printf("\nModificacion Exitosa");
				}
				}else
				{
					printf("\nNo se puede modificar sin antes cargar un pasajero");
				}
				break;

			case 3:
				printf("\nUsted eligio: BAJA\n");
				if(flagAlta == 1)
				{
				if(BajaPasajero(listaPasajeros,TAM,IdPasajeroBaja, tipoPasajero, TAM_T,estadoVuelo, TAM_E) == 0)
				{
					printf("\nBAJA EXITOSA");
				}
				}
				else
				{
					printf("\nNo se puede dar de baja sin antes cargar un pasajero");
				}
				break;
			case 4:
				printf("\nUsted eligio: INFORMAR\n");

				if(flagAlta == 1){
				MostrarListaPasajeros(listaPasajeros,TAM, tipoPasajero, TAM_T,estadoVuelo, TAM_E);

				informes = subMenuInformes();


				switch(informes){
				case 1:
					printf("\nUsted eligio: LISTADO DE PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO DE PASAJERO/n");
					OrdenarPasajerosPorApellidoYTipo(listaPasajeros,TAM,orden);
					break;
				case 2:
					printf("\nUsted eligio: TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y CUANTOS PASAJEROS SUPERAN EL PRECIO  PROMEDIO\n ");
					if(TotalYPromedioPrecios(listaPasajeros, TAM) == 1){
						printf("\nCalculos realizados correctamente");
					}else{
						printf("\nNo se pudieron realizar los calculos");
					}
					break;
				case 3:
					printf("\nUsted eligio: ORDENAR POR CODIGO DE VUELO  Y ESTADO DE VUELO\n ");
					OrdenarPorCodigoYEstado(listaPasajeros, TAM ,orden,tipoPasajero, TAM_T, estadoVuelo,TAM_E);
					break;
				case 4:
					printf("\nSalir");
					break;
				default:
					printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
					break;
				}
				}else
				{
					printf("\nNo se puede informar nada sin antes ingresar un pasajero");
				}
				break;

				case 5:
				printf("\nUSTED ELIGIO: HARDCODEAR");
				hardcodearEmpleados(listaPasajeros,TAM, &pId,tipoPasajero,TAM_T,estadoVuelo,TAM_E);

				break;

			case 6:
				printf("\nUsted eligio: SALIR\n");
				break;
			default:
				printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
				break;
			}

		} while (opcion != 6);











	return EXIT_SUCCESS;
}
