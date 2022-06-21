/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef FILA_H
#define FILA_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct nofi
{
	void * item;
	struct nofi * proximo;
}NoFi;
typedef NoFi * EndNoFi;

typedef struct fila
{
	EndNoFi inicio;
	EndNoFi final;
	unsigned int tamanho;
}Fila;

Fila * criaFila();
Fila * iniciaFila(Fila * endFila);
bool insereNaFila(Fila * endFila, void * item);
void * removeDaFila(Fila * endFila);
void apagaFila(Fila * endFila);
void * itemInicioFila(Fila fila);
unsigned int tamanhoFila(Fila fila);
bool filaVazia(Fila fila);

#endif