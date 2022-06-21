/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef GERENCIAONG_H
#define GERENCIAONG_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArvoreBinaria.h"
#include "Voluntario.h"
#include "Acao.h"
#include "Fila.h"

typedef struct grnong
{
	ArvoreBinaria * voluntarios;
	ArvoreBinaria * acoes;
}GerenciaOng;

//Incialização das Variáveis Voluntario e Acao:
GerenciaOng * iniciaOng(GerenciaOng * ong);

//Acalocação dinâmica
GerenciaOng * criaOngVazia();
GerenciaOng * criaOng(ArvoreBinaria * voluntarios, ArvoreBinaria * acoes);

//Manipulação dos campos
void setVoluntariosOng(GerenciaOng * ong, ArvoreBinaria * voluntarios);
ArvoreBinaria * getVoluntariosOng(GerenciaOng * ong);

void setAcoesOng(GerenciaOng * ong, ArvoreBinaria * acoes);
ArvoreBinaria * getAcoesOng(GerenciaOng * ong);

//Funções de busca
Acao * pesquisaAcaoByCodigo(GerenciaOng * ong, char * chave, Size tamChave);
Acao * pesquisaAcaoByTitulo(GerenciaOng * ong, char tituloAcao[50]);
Voluntario * pesquisaVolunByMatricula(GerenciaOng * ong, char * chave, Size tamChave);
Voluntario * pesquisaVolunByNome(GerenciaOng * ong, char nomeVolun[50]);

//Função de desalocar
void deletaOng(GerenciaOng * ong);

#endif