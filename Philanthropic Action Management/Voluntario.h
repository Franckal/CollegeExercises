/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef VOLUNTARIO_H
#define VOLUNTARIO_H
#include <stdlib.h>
#include <string.h>
#include "Acao.h"

typedef struct voluntario
{
	char matricula[6];
	char nomeVolun[50];
	char contato[50];
	Acao * acao;
}Voluntario;

//Funções de alocação dinâmica
Voluntario * _criaVoluntario();
Voluntario * criaVoluntario(char matricula[6], char nomeVolun[50], char contato[50], Acao * acao);

//Funções de manipulação
void setMatricula(Voluntario * endVolun, char matricula[6]);
char * getMatricula(Voluntario * endVolun);

void setNomeVolun(Voluntario * endVolun, char nomeVolun[50]);
char * getNomeVolun(Voluntario * endVolun);

void setContato(Voluntario * endVolun, char contato[50]);
char * getContato(Voluntario * endVolun);

void setAcao(Voluntario * endVolun, Acao * acao);
Acao * getAcao(Voluntario * endVolun);



#endif