/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#include <stdlib.h>

//Definindo o Tipo Nó
typedef struct no
{
    void * item;
    struct no * proximo;
}No;
typedef No * EndNo;

//Definindo o tipo Lista
typedef struct lista
{
    unsigned int tamanho;
    EndNo inicio;
    EndNo * atual;
}Lista;

//Funções de alocações
Lista * criaLista();
void iniciaLista(Lista * endLista);

//Funções de manipulação
bool insereNaLista(Lista * endLista, void * item);
void * removeDaLista(Lista * endLista);
void resetaAtual(Lista * endLista);
bool proximoLista(Lista * endLista);
void * atualLista(Lista lista);
bool listaVazia(Lista lista);
unsigned int tamanhoLista(Lista lista);

//Desalocação
void apagaLista(Lista * endLista);

#endif