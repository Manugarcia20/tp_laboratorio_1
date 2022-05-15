
#include "ArrayPassenger.h"
#include "ArrayTipoPasajero.h"
#include "ArrayEstadoVuelo.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/////////////////// PUNTO 1 ALTA ///////////////////////////
int InicializarPasajeros(ePasajero listaPasajeros[], int tam) {
	int i;
	int isOK = -1;
	if (listaPasajeros != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			listaPasajeros[i].isEmpty = LIBRE;
			isOK = 0;
		}
	}
	return isOK;
}
int BuscarEspacioLibre(ePasajero listaPasajeros[], int tam, int *pIndex) {
	int isOk = 0;

	if(listaPasajeros != NULL && tam > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i = 0; i < tam; i++)
		{
			if(listaPasajeros[i].isEmpty == 0)
			{
				*pIndex = i;
				break;
			}
		}
		isOk = 1;

	}
	return isOk;
}



int AltaPasajero(ePasajero *listaPasajeros, int tam, int *pId, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado) {
	int isOk = 0;
	int indice;
	int idTipo;
	int idEstado;

	ePasajero nuevoPasajero;


	if (listaPasajeros != NULL && tam > 0 && pId != NULL) {


		if (BuscarEspacioLibre(listaPasajeros, tam, &indice)) {

			if (indice == -1)
			{
				printf("\nNo hay lugar en el sistema");

			}
			else
			{
				while (getStringLetras("\nIngrese un nombre: ", nuevoPasajero.nombre) == -1)
				{
					printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
				}

				while (getStringLetras("\nIngrese un apellido: ", nuevoPasajero.apellido) == -1)
				{
					printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
				}

			    CargarPrecio(&nuevoPasajero.precio, "\nIngrese el precio de vuelo:  ", "\nError. Ingrese solo numeros: ");

			    while (getStringAlfaNumerico("\nIngrese un codigo de vuelo: ", nuevoPasajero.codigoVuelo) == -1)
			   	{
			    	printf("\nCaracteres invalidos. Por favor, ingrese solo numeros o letras: ");
			    }

			    printf("\n\n");

			    listarTipos(tipoPasajero,tamPas);
			    idTipo = getValidInt("\nIngrese el tipo de pasajero: ", "\nError, ingrese un tipo correcto: ", 5000, 5002);
			    nuevoPasajero.idTipo = idTipo;

			    printf("\n\n");

			    listarEstados(estadoVuelo,tamEstado);
			   	idEstado = getValidInt("\nIngrese el estado de vuelo: ", "\nError, ingrese un tipo correcto: ", 1, 3);
			   	nuevoPasajero.idEstado = idEstado;




					nuevoPasajero.isEmpty = OCUPADO;
					nuevoPasajero.id = *pId;
					(*pId)++;

					listaPasajeros[indice] = nuevoPasajero;
					isOk = 1;

			}

		}
	}

		return isOk;

	}

	void CargarPrecio(float *precio, char mensaje[], char mensajeError[]) {
		char auxPrecio[51];

		printf("%s", mensaje);
		scanf("%s", auxPrecio);

		while (!(esNumericoFlotante(auxPrecio))) {
			printf("%s", mensajeError);
			scanf("%s", auxPrecio);
		}

		*precio = atof(auxPrecio);

	}

