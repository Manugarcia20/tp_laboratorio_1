
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "funciones.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "ArrayTipoPasajero.h"
#include "ArrayEstadoVuelo.h"


#define OCUPADO 1
#define LIBRE 0







typedef struct{
int id;
char nombre[51];
char apellido[51];
float precio;
char codigoVuelo[10];
int idTipo;
int idEstado;
int isEmpty;
} ePasajero;

// ALTA

int InicializarPasajeros(ePasajero listaPasajeros[],int tam);

int BuscarEspacioLibre (ePasajero listaPasajeros[], int tam, int *pIndex);

ePasajero CargarUnPasajero();

int AltaPasajero(ePasajero *listaPasajeros, int tam, int *pId, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);

void CargarPrecio(float* precio, char mensaje[], char mensajeError[]);


// MODIFICAR

int ModificarPasajeros(ePasajero listaPasajeros[], int tam , int idPasajeroCambio, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);

//int modificarDatosPasajero(ePasajero listaPasajeros[], int tam);

// BAJA

int BajaPasajero(ePasajero listaPasajeros[], int tam, int idPasajeroBaja, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);

int FindPassengerById(ePasajero* listaPasajeros, int tam, int id);


// MOSTRAR
int MostrarUnPasajero(ePasajero unPasajero, eTipo tipoPasajero[],eEstadoVuelo estadoVuelo[], int tam, int tamEstado);

int MostrarListaPasajeros(ePasajero listaPasajeros[], int tam, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);

// ORDENAR

int OrdenarPasajerosPorApellidoYTipo(ePasajero listaPasajeros[], int tam, int orden);
int TotalYPromedioPrecios(ePasajero listaPasajeros[], int tam);
int OrdenarPorCodigoYEstado(ePasajero listaPasajeros[], int tam, int orden, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);
int hardcodearEmpleados(ePasajero *listaPasajeros, int tam, int *pId, eTipo tipoPasajero[], int tamPas, eEstadoVuelo estadoVuelo[], int tamEstado);

































#endif /* ARRAYEMPLOYEES_H_ */
