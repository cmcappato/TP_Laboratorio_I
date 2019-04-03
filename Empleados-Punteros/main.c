#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    int control;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        printf("*******************************************************************************\n");
        printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3- Alta de empleado\n");
        printf("4- Modificar datos de empleado\n");
        printf("5- Baja de empleado\n");
        printf("6- Listar empleados\n");
        printf("7- Ordenar empleados\n");
        printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9- Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("10- Salir\n");
        printf("*******************************************************************************\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch(option)
        {

            case 1:
                control = controller_loadFromText("data.csv", listaEmpleados);
                if (control)
                {
                    printf("Archivo cargado con exito\n");
                }
                else
                {
                    printf("No se pudo abrir el archivo\n");
                }
                break;
            case 2:
                control = controller_loadFromBinary("data.dat", listaEmpleados);
                if (control)
                {
                    printf("Archivo cargado con exito\n");
                }
                else
                {
                    printf("No se pudo abrir el archivo\n");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv", listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin", listaEmpleados);
                break;
            case 10:
                printf("Gracias por utilizar este programa \n");
                break;
            default:
                printf("Opcion incorrecta");
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}
