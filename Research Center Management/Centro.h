/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#ifndef CENTRO_H
#define CENTRO_H
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "Pesquisador.h"

typedef struct centro
{
	int numDepartamentos;
	char ** nomesDepartamentos;
	Lista * listaPesquisadores;
}Centro;

Centro * iniciaCentro(Centro * endCentro, int numDepartamentos);
Centro * criaCentro(int numDepartamentos);

int funcaoHash(Centro centro, int matricula);

int getNumDepartamentos(Centro centro);

void setNomesDepartamentos(Centro * endCentro, char nomeDepartamento[100], int indiceDepartamento);
char * getNomesDepartamentos(Centro * endCentro, int indiceDepartamento);

Lista * getListaPesquisadores(Centro * endCentro, int indiceDepartamento);

Pesquisador * buscaPesquisador(Centro * endCentro, int matricula);
bool inserePesquisador(Centro * endCentro, Pesquisador * endPesquisador);

Pesquisador * removePesquisador(Centro * endCentro, int matricula);

void desalocarCentro(Centro * endCentro);
#endif