#ifndef LISTACLIENTES_H_
#define LISTACLIENTES_H_
#include "cliente.h"
typedef struct listaClientes{
	Cliente * aClientes;
	int tam;
	int numC;

}ListaClientes;

void volcarFicheroAListaClientes(ListaClientes *lc, char nombfich);
int buscarCliente(ListaClientes lc, char *dni);
void anadirCliente(ListaClientes *lc, Cliente c);
void volcarListaClientesAFichero (ListaClientes lc, char *nombfich);

#endif /* LISTACLIENTES_H_ */