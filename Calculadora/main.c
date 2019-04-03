#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    float operandoA = 0;
    float operandoB = 0;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factorialA = 0;
    int factorialB = 0;
    int opcion;
    int banderaOperandoA = 0;
    int banderaOperandoB = 0;

    do
    {
        printf("Seleccione la opcion deseada: \n");
        printf("1- Para ingresar el primer numero: \n");
        printf("2- Para ingresar el segundo numero: \n");
        printf("3- Para realizar todas las operaciones: \n");
        printf("4- Para mostrar resultados: \n");
        printf("5- Para salir: \n");
        printf("----------------------------------------\n");
        printf("Los numeros ingresados son: %.2f y %.2f\n", operandoA, operandoB);
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            operandoA = getFloat ("Ingrese el primer numero: ");
            banderaOperandoA = 1;
            break;
        case 2:
            operandoB = getFloat ("Ingrese el segundo numero: ");
            banderaOperandoB = 1;
            break;
        case 3:
            if (banderaOperandoA == 1 && banderaOperandoB == 1)
            {
                suma = funcionSuma (operandoA, operandoB);
                resta = funcionResta (operandoA, operandoB);
                multiplicacion = funcionMultiplicacion (operandoA, operandoB);
                division = funcionDivision (operandoA, operandoB);
                factorialA = (int) funcionFactorial (operandoA);
                factorialB = (int) funcionFactorial (operandoB);

                printf("Se han realizado todos los calculos\n");
            }
            else
            {
                printf("No se han ingresado numeros \n");
            }
            break;
        case 4:
            if (banderaOperandoA == 1 && banderaOperandoB == 1)
            {
                printf("Resultados:\n");
                printf("Suma: %.2f \n", suma);
                printf("Resta: %.2f \n", resta);
                printf("Multiplicacion: %.2f \n", multiplicacion);
                if (operandoB == 0)
                {
                    printf("No se puede dividir por cero \n");
                }
                else
                {
                    printf("Division: %.2f \n", division);
                }
                if (operandoA < 0)
                {
                    printf("No se puede calcular factorial de un numero negativo\n");
                }
                else
                {
                    if (operandoA == 0)
                    {
                        factorialA = 1;
                        printf("Factorial del primer numero: %d\n", factorialA);
                    }
                    else
                    {
                        printf("Factorial del primer numero: %d\n", factorialA);
                    }

                }
                if (operandoB < 0)
                {
                    printf("No se puede calcular factorial de un numero negativo\n");
                }
                else
                {
                    if (operandoB == 0)
                    {
                        factorialB = 1;
                        printf("Factorial del segundo numero: %d\n", factorialB);
                    }
                    else
                    {
                        printf("Factorial del segundo numero: %d\n", factorialB);
                    }
                }
            }
            else
            {
                printf("No se han ingresado numeros, por lo tanto no hay nada para calcular\n");
            }
            break;
        case 5:
            opcion = '5';
            printf("Gracias por utilizar la calculadora\n");
            break;
        default:
            printf("La opcion ingresada no es correcta, intente nuevamente\n");
            break;
        }

        system("pause");
        system("cls");

    }
    while (opcion != '5');
    return 0;
}
