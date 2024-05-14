#include "menus.h"
#include "listaClientes.h"
#include "listaCoches.h"
#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

#define NOMBFICHCLIENTES "clientes.txt"
#define NOMBFICHCOCHES "catalogo.txt"

int main() {
	ListaClientes lClientes;
	ListaCoches lCoches;
	Cliente cliente, clienteIniciado;
	int pos;
	char opcion, opcionCliente1, opcionCliente2, opcionCliente3;
	bool sesionActiva = true;

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	volcarFicheroAListaClientes(&lClientes, NOMBFICHCLIENTES);
	volcarFicheroAListaCoches(&lCoches, NOMBFICHCOCHES);

	do {
		opcion = menuPrincipal();
		sprintf(sendBuff,"%c",opcion);
		send(s, sendBuff, sizeof(sendBuff), 0);
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
				opcionCliente1 = menuInicioSesionCliente();
				sprintf(sendBuff,"%c",opcionCliente1);
				send(s, sendBuff, sizeof(sendBuff), 0);

				switch (opcionCliente1) {
				case '1':
					iniciarSesion(cliente.email, cliente.contrasenia);
					sprintf(sendBuff,"%s",cliente.email);
					send(s, sendBuff, sizeof(sendBuff), 0);
					sprintf(sendBuff,"%s",cliente.contrasenia);
					send(s, sendBuff, sizeof(sendBuff), 0);

					//pos = buscarCliente(lClientes, cliente.email);
					recv(s, recvBuff, sizeof(recvBuff), 0);
					sscanf(recvBuff,"%d",&pos);
					if (pos == -1) {
						printf("Email o contraseña incorrectos\n");
						fflush(stdout);
					} else {
						//if (contraseniaCorrecta(lClientes.aClientes[pos].contrasenia,cliente.contrasenia)) {
						recv(s, recvBuff, sizeof(recvBuff), 0);
						int correcta;
						sscanf(recvBuff,"%d",&correcta);
						if(correcta==1){
							printf("Inicio sesión exitoso\n");
							printf(
									"----------------------------------------------------------------------------------"
											"-------------------------------------------------------\n");
							fflush(stdout);
							do {
								opcionCliente2 = menuCliente();
								sprintf(sendBuff,"%c",opcionCliente2);
								send(s, sendBuff, sizeof(sendBuff), 0);

								switch (opcionCliente2) {
								case '1':
									clienteIniciado = lClientes.aClientes[pos];
									mostrarCliente(clienteIniciado);
									printf(
											"----------------------------------------------------------------------------------"
													"-------------------------------------------------------\n");
									fflush(stdout);
									break;
								case '2':
									do {
										opcionCliente3 = menuCatalogo();
										sprintf(sendBuff,"%c",opcionCliente3);
										send(s, sendBuff, sizeof(sendBuff), 0);

										switch (opcionCliente3) {
										case '1':
											recv(s, recvBuff, sizeof(recvBuff), 0);
											int numC;
											Coche coche;
											sscanf(recvBuff,"%d",numC);
											for(int i=0;i<numC;i++){
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.anio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.marca,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.modelo,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.precio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.cv,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.estado,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.color,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.matricula,"%s",s);
											}
											visualizarListaCoches(lCoches);
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '2':
											char anio[5];
										    printf("Introduce el año del coche: ");
										    fflush(stdout);
										    fflush(stdin);
										    gets(anio);
											sprintf(sendBuff,"%c",anio);
											send(s, sendBuff, sizeof(sendBuff), 0);

											recv(s, recvBuff, sizeof(recvBuff), 0);
											int numC;
											Coche coche;
											sscanf(recvBuff,"%d",&numC);
											for ( int i = 0;  i < numC; ++ i) {
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.anio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.marca,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.modelo,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.precio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.cv,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.estado,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.color,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.matricula,"%s",s);
												mostrarCoche(coche); //DUDA

											}
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '3':
											char*marca;
											printf("Introduce la marca del coche: ");
										    fflush(stdout);
										    fflush(stdin);
										    gets(marca);
										    sprintf(sendBuff,"%c",marca);
											send(s, sendBuff, sizeof(sendBuff), 0);

											recv(s, recvBuff, sizeof(recvBuff), 0);
											int numC;
											Coche coche;
											sscanf(recvBuff,"%d",&numC);
											for ( int i = 0;  i < numC; ++ i) {
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.anio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.marca,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.modelo,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.precio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.cv,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.estado,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.color,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.matricula,"%s",s);
												mostrarCoche(coche); //DUDA
											}
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '4':
											char*cvmin, *cvmax;
										    printf("Introduce el valor mínimo de potencia (CV) del coche: ");
										    fflush(stdout);
										    fflush(stdin);
										    gets(cvmin);
										    sprintf(sendBuff,"%c",cvmin);
											send(s, sendBuff, sizeof(sendBuff), 0);
										    printf("Introduce el valor máximo de potencia (CV) del coche: ");
										    fflush(stdout);
										    fflush(stdin);
										    gets(cvmax);
											sprintf(sendBuff,"%c",cvmax);
											send(s, sendBuff, sizeof(sendBuff), 0);
											int numC;
											Coche coche;
											sscanf(recvBuff,"%d",&numC);
											for ( int i = 0;  i < numC; ++ i) {
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.anio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.marca,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.modelo,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.precio,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.cv,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.estado,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.color,"%s",s);
												recv(s, recvBuff, sizeof(recvBuff), 0);
												sprintf(coche.matricula,"%s",s);
												mostrarCoche(coche); //DUDA
											}

											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '5':
											char *precioMin, *precioMax;
											printf("Introduce el valor mínimo de precio del coche: ");
											fflush(stdout);
											fflush(stdin);
											gets(precioMin);
											sprintf(sendBuff,"%c",precioMin);
											send(s, sendBuff, sizeof(sendBuff), 0);
											printf("Introduce el valor máximo de precio del coche: ");
											fflush(stdout);
											fflush(stdin);
											gets(precioMax);
											sprintf(sendBuff,"%c",precioMax);
											send(s, sendBuff, sizeof(sendBuff), 0);
											//filtrarPorPrecio(lCoches);
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '6':
											filtrarPorColor(lCoches);
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										case '7':
											filtrarPorEstado(lCoches);
											printf(
													"----------------------------------------------------------------------------------"
															"-------------------------------------------------------\n");
											fflush(stdout);
											break;
										}
									} while (opcionCliente3 != '0');
									break;
								case '3':
									filtrarCocheCompra(lCoches);
									printf(
											"----------------------------------------------------------------------------------"
													"-------------------------------------------------------\n");
									fflush(stdout);
									volcarListaCochesAFichero(lCoches,
									NOMBFICHCOCHES);
									break;

								}
							} while (opcionCliente2 != '0');
						}
					}
					break;
				case '2':
					cliente = pedirCliente();
					pos = buscarCliente(lClientes, cliente.email);
					if (pos != -1) {
						printf("Lo sentimos! Ese email ya existe\n");
						printf(
								"----------------------------------------------------------------------------------"
										"-------------------------------------------------------\n");
						fflush(stdout);
					} else {
						aniadirCliente(&lClientes, cliente);
						aniadirClienteAlFinalDelFichero(cliente,
						NOMBFICHCLIENTES);
						printf(
								"----------------------------------------------------------------------------------"
										"-------------------------------------------------------\n");
						fflush(stdout);
					}
					break;
				default:
					break;
				}
			} while (opcionCliente1 != '0');
			break;
		default:
			printf("La opción seleccionada NO es correcta\n");
			fflush(stdout);
			fflush(stdin);
			break;
		}
	} while (opcion != '0' && sesionActiva);

	free(lClientes.aClientes);

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();
	return 0;
}

