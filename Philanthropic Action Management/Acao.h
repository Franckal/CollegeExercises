/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef ACAO_H
#define ACAO_H
#include <stdlib.h>
#include <string.h>
#include "Lista.h"


typedef struct acao
{
 	char codAcao[6];
	char tituloAcao[50];
	char descricao[100];
	Lista * voluntarios;
}Acao;

//Funções de alocação
Acao * _criaAcao();
Acao * criaAcao(char codAcao[6], char tituloAcao[50], char descricao[100], Lista * voluntarios);

//Funções para manipulação
void setCodAcao(Acao * endAcao, char codAcao[6]);
char * getCodAcao(Acao * endAcao);

void setTituloAcao(Acao * endAcao, char tituloAcao[50]);
char * getTituloAcao(Acao * endAcao);

void setDescricao(Acao * endAcao, char descricao[100]);
char * getDescricao(Acao * endAcao);

void setVoluntarios(Acao * endAcao, Lista * voluntarios);
Lista * getVoluntarios(Acao * endAcao);


//Funções para desalocar
void deletarAcao(Acao * acao);

#endif