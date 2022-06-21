/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#ifndef ARQUIVOCENTRO_H
#define ARQUIVOCENTRO_H
#include <stdlib.h>
#include <stdio.h>
#include "Centro.h"

Centro * carregaDados(char nomeArqv[]);
int gravaDados(Centro * endCentro, char nomeArqv[]);

#endif