#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int indice = -1;
    Employee* pEmployee;
    int cantidad;
    char id[20];
    char nombre[50];
    char horas[30];
    char sueldo[20];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
        do
        {
            cantidad = fscanf (pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

            if(cantidad == 4)
            {
                pEmployee = employee_new();
                employee_setId( pEmployee, atoi(id));
                employee_setNombre (pEmployee, nombre);
                employee_setHorasTrabajadas (pEmployee, atoi(horas));
                employee_setSueldo (pEmployee, atoi(sueldo));

                if (pEmployee != NULL)
                {
                    ll_add (pArrayListEmployee, pEmployee);
                }
                else
                {
                    printf("No hay mas espacio en memoria");
                }

                indice = 1;
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }

    return indice;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int indice = -1;
    Employee* pEmployee;
    int cantidad;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            pEmployee = employee_new();
            cantidad = fread (pEmployee, sizeof(Employee), 1, pFile);
            if(cantidad != 1)
            {
                if(feof(pFile))
                {
                    ll_add (pArrayListEmployee, pEmployee);
                    break;
                }
                else
                {
                    printf ("no leyo el ultimo registro");
                    break;
                }
            }

        }while(!feof(pFile));
    }
    return indice;
}
