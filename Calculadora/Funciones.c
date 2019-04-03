#include <stdio.h>
#include "Funciones.h"

float funcionSuma (float operandoA, float operandoB)
{
    float suma;

    suma = operandoA + operandoB;

    return suma;
}

float funcionResta (float operandoA, float operandoB)
{
    float resta;

    resta = operandoA - operandoB;

    return resta;
}

float funcionMultiplicacion (float operandoA, float operandoB)
{
    float multiplicacion;

    multiplicacion = operandoA * operandoB;

    return multiplicacion;
}

float funcionDivision (float operandoA, float operandoB)
{
    float division;

    if (operandoB == 0)
    {

    }
    else
    {
        division = operandoA / operandoB;
    }

    return division;
}

int funcionFactorial(int numero)
{
    int factorial;

    if (numero < 0)
    {

    }
    else
    {
        if (numero == 0)
        {
            return 1;
        }
        else
        {
            factorial = numero * funcionFactorial (numero - 1);
        }
    }
    return factorial;
}

float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);

    return auxiliarFloat;
}
