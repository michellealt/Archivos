#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include <string.h>
#include "estructuras.h"

void guardarArchivo(Alumno *a, int tam)
{
    FILE *archivo = fopen("alumnos.csv", "w");

    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for(int i=0; i<tam; i++)
    {
        fprintf(archivo,"%s;%s;%d;%s;%d\n",
                a[i].nombre,
                a[i].direccion.callePrincipal,
                a[i].direccion.numeroCasa,
                a[i].direccion.calleSecundaria,
                a[i].edad);
    }

    fclose(archivo);
}

void leerArchivo()
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[200];

    while(fgets(linea, sizeof(linea), archivo) != NULL)
    {
        printf("%s", linea);
    }

    fclose(archivo);
}

void buscarAlumno(char *nombreBuscado)
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno;
    int encontrado = 0;

    while(fscanf(archivo,"%49[^;];%49[^;];%d;%49[^;];%d\n",
                 alumno.nombre,
                 alumno.direccion.callePrincipal,
                 &alumno.direccion.numeroCasa,
                 alumno.direccion.calleSecundaria,
                 &alumno.edad) == 5)
    {
        if(strcmp(alumno.nombre, nombreBuscado) == 0)
        {
            printf("\nRegistro encontrado\n");
            printf("Nombre: %s\n", alumno.nombre);
            printf("Direccion: %s %d %s\n",
                   alumno.direccion.callePrincipal,
                   alumno.direccion.numeroCasa,
                   alumno.direccion.calleSecundaria);
            printf("Edad: %d\n", alumno.edad);

            encontrado = 1;
            break;
        }
    }

    if(!encontrado)
    {
        printf("No existe el nombre buscado\n");
    }

    fclose(archivo);
}

#endif