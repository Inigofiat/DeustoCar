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
void filtrarPorAnio(ListaCoches lco);
void filtrarPorMarca(ListaCoches lco);
void filtrarPorCV(ListaCoches lco);
void filtrarPorPrecio(ListaCoches lco);
void filtrarPorColor(ListaCoches lco);
void filtrarPorEstado(ListaCoches lco);
void volcarListaCochesAFichero(ListaCoches lco, char *nombfich);
void visualizarListaCoches(ListaCoches lCoches);

#endif /* LISTACOCHES_H_ */