////////////////////////////////// PUNTO 2 MODIFICACION ///////////////////////////////////////////////////

	int ModificarPasajeros(ePasajero listaPasajeros[], int tam , int idPasajeroCambio, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado)
	{
		int isOk;
		int subMenu;
		int indexPasajeroCambio;
		int nuevoTipo;
		char respuesta;


					isOk = -1;
					if (listaPasajeros != NULL && tam > 0) {
						printf("\n		*** MODIFICACION DE PASAJEROS ***						\n\n");
						MostrarListaPasajeros(listaPasajeros, tam, tipoPasajero,tamPas,estadoVuelo, tamEstado); //--muestro pasajeros activos
						idPasajeroCambio = getValidInt( "\nIngrese el id del pasajero a modificar:  ", "Error, ingrese un ID valido:  ", 1, 2000);
						indexPasajeroCambio = FindPassengerById(listaPasajeros, tam, idPasajeroCambio);
						if (indexPasajeroCambio != -1) //el empleado existe
								{

							respuesta = getChar("\nEsta seguro de que quiere modificar al pasajero %d ? s/n ", idPasajeroCambio);
							if (respuesta == 's') {

								do{
								subMenu = subMenuModificar();
								switch(subMenu){
								case 1:
									printf("\nUsted eligio: MODIFICAR NOMBRE\n");
									while (getStringLetras("\nIngrese un nuevo nombre: ", listaPasajeros->nombre) == -1)
									{
										printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									break;
								case 2:
									printf("\nUsted eligio: MODIFICAR APELLIDO\n");
									while (getStringLetras("\nIngrese un nuevo apellido: ", listaPasajeros->apellido) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									break;
								case 3:
									printf("\nUsted eligio: MODIFICAR PRECIO DE VUELO\n");
									CargarPrecio(&listaPasajeros->precio, "\nIngrese el nuevo precio de vuelo:  ", "\nError. Ingrese solo numeros");
									break;
								case 4:
									printf("\nUsted eligio: MODIFICAR CODIGO DE VUELO\n");
									while (getStringAlfaNumerico("\nIngrese un codigo de vuelo: ", listaPasajeros->codigoVuelo) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo numeros o letras");
									}
									break;
								case 5:
									printf("\nUsted eligio: MODIFICAR TIPO DE PASAJERO\n");
									 listarTipos(tipoPasajero,tamPas);
									 nuevoTipo = getValidInt("\nIngrese el id del nuevo tipo de pasajero: " , "\nError, ingrese un id valido: ",5000,5002);
									 listaPasajeros->idTipo = nuevoTipo;
									break;
								case 6:
									printf("\nUsted eligio: SALIR\n");
									break;
								default:
									printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
									break;
								}
								}while(subMenu !=6);

							}else{
								printf("\nModificacion cancelada");
							}







	}else
	{
		printf("\nNo hay ningun pasajero cargado con el id %d", idPasajeroCambio);
	}
					}

		return isOk;
	}




///////////////////////////////// PUNTO 3 BAJA ///////////////////////////////////////////////////////

//retorna -1 si el id que me pasan no existe / o lista invalida
//  la posicion en caso de que el id que me pasan exista

	int FindPassengerById(ePasajero listaPasajeros[], int tam, int id) {
		int posicionPasajero;

		posicionPasajero = -1; /*En caso de no haber espacio, lista nula o id inexistente*/

		if (listaPasajeros != NULL && tam > 0) {
			for (int i = 0; i < tam; i++) {
				if (listaPasajeros[i].id == id) {
					posicionPasajero = i;
				}
			}
		}
		return posicionPasajero;
	}

	int BajaPasajero(ePasajero listaPasajeros[], int tam, int idPasajeroBaja, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado) {
			int isOk;
			int indexPasajeroBaja;
			char respuesta;

			isOk = -1;
			if (listaPasajeros != NULL && tam > 0) {
				printf("\n		*** BAJA DE PASAJEROS ***						\n\n");
				MostrarListaPasajeros(listaPasajeros, tam, tipoPasajero, tamPas, estadoVuelo, tamEstado); //--muestro pasajeros activos
				idPasajeroBaja = getValidInt( "\nIngrese el id del pasajero a eliminar:  ", "Error, ingrese un ID valido:  ", 1, 2000);
				indexPasajeroBaja = FindPassengerById(listaPasajeros, tam, idPasajeroBaja);
				if (indexPasajeroBaja != -1) //el empleado existe
						{

					respuesta = getChar("\nEsta seguro de que quiere eliminar al pasajero? s/n ");
					if (respuesta == 's') {
						listaPasajeros[indexPasajeroBaja].isEmpty = LIBRE;
						isOk = 0;
					}else{
						printf("\nBaja cancelada");
					}

				} else {
					printf("\nEl id %d no esta registrado en el sistema",idPasajeroBaja);
				}




				//busqueda de ID y comparar
				//Analizar que este ocupado y luego cambiar el estado
			}
			return isOk;
		}





////////////////////////////////////////////////////////////  MOSTRAR   //////////////////////////////////////////////////////////////////////////////////////////////////////////

	int MostrarUnPasajero(ePasajero unPasajero, eTipo tipoPasajero[],eEstadoVuelo estadoVuelo[], int tam, int tamEstado) {
		int isOk = 0;
		char descTipo[20];
		char descEstado[20];

		if(tipoPasajero != NULL && tam > 0)
		{
		CargarDescripcionTipo(tipoPasajero, tam, unPasajero.idTipo, descTipo);
		CargarDescripcionEstado(estadoVuelo,tam, unPasajero.idEstado, descEstado);

		printf("\n%d          %s %s          %.2f         %s	    %10s      %10s  \n",    unPasajero.id,
															 	     unPasajero.nombre,
																	 unPasajero.apellido,
																  	 unPasajero.precio,
																	 unPasajero.codigoVuelo,
																	 descTipo,
																	 descEstado
																  );

		isOk = 1;
		}
		return isOk;
	}

	int MostrarListaPasajeros(ePasajero listaPasajeros[], int tam, eTipo tipoPasajero[], int tamTipo, eEstadoVuelo estadoVuelo[], int tamEstado) {

		int i;
		int isOK = 0;

		if (listaPasajeros != NULL && tam > 0) {

			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("		*** LISTA DE PASAJEROS ***		\n");
			printf("--------------------------------------------------------------------------------------------------------\n");
			printf("ID		NOMBRE		PRECIO VUELO	CODIGO DE VUELO	 TIPO DE PASAJERO	ESTADO DE VUELO	\n");
			printf("---------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < tam; i++) {
				if (listaPasajeros[i].isEmpty == OCUPADO) {
					MostrarUnPasajero(listaPasajeros[i],tipoPasajero,estadoVuelo,tamTipo, tamEstado);
				}
				isOK = 1;
			}
		}

		return isOK;
	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int OrdenarPasajerosPorApellidoYTipo(ePasajero listaPasajeros[], int tam, int orden)
	{
	    //      Ordena el array de empleados por apellido
	    //      y sector de manera ascendente o descendente
	    ePasajero auxPasajero;

	    orden = getValidInt("\n\nIngrese 1 si quiere ordenar de manera ascendente o 0 si quiere ordenar de manera descendente: ", "Error, ingrese un numero: ", 0,1);
	    if(orden)// order == 1
	    {
	        for(int i=0; i<tam-1; i++)
	        {
	            for(int j=i+1; j<tam; j++)
	            {
	                //criterio+condicion de ordenamiento dentro del if > o <
	                if(strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido) > 0)
	                {
	                    auxPasajero=listaPasajeros[i];
	                    listaPasajeros[i]=listaPasajeros[j];
	                    listaPasajeros[j]=auxPasajero;
	                }
	                //criterio+condicion de ordenamiento dentro del if > o <
	                if(listaPasajeros[i].idTipo>listaPasajeros[j].idTipo)
	                {
	                    auxPasajero=listaPasajeros[i];
	                    listaPasajeros[i]=listaPasajeros[j];
	                    listaPasajeros[j]=auxPasajero;
	                }
	            }
	        }
	    }
	    else// order != 1
	    {
	        for(int i=0; i<tam-1; i++)
	        {
	            for(int j=i + 1; j < tam; j++)
	            {
	                //criterio+condicion de ordenamiento dentro del if > o <
	                if(strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido) < 0)
	                {
	                    auxPasajero=listaPasajeros[i];
	                    listaPasajeros[i]=listaPasajeros[j];
	                    listaPasajeros[j]=auxPasajero;
	                }
	                //criterio+condicion de ordenamiento dentro del if > o <
	                if(listaPasajeros[i].idTipo<listaPasajeros[j].idTipo)
	                {
	                    auxPasajero=listaPasajeros[i];
	                    listaPasajeros[i]=listaPasajeros[j];
	                    listaPasajeros[j]=auxPasajero;
	                }
	            }
	        }
	    }
	    return 0;
	}


	int TotalYPromedioPrecios(ePasajero listaPasajeros[], int tam){
		int isOk = 0;
		float acumPrecios = 0;
		int cantPrecios = 0;
	    float promedio;
	    int arribaProm = 0;

		    if(listaPasajeros != NULL && tam > 0 )
		    {

		        for(int i=0; i < tam; i++)
		        {

		             if(listaPasajeros[i].isEmpty == 1)
		            {
		             acumPrecios += listaPasajeros[i].precio;
		             cantPrecios+= 1;
		            }
		        }

		        promedio = (float)acumPrecios/cantPrecios;

		        for(int i=0; i < tam; i++){
		        	if(listaPasajeros[i].precio > promedio){
		        		arribaProm+=1;
		        	}
		        }




		        printf("\n    *** Informe total y promedio de precios   ***\n\n");
		        printf("\nEl total de precio de los vuelos es: $%.2f pesos\n", acumPrecios);
		        printf("\nEl promedio de los precios es : $ %.2f pesos\n", promedio);
		        printf("\nLas cantidad de personas que superan el promedio son: %d\n", arribaProm);

		        isOk = 1;
		    }


		return isOk;

	}


	int OrdenarPorCodigoYEstado(ePasajero listaPasajeros[], int tam, int orden, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado){

		   ePasajero auxPasajero;

			    orden = getValidInt("\n\nIngrese 1 si quiere ordenar de manera ascendente o 0 si quiere ordenar de manera descendente: ", "Error, ingrese un numero: ", 0,1);
			    if(orden)// order == 1
			    {
			        for(int i=0; i<tam-1; i++)
			        {
			            for(int j=i+1; j<tam; j++)
			            {
			                //criterio+condicion de ordenamiento dentro del if > o <
			                if(strcmp(listaPasajeros[i].codigoVuelo,listaPasajeros[j].codigoVuelo) > 0)
			                {
			                    auxPasajero=listaPasajeros[i];
			                    listaPasajeros[i]=listaPasajeros[j];
			                    listaPasajeros[j]=auxPasajero;
			                }
			                //criterio+condicion de ordenamiento dentro del if > o <
			                if(listaPasajeros[i].idEstado>listaPasajeros[j].idEstado)
			                {
			                    auxPasajero=listaPasajeros[i];
			                    listaPasajeros[i]=listaPasajeros[j];
			                    listaPasajeros[j]=auxPasajero;
			                }
			            }
			        }
			    }
			    else// order != 1
			    {
			        for(int i=0; i<tam-1; i++)
			        {
			            for(int j=i + 1; j < tam; j++)
			            {
			                //criterio+condicion de ordenamiento dentro del if > o <
			                if(strcmp(listaPasajeros[i].codigoVuelo,listaPasajeros[j].codigoVuelo) < 0)
			                {
			                    auxPasajero=listaPasajeros[i];
			                    listaPasajeros[i]=listaPasajeros[j];
			                    listaPasajeros[j]=auxPasajero;
			                }
			                //criterio+condicion de ordenamiento dentro del if > o <
			                if(listaPasajeros[i].idTipo<listaPasajeros[j].idTipo)
			                {
			                    auxPasajero=listaPasajeros[i];
			                    listaPasajeros[i]=listaPasajeros[j];
			                    listaPasajeros[j]=auxPasajero;
			                }
			            }
			        }
			    }

			    for(int i = 0; i < tam; i++)
			    {
			    	if(listaPasajeros[i].isEmpty == 1 && listaPasajeros[i].idEstado == 1){
			    		MostrarUnPasajero(listaPasajeros[i],tipoPasajero, estadoVuelo, tam, tamEstado);
			    	}

			    }



			    return 0;
			}




	/////////////////////////////////////////////////////////////////////////////////


	int hardcodearEmpleados(ePasajero *listaPasajeros, int tam, int *pId, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado)
	{

	    int todoOk = 0;
	    ePasajero auxHardcodeo[] =
	    {
	    		{1, "Juan", "Martinez" , 30000, "rtos3k", 5000, 1},
				{1, "Ricardo", "Lopez" , 90000, "csf423", 5001, 2},
				{1, "Julieta", "Gomez" , 86000, "scdfv5", 5002, 1},
				{1, "Mabel",   "Diaz"  , 48000, "awerf2", 5000, 1},
				{1, "Matias", "Benitez" ,25000, "4gds7k", 5002, 3},

	    };

	    if(listaPasajeros!= NULL && tam > 0 && pId != NULL && tipoPasajero != NULL && tamPas > 0 && estadoVuelo != NULL && tamEstado > 0)
	    {

	        for(int i=0; i < tam; i++)
	        {
	            listaPasajeros[i] = auxHardcodeo[i];
	            listaPasajeros[i].id = *pId;
	            *pId = *pId +1;
	        }


	        for(int i = 0; i < tam; i++){

	        MostrarUnPasajero(listaPasajeros[i],tipoPasajero,estadoVuelo,tamPas, tamEstado);
	        }



	        todoOk = 1;
	    }
	    return todoOk;

	}






