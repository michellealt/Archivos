#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <stdio.h>
#include "estructuras.h"

void mostrarAlumno(Alumno *a, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("Nombre: %s\n", a[i].nombre);
        printf("Direccion: %s %d %s\n",
               a[i].direccion.callePrincipal,
               a[i].direccion.numeroCasa,
               a[i].direccion.calleSecundaria);

        printf("Edad: %d\n\n", a[i].edad);
    }
}

#endif