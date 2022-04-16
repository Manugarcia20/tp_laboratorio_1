/*
 * funciones.h
 *
 *  Created on: 1 abr. 2022
 *      Author: manu
 */

#define FUNCIONES_H_

/// Esta funcion lo que hace es mostrar todos los resultados calculados previamente, los cuales fueron guardados en una variable
/// para cada uno siendo estas las que se le pasan por parametro a la funcion. No devuelve nada ya que su intencion solo es mostrar.
void MostrarResultados(float,float,float,float,float,float,float,float,float);

/// @param mensaje Se le pasa por parametro un array de tipo char llamado mensaje para pedir por consola al usuario el ingreso
/// de un flotante.
/// @return Retorna el flotante ingresado por el usuario.
float IngresarFlotante(char mensaje[]);

/// Esta funcion lo que hace es cargar forzadamente los valores en vez de pedirlos por consola al usuario.
/// Todos estos valores se le pasan por parametro a la funcion para que dentro de ella se calculen con el hardcodeo de los datos.
void CargaForzada(float,float,float,float,float,float,float,float,float,float,float,float);



