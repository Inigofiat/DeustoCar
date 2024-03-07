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
	gets(cliente.apellido);

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

	printf("Introduce tu contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(cliente.contrasenia);

	return cliente;
}


int contraseniaCorrecta(char *conC, char *con){
	int conCorrecta = 0;
	if(strcmp(conC, con)==0){
		conCorrecta=1;
	}
	return conCorrecta;
}

void iniciarSesion(char *email, char*con){

	printf("Introduce tu email: ");
	fflush(stdout);
	fflush(stdin);
	gets(email);
	printf("Introduce tu contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(con);
}

//int emailCorrecto(char *emailC, char *email){
//	int correoCorrecto = 0;
//	if(strcmp(emailC, email)==0){
//		correoCorrecto=1;
//	}
//	return correoCorrecto;
//}

