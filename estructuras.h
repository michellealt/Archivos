#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct
{
    char callePrincipal[50];
    int numeroCasa;
    char calleSecundaria[50];

} Direccion;

typedef struct
{
    char nombre[50];
    Direccion direccion;
    int edad;

} Alumno;

#endif