#ifndef COCHE_H_
#define COCHE_H_
typedef struct coche{
	char anio[5];
	char marca[30];
	char modelo[50];
	char precio[10];
	char cv[5];
	char estado[15];
	char color[30];
	char matricula[20];
}Coche;
void mostrarCoche(Coche co);
#endif /* COCHE_H_ */
