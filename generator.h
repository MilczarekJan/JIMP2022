#ifndef _GENERATOR_H
#define _GENERATOR_H

#include <stdlib.h>

typedef struct para {
	int wezel;
	double droga;
} para;

typedef struct listapar {
	para pary;
  struct listapar* next;
} listapar;

typedef struct graf {
  listapar lista;
	int kolumny;
	int wiersze;
} graf;

double randomdouble(double min, double max);
void creategraph(FILE* new_file, int ilosckolumn, int iloscwierszy, double dolnagranica, double gornagranica);


#endif
