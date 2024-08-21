#include <stdio.h>
#include "LSO.h"
int lecturaDatos(LSO *lso);
void insertarPrestador(LSO *lista);
void eliminarPrestador(LSO *lista);
void mostrarListaPrestador(LSO *lista);
void modificarPrestador(LSO *lista);
void consultarPrestador(LSO *lista);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    LSO lista;
    initLSO(&lista);
    lecturaDatos(&lista);
    int resp=-1;
    Prestador p;
    char dniAux[9],nombre_y_apellidoAux[80], serviciosAux[120], domicilioAux[80], mailAux[50], telefonoAux[30];

    do {
        printf("LISTA SECUENCIAL ORDENADA\n");
        printf("MENU\n");
        printf("1.Ingresar Prestador\n");
        printf("2.Eliminar Prestador\n");
        printf("3.Mostrar Lista de Prestadores\n");
        printf("4.Modificar Prestador\n");\
        printf("5.Consultar Prestador\n");
        printf("6.Memorizacion Previa\n");
        printf("7.Salir\n");
        printf("Inserte la operacion a realizar: ");
        scanf("%d",&resp);

        switch(resp) {
            case 1: insertarPrestador(&lista);
                break;
            case 2: eliminarPrestador(&lista);
                break;
            case 3: mostrarListaPrestador(&lista);
                break;
            case 4: modificarPrestador(&lista);
                break;
            case 5: consultarPrestador(&lista);
                break;
            case 6: lecturaDatos(&lista);
                break;
            case 7: resp=7;
                break;
            default: printf("Opcion no valida\n");
                break;
        }
        system("cls");
    }while(resp!=7);
   return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertarPrestador(LSO *lista) {
    Prestador p;
    char dniAux[9],nombre_y_apellidoAux[80], serviciosAux[120], domicilioAux[80], mailAux[50], telefonoAux[30];
    int pos=0, exito=-1;

        printf("Ingresar DNI:");
        scanf("%s",dniAux);
        fflush(stdin);
        printf("Ingrese el nombre y apellido\n");
        scanf("%ld",&nombre_y_apellidoAux);
        fflush(stdin);
        printf("Ingrese el Servicio\n");
        scanf("%[^\n]s",serviciosAux);
        fflush(stdin);
        printf("Ingrese el Domicilio\n");
        scanf("%[^\n]s",domicilioAux);
        fflush(stdin);
        printf("Ingrese el Email\n");
        scanf("%ld",&mailAux);
        fflush(stdin);
        printf("Ingrese el Telefono\n");
        scanf("%[^\n]s",telefonoAux);
        fflush(stdin);

        strcpy(p.dni,dniAux);
        strcpy(p.nombre_y_apellido,nombre_y_apellidoAux);
        strcpy(p.servicios,serviciosAux);
        strcpy(p.domicilio,domicilioAux);
        strcpy(p.mail,mailAux);
        strcpy(p.telefono,telefonoAux);

        exito=altaLSO(lista,p);
        if(exito) {
            printf("Prestador insertado. Cantidad de prestadores: %d \n", lista->contador);
        }else if(exito == 0) {
            printf("EL prestador ya se encuentra en la lista\n");
        }else {
            printf("Lista llena. %d Prestadores cargados\n",lista->contador);
        }
}


int lecturaDatos(LSO *lso) {
    Prestador aux;
    FILE *fp;
    if ((fp = fopen("C:/ruta/absoluta/Prestadores.txt", "r")) == NULL) {
        return 0;  // Error al abrir el archivo
    } else {
        while (!feof(fp)) {
            // Leer DNI
            if (fscanf(fp, "%d\n", &aux.dni) != 1) break;  // Leer DNI y consumir el salto de línea
            // Leer Nombre y Apellido
            if (fgets(aux.nombre_y_apellido, sizeof(aux.nombre_y_apellido), fp) == NULL) break;
            aux.nombre_y_apellido[strcspn(aux.nombre_y_apellido, "\n")] = '\0';
            // Leer Servicios
            if (fgets(aux.servicios, sizeof(aux.servicios), fp) == NULL) break;
            aux.servicios[strcspn(aux.servicios, "\n")] = '\0';
            // Leer Domicilio
            if (fgets(aux.domicilio, sizeof(aux.domicilio), fp) == NULL) break;
            aux.domicilio[strcspn(aux.domicilio, "\n")] = '\0';
            // Leer Email
            if (fgets(aux.mail, sizeof(aux.mail), fp) == NULL) break;
            aux.mail[strcspn(aux.mail, "\n")] = '\0';
            // Leer Teléfono
            if (fgets(aux.telefono, sizeof(aux.telefono), fp) == NULL) break;
            aux.telefono[strcspn(aux.telefono, "\n")] = '\0';

             altaLSO(lso, aux);
        }

        // Cerrar el archivo
        fclose(fp);
        return 1;
    }
}


void mostrarListaPrestador(LSO *lista)
{
    int i;
    for (i = 0; i < lista->contador; i++)
    {
        Mostrarprestador(lista->prestador[i]);
    }
    printf("Total de %d envios\n", lista->contador);
}



