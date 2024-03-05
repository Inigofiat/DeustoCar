#ifndef CLIENTE_H_
#define CLIENTE_H_
typedef struct cliente{
	char nombre[20];
	char apellidos[20];
	char dni[10];
	char telefono[9];
	char email[30];
	char direccion[30];
}Cliente;
Cliente pedirCliente();
void mostrarCliente(Cliente c);
int contraseniaCorrecta(char *conU, char *con);

#endif /* CLIENTE_H_ */
