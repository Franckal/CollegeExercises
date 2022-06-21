/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#include "Lista.h"

//Funções de alocações
Lista * criaLista()
{
    Lista * novaLista = malloc(sizeof(Lista));
    iniciaLista(novaLista);
	return novaLista;
}


void iniciaLista(Lista * endLista)
{
    endLista->tamanho = 0;
    endLista->inicio = NULL;
    endLista->atual = &(endLista->inicio);
}

//Funções de manipulação
bool insereNaLista(Lista * endLista, void * item)
{
    EndNo elemento = malloc(sizeof(No));
    if(elemento == NULL)
        return false;
    elemento->item = item;
    elemento->proximo = *(endLista->atual);
    *(endLista->atual) = elemento;
    endLista->tamanho++;
    return true;
}

void * removeDaLista(Lista * endLista)
{
    if(listaVazia(*endLista))
        return NULL;
    else
    {
        EndNo elemento = *(endLista->atual);
        if(elemento == NULL)
            return NULL;
        void * item = elemento->item;
        *(endLista->atual) = elemento->proximo;
        free(elemento);
        endLista->tamanho--;
        return item;
    }
}

void resetaAtual(Lista * endLista)
{
    endLista->atual = &(endLista->inicio);
}

bool proximoLista(Lista * endLista)
{
    if((*(endLista->atual))!=NULL)
    {
        endLista->atual = &((*(endLista->atual))->proximo);
        return true;    
    }
    return false;
    
}
void * atualLista(Lista lista)
{
    if((*(lista.atual))!=NULL)
        return (*(lista.atual))->item;
    return NULL;
}

bool listaVazia(Lista lista)
{
    if(lista.inicio == NULL)
        return true;
    return false;
}

unsigned int tamanhoLista(Lista lista)
{
    return lista.tamanho;
}
		
void apagaLista(Lista * endLista)
{
    void * aux;
    resetaAtual(endLista);
    while((aux = removeDaLista(endLista))!=NULL)
        free(aux);
}
