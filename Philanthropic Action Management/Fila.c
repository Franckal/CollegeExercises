/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#include "Fila.h"

Fila * criaFila()
{
	Fila * novaFila = malloc(sizeof(Fila));
	return iniciaFila(novaFila);
}

Fila * iniciaFila(Fila * endFila)
{
	endFila->tamanho = 0;
	endFila->inicio = NULL;
	endFila->final = NULL;
	return endFila;
}

bool insereNaFila(Fila * endFila, void * item)
{
	EndNoFi elemento = malloc(sizeof(NoFi));
	if(elemento==NULL)
		return false;
	elemento->item = item;
	elemento->proximo = NULL;
	if(endFila->inicio==NULL)
		endFila->inicio = elemento;
	else
		endFila->final->proximo = elemento;
	endFila->final = elemento;
	endFila->tamanho ++;
	return true;
}

void * removeDaFila(Fila * endFila)
{
	if(filaVazia(*endFila))
		return NULL;
	else
	{
		EndNoFi elemento = endFila->inicio;
		endFila->inicio = elemento->proximo;
		if(endFila->inicio == NULL)
			endFila->final = NULL;
		void * item = elemento->item;
		free(elemento);
		endFila->tamanho--;
		return item;
	}
}

void apagaFila(Fila * endFila)
{
	void * aux;
	while((aux=removeDaFila(endFila))!=NULL)
		free(aux);
}

void * itemInicioFila(Fila fila)
{
	return fila.inicio->item;
}

unsigned int tamanhoFila(Fila fila)
{
	return fila.tamanho;
}

bool filaVazia(Fila fila)
{
	if(fila.inicio == NULL)
		return true;
	return false;
}