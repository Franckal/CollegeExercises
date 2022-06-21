/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#include "Acao.h"

//Funções de alocação
Acao * _criaAcao()
{
	Acao * novaAcao = malloc(sizeof(Acao));
	novaAcao->voluntarios = criaLista();
	return novaAcao;
}

Acao * criaAcao(char codAcao[6], char tituloAcao[50], char descricao[100], Lista * voluntarios)
{
	Acao * novaAcao = _criaAcao();
	setCodAcao(novaAcao, codAcao);
	setTituloAcao(novaAcao, tituloAcao);
	setDescricao(novaAcao, descricao);
	setVoluntarios(novaAcao, voluntarios);

	return novaAcao;
}

//Funções para manipulação
void setCodAcao(Acao * endAcao, char codAcao[6])
{
	strcpy(endAcao -> codAcao, codAcao);
}

char * getCodAcao(Acao * endAcao)
{
	return endAcao -> codAcao;
}

void setTituloAcao(Acao * endAcao, char tituloAcao[50])
{
	strcpy(endAcao -> tituloAcao, tituloAcao);
}

char * getTituloAcao(Acao * endAcao)
{
	return endAcao -> tituloAcao;
}

void setDescricao(Acao * endAcao, char descricao[100])
{
	strcpy(endAcao -> descricao, descricao);
}

char * getDescricao(Acao * endAcao)
{
	return endAcao -> descricao;
}

void setVoluntarios(Acao * endAcao, Lista * voluntarios)
{
	endAcao -> voluntarios = voluntarios;
}

Lista * getVoluntarios(Acao * endAcao)
{
	return endAcao -> voluntarios;
}

//Funções para desalocar
void deletarAcao(Acao * acao)
{
	free(acao);
	acao = NULL;
}