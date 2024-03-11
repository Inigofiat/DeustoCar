#include "listaCoches.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void volcarFicheroAListaClientes(ListaCoches *lco, char *nombfich){
	FILE *pf;
	Coche coche;
	pf=fopen(nombfich, "r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%d", &lco->tam);
		lco->aCoches = (Coche*)malloc(lco->tam * sizeof(Coche));
		lco->numC=0;
		while(fscanf(pf, "%s %s %s %s %s", coche.anio, coche.marca, coche.modelo, coche.precio, coche.cv)!=EOF){
			lco->aCoches[lco->numC]=coche;
			lco->numC++;
		}
		fclose(pf);
	}
}



char filtrarPorAnio (ListaCoches lco, char *anio){
	Coche coche;
	char finalizado = "Ya se ha filtrado";
	int pos=0;
	printf("Introduce el año del coche: ");
	fflush(stdout);
	fflush(stdin);
	anio = gets(coche.anio);
	if(strcmp(lco.aCoches[pos].anio,anio)==0){
		printf(coche);
		fflush(stdout);
		pos++;
	}else{
		pos++;
	}
	return finalizado;
}

