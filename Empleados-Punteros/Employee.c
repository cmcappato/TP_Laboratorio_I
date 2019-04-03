#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"

///////////////// Empleado /////////////////
Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*) malloc(sizeof(Employee));

    return pEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr)
{
    Employee* pEmployee;

    pEmployee = employee_new();

    if(pEmployee!=NULL)
    {
        employee_setId (pEmployee, atoi(idStr));
        employee_setNombre (pEmployee, nombreStr);
        employee_setHorasTrabajadas( pEmployee, atoi(horasTrabajadasStr));
    }

    return pEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

///////////////// Id /////////////////
int employee_setId(Employee* this,int id)
{
    int indice = 0;

    if (this != NULL && id > 0)
    {
        this -> id = id;
        indice = 1;
    }

    return indice;
}

int employee_getId(Employee* this, int* id)
{
    int indice = 0;

    if(this != NULL)
    {
        *id = this -> id;
        indice = 1;
    }

    return indice;
}

///////////////// Nombre /////////////////
int employee_setNombre(Employee* this, char* nombre)
{
    int indice = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this -> nombre, nombre);
        indice = 1;
    }

    return indice;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (nombre, this->nombre);
        indice = 1;
    }

    return indice;
}

///////////////// Horas trabajadas /////////////////
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int indice = 0;

    if (this != NULL)
    {
        this -> horasTrabajadas = horasTrabajadas;
    }

    return indice;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int indice = 0;

    if(this != NULL)
    {
        *horasTrabajadas = this -> horasTrabajadas;
        indice = 1;
    }

    return indice;
}

///////////////// Sueldo /////////////////
int employee_setSueldo(Employee* this,int sueldo)
{
    int indice = 0;

    if (this != NULL)
    {
        this -> sueldo = sueldo;
        indice = 1;
    }

    return indice;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int indice = 0;

    if(this != NULL)
    {
        *sueldo = this -> sueldo;
        indice = 1;
    }

    return indice;
}

///////////////// Ordenar /////////////////

int sortByName (void* EmployeeA, void* EmployeeB)
{
    int indice = 0;
    Employee* pEmployeeA;
    Employee* pEmployeeB;

    if ((EmployeeA != NULL) && (EmployeeB != NULL))
    {
        pEmployeeA = (Employee*) EmployeeA;
        pEmployeeB = (Employee*) EmployeeB;
        indice = strcmp(pEmployeeB -> nombre, pEmployeeA -> nombre);
    }

    return indice;
}


