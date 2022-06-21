/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef ARQUIVOONG_H
#define ARQUIVOONG_H
#include "GerenciaOng.h"
#include "Fila.h"
#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct vform
{
	char matricula[6];
	char nomeVolun[50];
	char contato[50];
	char codAcao[6];
}VolunFormatado;

typedef struct aform
{
	char codAcao[6];
	char tituloAcao[50];
	char descricao[100];
}AcaoFormatada;

//Funções de formatação
VolunFormatado formataVoluntario(Voluntario * voluntario);
AcaoFormatada formataAcao(Acao * acao);

GerenciaOng * carregaArquivo(char nomeArqvAcoes[], char nomeArqvVolun[]);
bool gravaArquivo(char nomeArqvAcoes[], char nomeArqvVolun[], GerenciaOng ong);

#endif