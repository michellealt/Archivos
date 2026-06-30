#include <stdio.h>
#include <string.h>

#include "estructuras.h"
#include "mostrar.h"
#include "archivo.h"

int main()
{
    Alumno p1[2];
    char nombreBuscado[50];

    strcpy(p1[0].nombre, "Juan");
    strcpy(p1[0].direccion.callePrincipal, "Av. Prensa");
    p1[0].direccion.numeroCasa = 123;
    strcpy(p1[0].direccion.calleSecundaria, "Florida");
    p1[0].edad = 20;

    strcpy(p1[1].nombre, "Maria");
    strcpy(p1[1].direccion.callePrincipal, "Av. Galo Plaza");
    p1[1].direccion.numeroCasa = 456;
    strcpy(p1[1].direccion.calleSecundaria, "Borja");
    p1[1].edad = 22;

    printf("=== Datos en memoria ===\n\n");
    mostrarAlumno(p1, 2);

    guardarArchivo(p1, 2);

    printf("\n=== Contenido del archivo ===\n\n");
    leerArchivo();

    printf("\nIngrese el nombre a buscar: ");
    fgets(nombreBuscado, 50, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    buscarAlumno(nombreBuscado);

    return 0;
}