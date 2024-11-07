#include <stdio.h>
#include <stdlib.h>
#include "LSO.h"
#include <string.h>

int lecturaDatos(LSO *lso);
void insertarPrestador(LSO *lista);
void eliminarPrestador(LSO *lista);
void mostrarListaPrestador(LSO *lista);
void modificarPrestador(LSO *lista);
void consultarPrestador(LSO *lista);
Prestador cargarPrestador();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    LSO lista;
    initLSO(&lista);
    int resp=-1;

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
        system("cls");

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
            case 7: resp=7;system("cls");
                break;
            default: printf("Opcion no valida\n");
                break;
        }
        system("cls");
    }while(resp!=7);
   return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Prestador cargarPrestador() {
    Prestador p;
    long dniAux;
    char nombre_y_apellidoAux[80], serviciosAux[120], domicilioAux[80], mailAux[50], telefonoAux[30];

    printf("Ingresar DNI: ");
    scanf("%ld",&dniAux);
    fflush(stdin);
    printf("Ingrese el nombre y apellido: ");
    scanf("%[^\n]s",nombre_y_apellidoAux);
    fflush(stdin);
    printf("Ingrese el Servicio: ");
    scanf("%[^\n]s",serviciosAux);
    fflush(stdin);
    printf("Ingrese el Domicilio: ");
    scanf("%[^\n]s",domicilioAux);
    fflush(stdin);
    printf("Ingrese el Email: ");
    scanf("%[^\n]s",mailAux);
    fflush(stdin);
    printf("Ingrese el Telefono: ");
    scanf("%[^\n]s",telefonoAux);
    fflush(stdin);
    system("pause");

    p.dni=dniAux;
    strcpy(p.nombre_y_apellido,nombre_y_apellidoAux);
    strcpy(p.servicios,serviciosAux);
    strcpy(p.domicilio,domicilioAux);
    strcpy(p.mail,mailAux);
    strcpy(p.telefono,telefonoAux);

    return p;
}

void insertarPrestador(LSO *lista) {
    if(lista->contador >= MAX_prestadores - 1){
        printf ("Lista llena.\n");
        system("pause");
        return;
    }
    Prestador p = cargarPrestador();
    int exito=-1;
    exito=altaLSO(lista,p);
    if(exito == 1) {
        printf("Prestador insertado. Cantidad de prestadores: %d \n", lista->contador);
    }else if(exito == 0) {
        printf("EL prestador ya se encuentra en la lista\n");
    }else {
        printf("El elemento que quiso ingresar, supera el limite admitido (DNI MAX 99.999.998) \n");
    }
    system("pause");
    system("cls");
}

void eliminarPrestador(LSO *lista) {
    if(lista->contador == 0){
        printf("Error al eliminar.Lista vacia\n");
        system("pause");
        return;
    }
    int exito=-1;
    long dniAux;
    printf("Ingrese el DNI del prestador:");
    scanf("%ld",&dniAux);
    if(dniAux >= MasInfinito){
        printf("Ingreso un dni mayor al limite. Limite %ld\n",MasInfinito);
        system("pause");
        return;
    }
    fflush(stdin);
    exito=bajaLSO(lista,dniAux);
    if(exito == 1) {
        printf("Se elimino el prestador \n");
    }else if(exito == 0) {
        printf("Se cancelo la eliminacion\n");
    }else {
        printf("No se encontro el elemento en la lista.\n");
    }
    system("pause");
    system("cls");
}

void mostrarListaPrestador(LSO *lista)
{
    int i;
    if(lista->contador == 0){
        printf("Error al mostrar.Lista vacia\n");
        return;
    }
    for (i = 0; i < lista->contador; i++)
    {
        printf("Prestador nro : %d\n",i+1);
        Mostrarprestador(lista->prestador[i]);
        if((i % 2)!= 0){
            system("pause");
            system("cls");
        }
    }
    printf("Total de %d prestadores\n", lista->contador);
    system("pause");
    system("cls");
}

void modificarPrestador(LSO *lista) {
    long dniAux;
    if(lista->contador == 0){
        printf("Error al modificar.Lista vacia\n");
        system("pause");
        return;
    }

    printf("Ingrese el DNI del prestador:");
    scanf("%ld",&dniAux);
    if(dniAux >= MasInfinito){
        printf("Ingreso un dni mayor al limite. Limite %ld\n",MasInfinito);
        system("pause");
        return;
    }else{
        fflush(stdin);
        if(modificarLSO(lista,dniAux)) {
            printf("Modificaciones guardadas con exito\n");
        }else {
            printf("Se cancelo la modificacion.\n");
        }
        system("pause");
        system("cls");
    }
}

void consultarPrestador(LSO *lista){
    long dniAux;
    int exito = -1;
    if(lista->contador == 0){
        printf("Error al consultar.Lista vacia\n");
        return;
    }
    printf("Ingrese el DNI del prestador:");
    scanf("%ld",&dniAux);
    if(dniAux >= MasInfinito){
        printf("Ingreso un dni mayor al limite. Limite %ld\n",MasInfinito);
        system("pause");
        return;
    }else{
        fflush(stdin);
        Prestador p = evocarLSO(lista,dniAux,&exito);
        if(exito) {
            Mostrarprestador(p);
        }else {
            printf("No se encontro el prestador\n");
        }
        system("pause");
        system("cls");
    }
}

int lecturaDatos(LSO *lso) {
    Prestador aux;
    FILE *fp;
    int rep = 0, res = 2 , cont =0, limiteExcedido = 0;
    if ((fp = fopen("Prestadores.txt", "r")) == NULL) {
        printf("Hubo un error con la lectura del archivo.\n");
        system("pause");
        return 0;  // Error al abrir el archivo
    }
    while (!feof(fp)) {
        // Leer DNI
        if (fscanf(fp, "%ld\n", &aux.dni) != 1) break;
        // Leer Nombre y Apellido
        if (fgets(aux.nombre_y_apellido, sizeof(aux.nombre_y_apellido), fp) == NULL) break;
        aux.nombre_y_apellido[strcspn(aux.nombre_y_apellido, "\n")] = '\0';  // Eliminar salto de línea al final
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
        res = altaLSO(lso, aux) ;
        switch(res){
        case 0:
            rep++;
            break;
        case 1:
            cont++;
            break;
        case 2:
            printf ("Lista llena.\n");
            if(cont>0)
                printf("Se cargo %d prestador/es en la lista.\n",cont);
            if(cont > rep)
                printf("Hubo %d prestador/es no cargado/s repetido/s\n",rep);
            system("pause");
            fclose(fp);
            return 1;
            break;
        case 3:
            if (!limiteExcedido) {
                printf("Se intento ingresar uno o varios prestadores con dni mayor al limite permitido.\n");
                limiteExcedido = 1;
            }
        }
    }
    if(cont>0)
        printf("Se cargo %d prestador/es en la lista.\n",cont);
    else
        printf("No se cargo ningun prestador\n");

    if(rep > 0)
        printf("Hubo %d prestador/es no cargado/s repetido/s\n",rep);
    system("pause");
    fclose(fp);
    return 1;
}
