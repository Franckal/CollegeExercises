/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#include "Pesquisador.h"

//Alocação Dinâmica e desalocação
Pesquisador * criaPesquisadorVazio()
{
	return malloc(sizeof(Pesquisador));	
}

Pesquisador * criaPesquisador(int matricula, char nome[50], char formacao[100], char contato[50])
{
	Pesquisador * novoPesquisador = criaPesquisadorVazio();
	setMatricula(novoPesquisador, matricula);
	setNome(novoPesquisador, nome);
	setFormacao(novoPesquisador, formacao);
	setContato(novoPesquisador, contato);

	return novoPesquisador;
}

void destroiPesquisador(Pesquisador * endPesquisador)
{
	free(endPesquisador);
	endPesquisador = NULL;
}

//Manipulação de Campos
void setMatricula(Pesquisador * endPesquisador, int matricula)
{
	endPesquisador -> matricula = matricula;
}

int getMatricula(Pesquisador * pesquisador)
{
	return pesquisador -> matricula;
}

void setNome(Pesquisador * endPesquisador, char nome[50])
{
	strcpy(endPesquisador -> nome, nome);
}

char * getNome(Pesquisador * endPesquisador)
{
	return endPesquisador -> nome;	
}

void setFormacao(Pesquisador * endPesquisador, char formacao[100])
{
	strcpy(endPesquisador -> formacao, formacao);
}

char * getFormacao(Pesquisador * endPesquisador)
{
	return endPesquisador -> nome;
}

void setContato(Pesquisador * endPesquisador, char contato[50])
{
	strcpy(endPesquisador -> contato, contato);
}

char * getContato(Pesquisador * endPesquisador)
{
	return endPesquisador -> contato;
}