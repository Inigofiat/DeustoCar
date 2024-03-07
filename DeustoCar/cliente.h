#ifndef CLIENTE_H_
#define CLIENTE_H_
typedef struct cliente{
	char nombre[20];
	char apellido[20];
	char dni[10];
	char telefono[10];
	char email[30];
	char direccion[30];
	char contrasenia[30];
}Cliente;
Cliente pedirCliente();
void mostrarCliente(Cliente c);
int contraseniaCorrecta(char *conC, char *con);
void iniciarSesion(char *email, char *con);
//int emailCorrecto (char *emailC, char *email);
#endif /* CLIENTE_H_ */
