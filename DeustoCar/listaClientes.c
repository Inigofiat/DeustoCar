#include "listaClientes.h"
#include <stdio.h>
#include <string.h>

int buscarCliente(ListaClientes lc, char *dni){
	int pos=0,enc=0;
	while(!enc && pos<lc.numC){
		if(strcmp(lc.aClientes[pos].dni,dni)==0){
			enc=1;
		}else{
			pos++;
		}
	}
	if(enc){
		return pos;
	}else{
		return -1;
	}
}

volcarFicheroAListaClientes(ListaClientes *lc, char *nombfich){
	FILE *pf;
	Cliente cliente;
	pf=fopen(nombfich, "r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%d", &lc->tam);
		lc->aClientes = (Cliente*)malloc(lc->tam * sizeof(Cliente));
		lc->numC++;
	}
	fclose(pf);
}
