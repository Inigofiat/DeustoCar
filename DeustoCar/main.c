#include "menus.h"
#include "listaClientes.h"
#include <stdio.h>
#define NOMBFICH "clientes.txt"

int main() {
    ListaClientes lc;
    Cliente cliente,clienteIniciado;
    int pos;
    char opcion, opcionCliente;


    volcarFicheroAListaClientes(&lc, NOMBFICH);

    do {
        opcion = menuPrincipal();
        switch (opcion) {
            case '0':
                printf("El programa se ha cerrado\n");
                fflush(stdout);
                break;
            case '1':
                printf("El área de administrador se hará en C++\n");
                fflush(stdout);
                break;
            case '2':
                do {
                    opcionCliente = menuInicioSesionCliente();
                    switch (opcionCliente) {
                        case '1':
                            iniciarSesion(cliente.email, cliente.contrasenia);
                            pos = buscarCliente(lc, cliente.email);
                            if (pos == -1){
								printf("Email o contraseña incorrectos\n");
								fflush(stdout);
                            } else {
                            	if(contraseniaCorrecta(lc.aClientes[pos].contrasenia, cliente.contrasenia)){
                            		printf("Inicio sesión exitoso\n");
                            		printf("----------------------------------------------------------------------------------"
                            					"-------------------------------------------------------\n");
									fflush(stdout);
									clienteIniciado = lc.aClientes[pos];
									mostrarCliente(clienteIniciado);
									printf("----------------------------------------------------------------------------------"
									            "-------------------------------------------------------\n");
																		fflush(stdout);
                            	}
                            }
                            break;
                        case '2':
                        	cliente = pedirCliente();
                        	pos = buscarCliente(lc,cliente.email);
                        	if(pos!=-1){
                        		printf("Lo sentimos! Ese email ya existe\n");
                        		printf("----------------------------------------------------------------------------------"
                        		                            					"-------------------------------------------------------\n");
                        		fflush(stdout);
                        	}else{
                        		aniadirCliente(&lc, cliente);
                        		aniadirClienteAlFinalDelFichero(cliente, NOMBFICH);
                        		printf("----------------------------------------------------------------------------------"
                        		                            					"-------------------------------------------------------\n");
                        		fflush(stdout);
                        	}
                        default:
                            break;
                    }
                } while (opcionCliente != '0');
                break;
            default:
                printf("La opción seleccionada NO es correcta\n");
                fflush(stdout);
				fflush(stdin);
                break;
        }
    } while (opcion != '0');

    free(lc.aClientes);
    return 0;
}
