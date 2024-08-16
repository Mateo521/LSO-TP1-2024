#include <stdio.h>
#include "LSO.h"
#include "Prestadores.h"
int main() {


   return 0;
}
int lectura_datos() {
    FILE *fp;
    Prestador aux;
    if ((fp = fopen("Prestadores.txt", "r")) == NULL)
        return 0;
    while (!feof(fp)) {
        if (fscanf(fp, "%d", &aux.dni) == 1) {
            fscanf(fp, " %[^\n]", aux.nombre_y_apellido);
            fscanf(fp, " %[^\n]", aux.servicios);
            fscanf(fp, " %[^\n]", aux.domicilio);
            fscanf(fp, " %[^\n]", aux.mail);
            fscanf(fp, " %[^\n]", aux.telefono);
            // Procesar los datos del prestador
        }
    }
    fclose(fp);
    return 1;
}