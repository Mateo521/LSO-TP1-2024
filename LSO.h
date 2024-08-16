//
// Created by Usuario on 16/8/2024.
//
#define MAX_prestadores 110
#ifndef LSO_TP1_2024_LSO_H
#include "Prestadores.h"
typedef struct {
    Prestador prestador [MAX_prestadores];
    int contador;
   }LSO;

int LocalizarLSO(LSO *lista, int *pos, int dni_x) {
    int i = 0;
    while (i < lista->contador  && lista->prestador[i].dni < dni_x) {
        i++;
    }
    *pos = i;
    if (i < lista->contador && lista->prestador[i].dni == dni_x) {
        return 1;
    } else {
        return 0;
    }
}


int AltaLSO(LSO *lista, Prestador prestador) {
    if (lista->contador >= MAX_prestadores) {
        printf("Error: Limite maximo de prestadores alcanzado.\n");
        return 2;
    }

    int pos;
    int i;
    int res = LocalizarLSO(lista, &pos, prestador.dni);
    if (res == 0) {
        for (i = lista->contador - 1; i >= pos; i--) {
            lista->prestador[i + 1] = lista->prestador[i];
        }
        lista->prestador[pos] = prestador;
        lista->contador++;
        printf("Prestador insertado. Nuevo contador: %d\n", lista->contador);
        return 0;
    } else {
        return 1;
    }
}





#define LSO_TP1_2024_LSO_H
#endif
