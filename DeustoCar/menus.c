#include <stdio.h>
char menuPrincipal(){
	char opcion;
	printf("1.Área administrador\n");
	printf("2.Área cliente\n");
	printf("0.Cerrar programa\n");
	printf("Seleccione una opción: \n");
	printf("-----------------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}

char menuCliente(){
	char opcion;
	printf("1.Iniciar sesión\n");
	printf("2.Registrarse\n");
	printf("0. Volver al menú principal\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &opcion);
	return opcion;
}
