/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#ifndef INTERFACECENTRO_H
#define INTERFACECENTRO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Centro.h"

void clear();
int menuPrincipal();

bool entraPesquisador(Centro * endCentro, Pesquisador * novoPesquisador);
void interfaceMostraDepartamentos(Centro * endCentro);
void interfaceMostraPesquisadores(Centro * endCentro, int codDepartamento);
void exibePesquisador(Pesquisador * pesquisador);

#endif

