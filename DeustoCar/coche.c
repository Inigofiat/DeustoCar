#include "coche.h"
#include <stdio.h>
void mostrarCoche(Coche coche){
	printf("%22s%22s%24s%21s%20s%20s%20s%20s\n", coche.anio, coche.marca, coche.modelo, coche.precio, coche.cv, coche.color, coche.estado, coche.matricula);
	fflush(stdout);
}
