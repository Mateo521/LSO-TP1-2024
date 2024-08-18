#include <stdio.h>
#include "LSO.h"
void mostrarestructuraLSO(LSO *lista);
int Lectura_datos(LSO *lso);
int main() {
    LSO lso;
    initLSO(&lso);
    Lectura_datos(&lso);

   mostrarestructuraLSO(&lso);
   return 0;
}
int Lectura_datos(LSO *lso) {
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


void mostrarestructuraLSO(LSO *lista)
{
    int i;
    for (i = 0; i < lista->contador; i++)
    {
        Mostrarprestador(lista->prestador[i]);
    }
    printf("Total de %d envios\n", lista->contador);
}



