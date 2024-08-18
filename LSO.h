//
// Created by Usuario on 16/8/2024.
//
#define MAX_prestadores 110
#ifndef LSO_TP1_2024_LSO_H
#include "Prestadores.h"
typedef struct {
    Prestador prestador [MAX_prestadores];
    int contador = 0;
   }LSO;

void initLSO(LSO *lso) {
    lso->prestador[0].dni= "*";
}

int localizarLSO(LSO *lista, int *pos, int dni_x) {
    int i = 0;
    while ( lista->contador <= MAX_prestadores && strcmp(lista->prestador[i].dni,"*") != 0  && strcmp(lista->prestador[i].dni,dni_x) < 0) {
        i++;
    }
    *pos = i;
    if (i < lista->contador && strcmp(lista->prestador[i].dni, "*") != 0) {
        return 1;
    } else {
        return 0;
    }
}


int altaLSO(LSO *lista, Prestador prestador) {
    if (lista->contador >= MAX_prestadores) {
        printf("Error: Limite maximo de prestadores alcanzado.\n");
        return 2;
    }
    int pos=0, i=0;
    if (!localizarLSO(lista, &pos, prestador.dni)) {
        for (i = lista->contador - 1; i >= pos; i--) {
            lista->prestador[i + 1] = lista->prestador[i];
        }
        lista->prestador[pos] = prestador;
        lista->contador++;
        printf("Prestador insertado. Cantidad de prestadores: %d \n", lista->contador);
        return 1;
    } else {
        return 0;
    }
}

int bajaLSO(LSO *lista, Prestador prestador) {
    int pos = 0, resp=0 , i=0;
    if(localizarLSO(lista, &pos,prestador.dni)) {
        printf("Prestador N %d \n",pos+1);
        printf("DNI: %s \n",lista->prestador[pos].dni);
        printf("Nombre y Apellido: %s\n", lista->prestador[pos].nombre_y_apellido);
        printf("Servicios: %s\n", lista->prestador[pos].servicios);
        printf("Domicilio: %s\n", lista->prestador[pos].domicilio);
        printf("Email: %s\n", lista->prestador[pos].mail);
        printf("Telefono: %s\n", lista->prestador[pos].telefono);
        printf("Desea eliminar este prestador? \n 1) Si\n 0)No\n Ingrese:");
        scanf("%d", &resp);
        if (resp == 1) {
            while(i=pos, i<= lista->contador, i++) {
                lista->prestador[i] = lista->prestador[i+1];
            }
            lista->contador --;
            printf("Prestador eliminado con exito. Cantidad de prestadores: %d \n", lista->contador);
            return 1;
        }else {
            return 0;
        }
    }
}



#define LSO_TP1_2024_LSO_H
#endif
