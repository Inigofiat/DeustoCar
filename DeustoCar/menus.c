#include <stdio.h>
char menuPrincipal(){
	char opcion;
	printf("1. Área administrador\n");
	printf("2. Área cliente\n");
	printf("0. Cerrar programa\n");
	printf("Seleccione una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	printf("----------------------------------------------------------------------------------"
			"-------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	return opcion;

}

char menuInicioSesionCliente(){
	char opcion;
	printf("1. Iniciar sesión\n");
	printf("2. Registrarse\n");
	printf("0. Volver al menú principal\n");
	printf("Seleccione una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &opcion);
	printf("----------------------------------------------------------------------------------"
				"-------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	return opcion;
}

char menuCliente(){
	char opcion;
	printf("1. Perfil\n");
	printf("2. Catalogo\n");
	printf("3. Comprar\n");
	printf("4. Vender\n");
	printf("0. Cerrar sesión\n");
	printf("Seleccione una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &opcion);
	printf("----------------------------------------------------------------------------------"
			"-------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	return opcion;
}

char menuAdministrador(){
	char opcion;
	printf("1. Añadir coches\n");
	printf("2. Eliminar coches\n");
	printf("3. Ver clientes");
	printf("4. Ver coches disponibles\n");
	printf("0. Salir\n");
	printf("Seleccione una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &opcion);
	printf("----------------------------------------------------------------------------------"
			"-------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	return opcion;
}

char menuCatalogo(){
	char opcion;
	printf("1. Ver todo el catálogo\n");
	printf("2. Filtrar por AÑO\n");
	printf("3. Filtrar por MARCA\n");
	printf("4. Filtrar por CV\n");
	printf("5. Filtrar por PRECIO\n");
	printf("6. Filtrar por COLOR\n");
	printf("7. Filtrar por ESTADO\n");
	printf("0. Cerrar Sesión\n");
	printf("Seleccione una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", &opcion);
	printf("----------------------------------------------------------------------------------"
			"-------------------------------------------------------\n");
	fflush(stdout);
	fflush(stdin);
	return opcion;
}
