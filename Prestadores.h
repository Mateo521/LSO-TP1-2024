#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char dni[9];
    char nombre_y_apellido[80];
    char servicios[120];
    char domicilio[80];
    char mail[50];
    char telefono[30];
}Prestador;


void Mostrarprestador(Prestador prestador) {
    printf("DNI: %s\n", prestador.dni);
    printf("Nombre y Apellido: %s\n", prestador.nombre_y_apellido);
    printf("Servicios: %s\n", prestador.servicios);
    printf("Domicilio: %s\n", prestador.domicilio);
    printf("Email: %s\n", prestador.mail);
    printf("Telefono: %s\n", prestador.telefono);
}