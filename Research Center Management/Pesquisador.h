/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#ifndef PESQUISADOR_H
#define PESQUISADOR_H
#include <stdlib.h>
#include <string.h>

typedef struct psqs
{
	int matricula;
	char nome[50];
	char formacao[100];
	char contato[50];
}Pesquisador;

//Alocação Dinâmica e desalocação
Pesquisador * criaPesquisadorVazio();
Pesquisador * criaPesquisador(int matricula, char nome[50], char formacao[100], char contato[50]);
void destroiPesquisador(Pesquisador * endPesquisador);

//Manipulação de Campos
void setMatricula(Pesquisador * endPesquisador, int matricula);
int getMatricula(Pesquisador * pesquisador);

void setNome(Pesquisador * endPesquisador, char nome[50]);
char * getNome(Pesquisador * endPesquisador);

void setFormacao(Pesquisador * endPesquisador, char formacao[100]);
char * getFormacao(Pesquisador * endPesquisador);

void setContato(Pesquisador * endPesquisador, char contato[50]);
char * getContato(Pesquisador * endPesquisador);


#endif