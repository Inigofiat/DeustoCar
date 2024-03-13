#include "menus.h"
#include "listaClientes.h"
#include "listaCoches.h"
#include <stdio.h>
#include <stdbool.h>

#define NOMBFICHCLIENTES "clientes.txt"
#define NOMBFICHCOCHES "catalogo.txt"

int main() {
    ListaClientes lClientes;
    ListaCoches lCoches;
    Cliente cliente, clienteIniciado;
    int pos;
    char opcion, opcionCliente;
    bool sesionActiva = true;

    volcarFicheroAListaClientes(&lClientes, NOMBFICHCLIENTES);
    volcarFicheroAListaCoches(&lCoches, NOMBFICHCOCHES);

    do {
        opcion = menuPrincipal();
        switch (opcion) {
            case '0':
                printf("Sesión cerrada\n");
                fflush(stdout);
                sesionActiva = false;
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
                            pos = buscarCliente(lClientes, cliente.email);
                            if (pos == -1) {
                                printf("Email o contraseña incorrectos\n");
                                fflush(stdout);
                            } else {
                                if (contraseniaCorrecta(lClientes.aClientes[pos].contrasenia, cliente.contrasenia)) {
                                    printf("Inicio sesión exitoso\n");
                                    printf("----------------------------------------------------------------------------------"
                                           "-------------------------------------------------------\n");
                                    fflush(stdout);
                                    do {
                                        opcionCliente = menuCliente();
                                        switch (opcionCliente) {
                                            case '1':
                                                clienteIniciado = lClientes.aClientes[pos];
                                                mostrarCliente(clienteIniciado);
                                                printf("----------------------------------------------------------------------------------"
                                                       "-------------------------------------------------------\n");
                                                fflush(stdout);
                                                break;
                                            case '2':
                                                do {
                                                    opcionCliente = menuCatalogo();
                                                    switch (opcionCliente) {
                                                        case '1':
                                                            visualizaListaCoches(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '2':
                                                            filtrarPorAnio(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '3':
                                                            filtrarPorMarca(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '4':
                                                            filtrarPorCV(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '5':
                                                            filtrarPorPrecio(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '6':
                                                            filtrarPorColor(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                        case '7':
                                                            filtrarPorEstado(lCoches);
                                                            printf("----------------------------------------------------------------------------------"
                                                                   "-------------------------------------------------------\n");
                                                            fflush(stdout);
                                                            break;
                                                    }
                                                } while (opcionCliente != '0');
                                                break;
                                            case'3':
                                            	filtrarCocheCompra(lCoches);
												printf("----------------------------------------------------------------------------------"
													   "-------------------------------------------------------\n");
												fflush(stdout);
												volcarListaCochesAFichero(lCoches,NOMBFICHCOCHES);
												break;

                                        }
                                    } while (opcionCliente != '0');
                                }
                            }
                            break;
                        case '2':
                            cliente = pedirCliente();
                            pos = buscarCliente(lClientes, cliente.email);
                            if (pos != -1) {
                                printf("Lo sentimos! Ese email ya existe\n");
                                printf("----------------------------------------------------------------------------------"
                                       "-------------------------------------------------------\n");
                                fflush(stdout);
                            } else {
                                aniadirCliente(&lClientes, cliente);
                                aniadirClienteAlFinalDelFichero(cliente, NOMBFICHCLIENTES);
                                printf("----------------------------------------------------------------------------------"
                                       "-------------------------------------------------------\n");
                                fflush(stdout);
                            }
                            break;
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
    } while (opcion != '0' && sesionActiva);

    free(lClientes.aClientes);
    return 0;
}

