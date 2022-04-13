/*
 * Funciones.h
 *
 *  Created on: 9 Apr 2022
 *      Author: Zequi
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// @brief  Utiliza un printf para crear un mensaje
///
/// @param message: toma la string que se escribe en el main
void getMessage(char message[]);
/// @brief Muestra un menu para ingresar los precios de los vuelos@brief
///
void showSubMenu(void);
/// @brief Limpia la consola
///
void cleanConsole(void);
/// @brief Pide un numero entero al usuario
///
/// @param number es la variable que recibe como parametro desde el main
/// @param message recibe un mensaje por medio de un puntero
/// @return retorna un entero ingresado por el usuario
int getInteger(int number, char message[]);
/// @brief Pide un numero flotante al usuario
///
/// @param number es la variable que recibe como parametro desde el main
/// @param message recibe un mensaje por medio de un puntero
/// @return retorna un flotante ingresado por el usuario
float getFloat(float number, char message[]);
/// @brief valida los numeros ingresados
///
/// @param number es el numero que recibe para ser validado
/// @param minNumber es el numero que recibe para validar el minimo
/// @param errorMessage es el mensaje que recibe al cumplir con la condicion del while
/// @return
float validateNumber(float number, int minNumber, char errorMessage[]);
/// @brief Calcula el descuento
///
/// @param number es el numero recibido al que se le calculara el descuento
/// @return retorna number con el descuento aplicado
float makeDiscount(float number);
/// @brief Calcula el interes
///
/// @param number es el numero recibido al que se le calculara el interes
/// @return retorna number con el interes aplicado
float makeInterest(float number);
/// @brief Realiza una conversion del numero ingresado en pesos a Bitcoin
///
/// @param number es el numero recibido al que se le calculara la conversion
/// @return retorna number convertido a bitcoin
float calculateBitcoin(float number);
/// @brief Calcula el precio unitario del numero ingresado
///
/// @param number es el numero recibido al que se le calculara el precio unitario
/// @param kilometers es la cantidad de kilometros que dividira a number
/// @return retorna el precio unitario de number
float calculateUnitary(float number, float kilometers);
/// @brief Calcula la diferencia entre los precios de latam y aerolineas
///
/// @param number recibe el valor del precio de Latam
/// @param anotherNumber recibe el valor del precio de Aerolineas
/// @return retorna la diferencia entre ambos parametros
float calculateDifference(float number, float anotherNumber);


#endif /* FUNCIONES_H_ */
