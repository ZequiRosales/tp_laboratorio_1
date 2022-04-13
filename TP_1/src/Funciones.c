/*
 * Funciones.c
 *
 *  Created on: 9 Apr 2022
 *      Author: Zequi
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"


void getMessage(char message[])
{
	printf("%s", message);
}

void cleanConsole(void)
{
	printf("\n\n\n\n");
}

void showSubMenu(void)
{
	getMessage("1. Precio vuelo Aerolineas\n2. Precio vuelo Latam\n3. Volver al menu");
}

int getInteger(int number, char message[])
{
	printf("%s", message);
	fflush(stdin);
	scanf("%d", &number);

	return number;
}

float getFloat(float number, char message[])
{
	printf("%s", message);
	fflush(stdin);
	scanf("%f", &number);

	number = validateNumber(number, 0, "Error, ingrese un valor valido: ");

	return number;
}

float validateNumber(float number, int minNumber, char errorMessage[])
{
	while(isdigit(number) || number < minNumber)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%f", &number);
	}

	return number;
}

float makeDiscount(float number)
{
	float totalResult;

	totalResult = number - (number * 10/100);

	return totalResult;
}

float makeInterest(float number)
{
	float totalResult;

	totalResult = number + (number * 25/100);

	return totalResult;
}

float calculateBitcoin(float number)
{
	float totalResult;

	totalResult = number/4606954.55;

	return totalResult;
}

float calculateUnitary(float number, float kilometers)
{
	float totalResult;

	totalResult = number/kilometers;

	return totalResult;
}

float calculateDifference(float number, float anotherNumber)
{
	float totalResult;

	totalResult = number - anotherNumber;

	return totalResult;
}
