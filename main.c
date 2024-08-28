#include <stdio.h>
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
    char dniAux[9],nombre_y_apellidoAux[80], serviciosAux[120], domicilioAux[80], mailAux[50], telefonoAux[30];

    printf("Ingresar DNI: ");
    scanf("%s",dniAux);
    fflush(stdin);
    printf("Ingrese el nombre y apellido: ");
    scanf("%[^\n]s",&nombre_y_apellidoAux);
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

    strcpy(p.dni,dniAux);
    strcpy(p.nombre_y_apellido,nombre_y_apellidoAux);
    strcpy(p.servicios,serviciosAux);
    strcpy(p.domicilio,domicilioAux);
    strcpy(p.mail,mailAux);
    strcpy(p.telefono,telefonoAux);

    return p;
}

void insertarPrestador(LSO *lista) {
    Prestador p = cargarPrestador();
    int pos=0, exito=-1;

        exito=altaLSO(lista,p);
        if(exito == 1) {
            printf("Prestador insertado. Cantidad de prestadores: %d \n", lista->contador);
        }else if(exito == 0) {
            printf("EL prestador ya se encuentra en la lista\n");
        }else {
            printf("Error al cargar.\n");
        }
    system("pause");
    system("cls");
}

void eliminarPrestador(LSO *lista) {
    int pos=0, exito=-1;
    char dniAux[9];
    printf("Ingrese el DNI del prestador:");
    scanf("%s",dniAux);
    fflush(stdin);
    exito=bajaLSO(lista,dniAux);
    if(exito) {
        printf("Se elimino el prestador\n");
    }else {
        printf("Se cancelo la eliminacion");
    }
    system("pause");
    system("cls");
}

void mostrarListaPrestador(LSO *lista)
{
    int i;
    for (i = 0; i < lista->contador; i++)
    {
        printf("Envio nro : %d\n",i+1);
        Mostrarprestador(lista->prestador[i]);
    }
    printf("Total de %d envios\n", lista->contador);
    system("pause");
    system("cls");
}

void modificarPrestador(LSO *lista) {
    int fin=0;
    char dniAux[9];
    printf("Ingrese el DNI del prestador:");
    scanf("%s",dniAux);
    fflush(stdin);
    if(modificarLSO(lista,dniAux)) {
        printf("Se modifico con exito");
    }else {
        printf("Se cancelo la modificacion.");
    }
    system("pause");
    system("cls");
}

void consultarPrestador(LSO *lista){
    char dniAux[9];
    int exito = -1;
    printf("Ingrese el DNI del prestador:");
    scanf("%s",dniAux);
    fflush(stdin);
    Prestador p = evocarLSO(lista,dniAux,&exito);
    if(exito) {
        Mostrarprestador(p);
    }else {
        printf("No se encontro el prestador");
    }
    system("pause");
    system("cls");
}

int lecturaDatos(LSO *lso) {
    Prestador aux;
    FILE *fp;

    if ((fp = fopen("C:/Users/mateo/Desktop/LSO-TP1-2024/Prestadores.txt", "r")) == NULL) {
        printf("Hubo un error con la lectura del archivo.\n");
        return 0;  // Error al abrir el archivo
    }

    while (!feof(fp)) {
        // Leer DNI
        if (fscanf(fp, "%s\n", &aux.dni) != 1) break;
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



        // Agregar el registro leído a la lista
         altaLSO(lso, aux);
    }

    // Cerrar el archivo
    fclose(fp);
    return 1;
}





