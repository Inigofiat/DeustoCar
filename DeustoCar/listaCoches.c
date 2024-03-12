#include "listaCoches.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coche.h"

void volcarFicheroAListaCoches(ListaCoches *lco, char *nombfich){
	FILE *pf;
	Coche coche;
	pf=fopen(nombfich, "r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%d", &lco->tam);
		lco->aCoches = (Coche*)malloc(lco->tam * sizeof(Coche));
		lco->numC=0;
		while(fscanf(pf, "%s %s %s %s %s %s %s %s", coche.anio, coche.marca, coche.modelo, coche.precio, coche.cv, coche.color, coche.estado, coche.matricula) != EOF) {
		    lco->aCoches[lco->numC] = coche;
		    lco->numC++;
		}

		fclose(pf);
	}
}



void visualizaListaCoches(ListaCoches lCoches){
	int i;
	Coche coche;
	printf("%22s%22s%24s%22s%22s%22s%22s%22s\n", "AÑO", "MARCA", "MODELO", "PRECIO", "POTENCIA(CV)", "COLOR", "ESTADO", "MATRÍCULA");
	fflush(stdout);
	for (i = 0; i < lCoches.numC; i++) {
		coche = lCoches.aCoches[i];
		mostrarCoche(coche);
	}
}


void filtrarPorAnio(ListaCoches lco) {
    char anio[5];
    int pos = 0;
    int encontrado = 0;
    printf("Introduce el año del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(anio);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].anio, anio) == 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }
    if (!encontrado) {
        printf("No se encontraron coches para el año especificado.\n");
        fflush(stdout);
    }
}

void filtrarPorMarca(ListaCoches lco) {
    char marca[30];
    int pos = 0;
    int encontrado = 0;
    printf("Introduce la marca del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(marca);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].marca, marca) == 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }

    if (!encontrado) {
        printf("No se encontraron coches para la marca especificada.\n");
        fflush(stdout);
    }
}

void filtrarPorColor(ListaCoches lco) {
    char color[30];
    int pos = 0;
    int encontrado = 0;
    printf("Introduce el color del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(color);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].color, color) == 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }

    if (!encontrado) {
        printf("No se encontraron coches para el color especificado.\n");
        fflush(stdout);
    }
}

void filtrarPorEstado(ListaCoches lco) {
    char estado[30];
    int pos = 0;
    int encontrado = 0;
    printf("Los estados disponibles son: Nuevo o Seminuevo\n");
    printf("Introduce el color del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(estado);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].estado, estado) == 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }

    if (!encontrado) {
        printf("No se encontraron coches para el estado especificado.\n");
        fflush(stdout);
    }
}

void filtrarPorCV(ListaCoches lco) {
    char cvMin[5], cvMax[5];
    int pos = 0;
    int encontrado = 0;
    printf("Introduce el valor mínimo de potencia (CV) del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(cvMin);
    printf("Introduce el valor máximo de potencia (CV) del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(cvMax);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].cv, cvMin) >= 0 && strcmp(lco.aCoches[pos].cv, cvMax) <= 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }
    if (!encontrado) {
        printf("No se encontraron coches para el intervalo de potencia especificado.\n");
        fflush(stdout);
    }
}

void filtrarPorPrecio(ListaCoches lco) {
    char precioMin[10], precioMax[10];
    int pos = 0;
    int encontrado = 0;
    printf("Introduce el valor mínimo de precio del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(precioMin);
    printf("Introduce el valor máximo de precio del coche: ");
    fflush(stdout);
    fflush(stdin);
    gets(precioMax);
    while (pos < lco.numC) {
        if (strcmp(lco.aCoches[pos].precio, precioMin) >= 0 && strcmp(lco.aCoches[pos].precio,precioMax) <= 0) {
            mostrarCoche(lco.aCoches[pos]);
            fflush(stdout);
            encontrado = 1;
        }
        pos++;
    }
    if (!encontrado) {
        printf("No se encontraron coches para el intervalo de precio especificado.\n");
        fflush(stdout);
    }
}


