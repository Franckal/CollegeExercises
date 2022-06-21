/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/

#include "ArvoreBinaria.h"
#include <stdio.h>
//Funções Registro
Registro * criaRegistro(void * dados, void * chave, Size tamChave)
{
	Registro * novoRegistro = malloc(sizeof(Registro));
	if(novoRegistro == NULL)
		return NULL;
	return iniciaRegistro(novoRegistro, dados, chave, tamChave);
}

void deletaRegistro(Registro * registro)
{
	free(registro);	
}

Registro * iniciaRegistro(Registro * destino, void * dados, void * chave, Size tamChave)
{
	destino->chave = chave;
	destino->tamChave = tamChave;
	destino->dados = dados;
	return destino;
}

void * getDadosRegistro(Registro registro)
{
	return registro.dados;
}

//Funções Árvore Binária
ArvoreBinaria * criaArvore()
{
	return iniciaArvore(malloc(sizeof(ArvoreBinaria)));	
}

void deletaArvoreNoh(EndNoh noh)
{
	
	if(noh->esquerda == NULL && noh->direita == NULL)
	{
		
		free(noh->registro.dados);
		free(noh);
	}
	else if(noh->esquerda != NULL)
		deletaArvoreNoh(noh->esquerda);
	else
		deletaArvoreNoh(noh->direita);
}

void deletaArvore(ArvoreBinaria * arvore)
{
	deletaArvoreNoh(arvore->raiz);
	free(arvore);
}

ArvoreBinaria * iniciaArvore(ArvoreBinaria * arvore)
{
	arvore->raiz = NULL;
	arvore->atual = &arvore->raiz;
	return arvore;
}

ArvoreBinaria * resetaArvore(ArvoreBinaria * arvore)
{
	deletaArvoreNoh(arvore->raiz);
	return iniciaArvore(arvore);
}

//Funções EndNoh
EndNoh * getRaiz(ArvoreBinaria * arvore)
{
	return &arvore->raiz;
}

EndNoh * getFilhoDireita(EndNoh nohPai)
{
	return &nohPai->direita;
}

EndNoh * getFilhoEsquerda(EndNoh nohPai)
{
	return &nohPai->esquerda;
}

void setAtual(ArvoreBinaria * arvore, EndNoh * noh)
{
	arvore->atual = noh;
}

EndNoh * getAtual(ArvoreBinaria arvore)
{
	return arvore.atual;
}

Registro * getRegistroNoh(EndNoh noh)
{
	return &noh->registro;
}

Registro * getRegistroAtual(ArvoreBinaria arvore)
{
	return &(*(arvore.atual))->registro;
}


short comparaChaves(Registro base, char * cChave, Size tamChave)
{
	Size i;
	Byte * bChave = base.chave;
	for(i=0; i < tamChave && i < base.tamChave; i++)
	{
		if(bChave[i]<cChave[i])
			return 1;
		else if(bChave[i]>cChave[i])
			return -1;
	}
	if(base.tamChave == tamChave)
		return 0;
	else if(base.tamChave<tamChave)
		return 1;
	else	
		return -1;
}

short comparaChavesRegistros(Registro base, Registro comp)
{
	return comparaChaves(base, comp.chave, comp.tamChave);
}

//Funções de manipulação e pesquisa de ArvoreBinaria
bool insereArvore1(EndNoh * endNoh, Registro origem)
{
	if(*endNoh == NULL)
	{
		*endNoh = malloc(sizeof(Noh));
		if(*endNoh == NULL)
			return 0;
		iniciaRegistro(&(*endNoh)->registro, origem.dados, origem.chave, origem.tamChave);
		(*endNoh)->direita = NULL;
		(*endNoh)->esquerda = NULL;
		return 1;		
	}
	if(comparaChavesRegistros((*endNoh)->registro, origem) == 0)
		return 0;
	else if(comparaChavesRegistros((*endNoh)->registro, origem) == 1)
		insereArvore1(&(*endNoh)->direita, origem);
	else
		insereArvore1(&(*endNoh)->esquerda, origem);
}

bool insereArvore(ArvoreBinaria * arvore, Registro origem)
{
	return insereArvore1(&arvore->raiz, origem);
}

bool pesquisaArvore(ArvoreBinaria * arvore, char * chave, Size tamChave)
{
	arvore->atual = &arvore->raiz;
	while(*(arvore->atual) != NULL)
	{
		if(comparaChaves((*(arvore->atual))->registro, chave, tamChave) == 0)
			return 1;
		else if(comparaChaves((*(arvore->atual))->registro, chave, tamChave) == 1)
			arvore->atual = &(*(arvore->atual))->direita;
		else
			arvore->atual = &(*(arvore->atual))->esquerda;
	}
	return 0;
}

void * removeAtualArvore(ArvoreBinaria * arvore)
{
	EndNoh * atual = arvore->atual;
	if(*atual==NULL)
		return NULL;
	void * ponteiro;
	if(((*atual)->esquerda != NULL) && ((*atual)->direita != NULL))
	{
		ponteiro = (*atual)->registro.dados;
		atual = &((*atual)->esquerda);
		while((*atual)->direita != NULL)
			atual = &((*atual)->direita);
		iniciaRegistro(&((*(arvore->atual))->registro), 
						(*atual)->registro.dados, 
						(*atual)->registro.chave,
						(*atual)->registro.tamChave);
		arvore->atual = atual;
		removeAtualArvore(arvore);
	}
	else if((*atual)->esquerda==NULL)
    {
        EndNoh aux = *atual;
        *atual = aux->direita;
        ponteiro = aux->registro.dados;
        free(aux);        
    }
    else
    {
        EndNoh aux = *atual;
        *atual = aux->esquerda;
        ponteiro = aux->registro.dados;
        free(aux);        
    }
	return ponteiro;
}