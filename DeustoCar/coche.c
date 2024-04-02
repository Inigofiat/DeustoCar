#include "coche.h"
#include <stdio.h>
void mostrarCoche(Coche coche){
    printf("%-20s%-21s%-24s%-21s%-19s%-24s%-24s%-20s\n", coche.anio, coche.marca, coche.modelo, coche.precio, coche.cv, coche.color, coche.estado, coche.matricula);
    fflush(stdout);
}


