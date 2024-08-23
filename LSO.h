//
// Created by Usuario on 16/8/2024.
//
#ifndef LSO_TP1_2024_LSO_H
#define LSO_TP1_2024_LSO_H
#include "Prestadores.h"
#define MAX_prestadores 111 ///CONSULTAR SI AGG UN LUGAR MAS PARA EL INFINITO
#define MasInfinito "9999999"


typedef struct {
    Prestador prestador [MAX_prestadores];
    int contador;
}LSO;

void initLSO(LSO *lso) {
    lso->contador = 0;
    for (int i = 0; i < MAX_prestadores; i++) {
        strcpy(lso->prestador[i].dni, MasInfinito); // Inicializa todas las posiciones con MasInfinito
    }
}

int localizarLSO(LSO *lista, int *pos, char dni_x[]) {
    if(lista->contador == 0 ) {
        return 0;
    }

    while ((*pos) < lista->contador && strcmp(lista->prestador[(*pos)].dni, MasInfinito) != 0 && strcmp(lista->prestador[(*pos)].dni, dni_x) < 0) {
        (*pos)++;
    }

    if (strcmp(lista->prestador[(*pos)].dni, MasInfinito) != 0 && strcmp(lista->prestador[(*pos)].dni,dni_x) == 0) {
        return 1;
    } else {
        return 0;
    }
}


int altaLSO(LSO *lista, Prestador prestador) {
    if (lista->contador >= MAX_prestadores) {
        return 2;
    }
    int pos=0, i=0;
    if (!(localizarLSO(lista, &pos, prestador.dni))) {
        for (i = (lista->contador); i > pos; i--) {
            lista->prestador[i] = lista->prestador[i - 1];
        }
        lista->prestador[pos] = prestador;
        lista->contador++;
        return 1;
    } else {
        return 0;
    }
}

int bajaLSO(LSO *lista, char dni_x[]) {
    int pos = 0, resp=0 , i=0;
    if(localizarLSO(lista, &pos,dni_x)) {
        printf("Prestador N %d \n",pos+1);
        printf("DNI: %s \n",lista->prestador[pos].dni);
        printf("Nombre y Apellido: %s\n", lista->prestador[pos].nombre_y_apellido);
        printf("Servicios: %s\n", lista->prestador[pos].servicios);
        printf("Domicilio: %s\n", lista->prestador[pos].domicilio);
        printf("Email: %s\n", lista->prestador[pos].mail);
        printf("Telefono: %s\n", lista->prestador[pos].telefono);
        printf("Desea eliminar este prestador? \n 1)Si\n 0)No\n Ingrese:");
        scanf("%d", &resp);
        if (resp == 1) {
            for(i=pos; i< lista->contador; i++) {
                lista->prestador[i] = lista->prestador[i+1];
            }
            lista->contador --;
            return 1;
        }else {
            return 0;
        }
    }
}

int modificarLSO(LSO *lista, char dni_x[]){
    int pos=0,fin=0;
    char nombre_y_apellidoAux[80], serviciosAux[120], domicilioAux[80], mailAux[50], telefonoAux[30];
    do{
        if (localizarLSO(lista,&pos,dni_x)){ ///SACAR ESTO AFUERA O NO
            printf("*********Prestador N: %d \n",pos+1);
            printf("***DNI: %s \n",lista->prestador[pos].dni);
            printf("<1>Nombre y Apellido: %s\n", lista->prestador[pos].nombre_y_apellido);
            printf("<2>Servicios: %s\n", lista->prestador[pos].servicios);
            printf("<3>Domicilio: %s\n", lista->prestador[pos].domicilio);
            printf("<4>Email: %s\n", lista->prestador[pos].mail);
            printf("<5>Telefono: %s\n", lista->prestador[pos].telefono);
            printf("<6>Terminar modificaciones \n");
            printf("Que desea modificar <1-6> \n");
            scanf("%d",&fin);
            fflush(stdin);
            switch(fin){
                case 1:
                    system("cls");
                    printf("Ingrese el nuevo nombre y apellido\n");
                    scanf("%[^\n]s",nombre_y_apellidoAux);
                    strcpy(lista->prestador->nombre_y_apellido,nombre_y_apellidoAux);
                    break;
                case 2:
                    system("cls");
                    printf("Ingrese el nuevo Servicio\n");
                    scanf("%[^\n]s",serviciosAux);
                strcpy(lista->prestador->servicios,serviciosAux);
                    break;
                case 3:
                    system("cls");
                    printf("Ingrese el nuevo Domicilio\n");
                    scanf("%[^\n]s",domicilioAux);
                strcpy(lista->prestador->domicilio,domicilioAux);
                    break;
                case 4:
                    system("cls");
                    printf("Ingrese el nuevo Email\n");
                    scanf("%s",&mailAux);
                    strcpy(lista->prestador->mail,mailAux);
                    break;
                case 5:
                    system("cls");
                    printf("Ingrese el nuevo Telefono\n");
                    scanf("%[^\n]s",telefonoAux);
                    strcpy(lista->prestador->telefono,telefonoAux);
                    break;
                case 6:
                    return 1;
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("-------------------Opcion Incorrecta--------------------\n");
                    printf("------Presione cualquier tecla para volver al menu------");
                    getchar();
                    break;
            }
        }
    }while(fin !=6);
    return 0;
}

Prestador evocarLSO(LSO *lista, char dni_x[], int *exito) {
    int pos=0;
    *exito = localizarLSO(lista, &pos, dni_x);
    if(*exito) {
        return lista->prestador[pos];
    }
}


#endif
