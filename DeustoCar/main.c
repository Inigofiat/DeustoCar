#include "menus.h"
#include "listaClientes.h"
#include <stdio.h>
//#define NOMBFICH "clientes.txt"
int main() {
	ListaClientes lc;
//	Cliente cliente;
//	int pos;
	char opcion, opcionCliente;

	//volcarFicheroAListaClientes(&lc, NOMBFICH);
	do {
		opcion = menuPrincipal();
		switch (opcion) {
			case '0':
				printf("El programa se ha cerrado\n");
				fflush(stdout);
				break;
			case '1':
				printf("El área de administrador se hará en C++");
				break;
			case '2':
				menuCliente();
				break;
			default:
				printf("La opción seleccionada NO es correcta\n");
				break;
		}


	} while (opcion!='0');
	//free(lc.aClientes);
}


