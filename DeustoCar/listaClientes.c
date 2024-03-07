#include "listaClientes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int buscarCliente(ListaClientes lc, char *email){
	int pos=0,enc=0;
	while(!enc && pos<lc.numC){
		if(strcmp(lc.aClientes[pos].email,email)==0){
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

void volcarFicheroAListaClientes(ListaClientes *lc, char *nombfich){
	FILE *pf;
	Cliente cliente;
	pf=fopen(nombfich, "r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%d", &lc->tam);
		lc->aClientes = (Cliente*)malloc(lc->tam * sizeof(Cliente));
		lc->numC=0;
		while(fscanf(pf, "%s %s %s %s %s %s %s", cliente.nombre, cliente.apellido, cliente.dni,
				cliente.telefono, cliente.email, cliente.direccion, cliente.contrasenia)!=EOF){
			lc->aClientes[lc->numC]=cliente;
			lc->numC++;
		}
		fclose(pf);
	}
}

void aniadirCliente(ListaClientes *lc, Cliente cliente){
	if(lc->numC<lc->tam){
		lc->aClientes[lc->numC]=cliente;
		lc->numC++;
		printf("El usuario ha sido registrado con éxito\n");
	}else{
		printf("El usuario no ha podido ser registrado\n");
	}
	fflush(stdout);
}

void aniadirClienteAlFinalDelFichero(Cliente c, char *nomfich){
	FILE *pf;
	pf=fopen(nomfich,"a");
	if(pf!=(FILE*)NULL){
		fprintf(pf, "%s %s %s %s %s %s %s\n", c.nombre, c.apellido, c.dni, c.telefono, c.email, c.direccion,c.contrasenia);
		fclose(pf);
	}
}

