/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char Byte;
typedef unsigned int Size;

typedef struct reg
{
	Size tamChave;
	void * chave;
	void * dados;
}Registro;

typedef struct abf
{
	Registro registro;
	struct abf * esquerda;
	struct abf * direita;
}Noh;
typedef Noh * EndNoh;

typedef struct ab
{
	EndNoh raiz;
	EndNoh * atual;
}ArvoreBinaria;

Registro * criaRegistro(void * dados, void * chave, Size tamChave);
void deletaRegistro(Registro * registro);
Registro * iniciaRegistro(Registro * destino, void * dados, void * chave, Size tamChave);
void * getDadosRegistro(Registro registro);

ArvoreBinaria * criaArvore();
void deletaArvore(ArvoreBinaria * arvore);
ArvoreBinaria * iniciaArvore(ArvoreBinaria * arvore);
ArvoreBinaria * resetaArvore(ArvoreBinaria * arvore);

EndNoh * getRaiz(ArvoreBinaria * arvore);
EndNoh * getFilhoDireita(EndNoh nohPai);
EndNoh * getFilhoEsquerda(EndNoh nohPai);
void setAtual(ArvoreBinaria * arvore, EndNoh * noh);
EndNoh * getAtual(ArvoreBinaria arvore);
Registro * getRegistroNoh(EndNoh noh);
Registro * getRegistroAtual(ArvoreBinaria arvore);


bool insereArvore(ArvoreBinaria * arvore, Registro origem);
bool pesquisaArvore(ArvoreBinaria * arvore, char * chave, Size tamChave);
void * removeAtualArvore(ArvoreBinaria * arvore);

#endif
