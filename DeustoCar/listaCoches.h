#ifndef LISTACOCHES_H_
#define LISTACOCHES_H_
#include "coche.h"
#include <stdlib.h>
typedef struct listaCoches{
	Coche * aCoches;
	int tam;
	int numC;
}ListaCoches;

void volcarFicheroAListaCoches (ListaCoches *lco, char *nombfich);
int filtrarPorAnio(ListaCoches lco, Coche co);
int filtrarPorMarca(ListaCoches lco, Coche co);
int filtrarPorCV(ListaCoches lco, Coche co);
void volcarListaCochesAFichero(ListaCoches lco, char *nombfich);
void visualizarListaCoches(ListaCoches lCoches);

#endif /* LISTACOCHES_H_ */
