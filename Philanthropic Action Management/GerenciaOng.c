/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/

#include "GerenciaOng.h"
#include <stdio.h>
//Incialização das Variáveis Voluntario e Acao:
GerenciaOng * iniciaOng(GerenciaOng * ong)
{
	ong->voluntarios = criaArvore();
	ong->acoes = criaArvore();
	return ong;
}

//Acalocação dinâmica
GerenciaOng * criaOngVazia()
{
	return iniciaOng(malloc(sizeof(GerenciaOng)));
}

GerenciaOng * criaOng(ArvoreBinaria * voluntarios, ArvoreBinaria * acoes)
{
	GerenciaOng * novaOng = criaOngVazia();
	if(novaOng == NULL)
		return NULL;
	if(iniciaOng(novaOng) == NULL)
	{
		free(novaOng);
		novaOng = NULL;
	}	
	else
	{
		novaOng->acoes = acoes;
		novaOng->voluntarios = voluntarios;
	}
	return novaOng;
}

//Manipulação dos campos
void setVoluntariosOng(GerenciaOng * ong, ArvoreBinaria * voluntarios)
{
	ong->voluntarios = voluntarios;
}

ArvoreBinaria * getVoluntariosOng(GerenciaOng * ong)
{
	return ong->voluntarios;
}

void setAcoesOng(GerenciaOng * ong, ArvoreBinaria * acoes)
{
	ong->acoes = acoes;
}

ArvoreBinaria * getAcoesOng(GerenciaOng * ong)
{
	return ong->acoes;
}

//Funções de busca

Acao * pesquisaAcaoByCodigo(GerenciaOng * ong, char * chave, Size tamChave)
{

	ArvoreBinaria * acoes = getAcoesOng(ong);
	if(pesquisaArvore(acoes, chave, tamChave))
		return getDadosRegistro(*getRegistroAtual(*acoes));
	else
		return NULL;
}

Acao * pesquisaAcaoByTitulo(GerenciaOng * ong, char tituloAcao[50])
{
	Fila fila;
    EndNoh item;
	ArvoreBinaria * avAcoes = getAcoesOng(ong);
	Acao * acoes = NULL;
	
    iniciaFila(&fila);
    insereNaFila(&fila, *getRaiz(avAcoes));
    
    while(!filaVazia(fila))
    {
		
        item = removeDaFila(&fila);
		if(item==NULL)
		{
			return NULL;
		}
			
		
		acoes = getDadosRegistro(*getRegistroNoh(item));
		if(strcmp(getTituloAcao(acoes), tituloAcao) == 0)
		{
			apagaFila(&fila);
			return acoes;
		}
        if(*getFilhoEsquerda(item)!=NULL)
            insereNaFila(&fila, *getFilhoEsquerda(item));
        if(*getFilhoDireita(item)!=NULL)
            insereNaFila(&fila, *getFilhoDireita(item));
    }
	apagaFila(&fila);
	return NULL;
}

Voluntario * pesquisaVolunByMatricula(GerenciaOng * ong, char * chave, Size tamChave)
{
	ArvoreBinaria * voluntarios = getVoluntariosOng(ong);

	if(pesquisaArvore(voluntarios, chave, tamChave))
		return getDadosRegistro(*getRegistroAtual(*voluntarios));
	else
		return NULL;
} 

Voluntario * pesquisaVolunByNome(GerenciaOng * ong, char nomeVolun[50])
{
	Fila fila;
    EndNoh item;
	ArvoreBinaria * avVolun = getVoluntariosOng(ong);
	Voluntario * volun = NULL;
	
    iniciaFila(&fila);
    insereNaFila(&fila, *getRaiz(avVolun));
    
    while(!filaVazia(fila))
    {
        item = removeDaFila(&fila);
		if(item == NULL)
			return NULL;
		volun = getDadosRegistro(*getRegistroNoh(item));
		if(strcmp(getNomeVolun(volun), nomeVolun) == 0)
		{
			apagaFila(&fila);
			return volun;
		}
        if(*getFilhoEsquerda(item)!=NULL)
            insereNaFila(&fila, *getFilhoEsquerda(item));
        if(*getFilhoDireita(item)!=NULL)
            insereNaFila(&fila, *getFilhoDireita(item));
    }
	apagaFila(&fila);
	return NULL;
}

//Funcao de desalocar
void deletaOng(GerenciaOng * ong)
{
	if(*getRaiz(getAcoesOng(ong)) != NULL)
	{
		deletaArvore(getAcoesOng(ong));
		deletaArvore(getVoluntariosOng(ong));
	}  
	free(ong);	
}

