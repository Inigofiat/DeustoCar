#include <stdio.h>
#include "cliente.h"
#include <string.h>

Cliente pedirCliente(){
	Cliente cliente;
	printf("Introduce tu nombre: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.nombre);

	printf("Introduce tus apellidos: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.apellidos);

	printf("Introduce tu dni: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.dni);

	printf("Introduce tu teléfono: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.telefono);

	printf("Introduce tu email: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.email);

	printf("Introduce tu dirección: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.direccion);

	return cliente;
}


int contraseniaCorrecta(char *conU, char *con){
	int conCorrecta = 0;
	if(strcmp(conU, con)==0){
		conCorrecta=1;
	}
	return conCorrecta;
}
