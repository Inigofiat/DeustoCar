#ifndef COCHE_H_
#define COCHE_H_
typedef struct coche{
	char anio[4];
	char marca[30];
	char modelo[50];
	char precio[7];
	char cv[4];
}Coche;
void mostrarCoche(Coche co);
#endif /* COCHE_H_ */
