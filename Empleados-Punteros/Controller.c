#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivoTexto;
    int indice = 0;

    if ((pArchivoTexto = fopen(path, "r")) != NULL)
    {
        indice = parser_EmployeeFromText(pArchivoTexto, pArrayListEmployee);
    }

    fclose(pArchivoTexto);

    return indice;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivoBinario;
    int indice = 0;

    if ((pArchivoBinario = fopen(path, "rb")) != NULL)
    {
        indice = parser_EmployeeFromBinary(pArchivoBinario, pArrayListEmployee);
    }

    fclose(pArchivoBinario);

    return indice;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee = employee_new();
    int indice = 0;
    char auxiliarId[20];
    int auxiliarIdDecimal;
    char auxiliarNombre[50];
    char auxiliarHoras[30];
    char auxiliarSueldo[20];

    if(pArrayListEmployee != NULL)
    {
        auxiliarIdDecimal = getValidInt ("Ingrese ID del empleado: ", "Error, ingrese un ID valido: ", 1, 10000);
        itoa(auxiliarIdDecimal, auxiliarId, 10);

        getValidStringEspaciosYLetras ("Ingrese nombre del empleado: ", "Error, ingrese un nombre valido: ", auxiliarNombre);
        getValidStringNumeros ("Ingrese las horas trabajadas: ", "Error, ingrese horas validas: ", auxiliarHoras);
        getValidStringNumeros ("Ingrese el sueldo del empleado: ", "Error, ingrese sueldo valido: ", auxiliarSueldo);

        newEmployee = employee_newParametros(auxiliarId, auxiliarNombre, auxiliarHoras);

        if (auxiliarId != NULL)
        {
            auxiliarIdDecimal = atoi(auxiliarSueldo);
            employee_setSueldo(newEmployee, auxiliarIdDecimal);
            ll_add(pArrayListEmployee, newEmployee);
            indice = 1;
        }
    }
    return indice;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    Employee* pNewEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);
    char auxId[20];
    int auxiliarId;
    int auxiliarIdDecimal;
    char auxiliarNombre [50];
    char auxiliarHoras [30];
    int horasAux;
    char auxiliarSueldo [20];
    int sueldoAux;
    int option;

    if (pArrayListEmployee != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);
        auxiliarId = getValidInt("Ingrese el ID del empleado que desea modificar: ", "Error, ID no valido, ingrese nuevamente: ", 1, 10000);

        for (int i = 0; i < tamLista; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxiliarId == pEmployee -> id)
            {
                do
                {
                    printf("Elija que desea modificar: \n");
                    printf("1- ID del empleado \n");
                    printf("2- Nombre del empleado \n");
                    printf("3- Horas que trabajo el empleado \n");
                    printf("4- Sueldo del empleado \n");
                    printf("5- Salir");
                    printf("*******************************************************************************\n");
                    scanf("%d", &option);

                    switch (option)
                    {
                        case 1:
                            auxiliarIdDecimal = getValidInt ("Ingrese ID del empleado: ", "Error, ingrese un ID valido: ", 1, 10000);
                            itoa(auxiliarIdDecimal, auxId, 10);
                            for (i = 0; i < tamLista ; i++)
                            {
                                pNewEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                                if (pNewEmployee -> id == auxiliarIdDecimal)
                                {
                                    indice = 0;
                                    printf("El ID ya existe, intente con otro");
                                    break;
                                }
                                else
                                {
                                    auxiliarId = atoi(auxId);
                                    employee_setId(pEmployee, auxiliarId);
                                }
                            }
                            break;
                        case 2:
                            getValidStringEspaciosYLetras ("Ingrese nombre del empleado: ", "Error, ingrese un nombre valido: ", auxiliarNombre);
                            employee_setNombre(pEmployee, auxiliarNombre);
                            break;
                        case 3:
                            getValidStringNumeros ("Ingrese las horas trabajadas: ", "Error, ingrese horas validas: ", auxiliarHoras);
                            horasAux = atoi(auxiliarHoras);
                            employee_setHorasTrabajadas(pEmployee, horasAux);
                            break;
                        case 4:
                            getValidStringNumeros ("Ingrese el sueldo del empleado: ", "Error, ingrese sueldo valido: ", auxiliarSueldo);
                            sueldoAux = atoi(auxiliarSueldo);
                            employee_setSueldo(pEmployee, sueldoAux);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Ingrese una opcion del 1 al 5");
                    }

                }while (option != 5);
            }
        }
    }
    return indice;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int indice = 1;
    int tamLista = ll_len(pArrayListEmployee);
    int id;

    if(pArrayListEmployee != NULL)
    {
        id = getValidInt("Ingrese ID del empleado que desea eliminar: ", "Error, ingrese un ID valido: ", 1, 10000);

        for (int i = 0; i < tamLista; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if (pEmployee->id == id)
            {
                ll_remove(pArrayListEmployee, i);
                indice = 0;
                printf("Empleado eliminado correctamente");
                employee_delete(pEmployee);
                break;
            }
        }

        if(pEmployee->id != id)
        {
            printf("No se encontro empleado con ese ID");
            indice = 1;
        }
    }


    return indice;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);
    int id;
    char nombre [50];
    int horas;
    int sueldo;


    if(pArrayListEmployee != NULL)
    {
        if (tamLista > 0)
        {
            printf("  ID      Nombre      Horas Trabajadas   Sueldo \n");

            for (int i = 0; i < tamLista; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pEmployee, &id);
                employee_getNombre(pEmployee, nombre);
                employee_getHorasTrabajadas(pEmployee, &horas);
                employee_getSueldo(pEmployee, &sueldo);

                printf("%5d  %10s %10d  %10d\n",id, nombre, horas, sueldo);
            }
            indice = 1;
        }
        else
        {
            printf("No se han cargado los datos");
        }
    }

    return indice;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int indice = 0;

    if (pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, sortByName, 0);
    }
    return indice;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);

    FILE* pArchivoTexto = fopen(path, "w");

    if (pArchivoTexto == NULL)
    {
        printf("No se pudo abrir el archivo");
        return indice;
    }

    fprintf(pArchivoTexto, "ID, Nombre, Horas trabajadas, Sueldo \n");

    if(pArrayListEmployee != NULL)
    {
        for (int i = 0; i < tamLista; i++)
        {
            pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pArchivoTexto, "%d, %s, %d, %d \n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
        }
        printf("El archivo se guardo exitosamente");
        indice = 1;
    }

    fclose(pArchivoTexto);
    return indice;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int indice = 0;
    int tamLista = ll_len(pArrayListEmployee);

    FILE* pArchivoBinario = fopen(path, "wb");

    if (pArchivoBinario == NULL)
    {
       printf("No se pudo abrir el archivo");
       return indice;
    }
    if(pArrayListEmployee != NULL)
    {
        for (int i=0; i < tamLista; i++)
        {
            pEmployee =(Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmployee, sizeof(Employee), 1, pArchivoBinario);
        }
        printf("El archivo se guardo exitosamente");
        indice = 1;
    }

    fclose(pArchivoBinario);

    return indice;
}
