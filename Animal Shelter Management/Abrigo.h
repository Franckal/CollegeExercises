#ifndef ABRIGO_H
#define ABRIGO_H
#include "Animal.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* Programa Feito Por: Franck Allyson da Silva Rocha  */


typedef struct abg{
    int codigo; /* Código que vai ser gerado automaticamente*/
    char nome[50];
    char responsavel[50];
    char endereco[300];
    int numAnimais;
    Animal * listaAnimal;
}Abrigo;

/* Alocação Dinamica do Abrigo */
Abrigo * _criaAbrigo();
Abrigo * criaAbrigo(char nome[50], char responsavel[50], char endereco[50], 
                    int numAnimais, Animal * listaAnimal);

/* Funções de Manipulação */

void setCodigo(Abrigo * endAbrigo, int codigo);
int getCodigo(Abrigo abrigo);

void setNomeAbrigo(Abrigo * endAbrigo, char nome[50]);
char * getNomeAbrigo(Abrigo * endAbrigo);

void setResponsavelAbrigo(Abrigo * endAbrigo, char responsavel[50]);
char * getResponsavelAbrigo(Abrigo * endAbrigo);

void setEnderecoAbrigo(Abrigo * endAbrigo, char endereco[300]);
char * getEnderecoAbrigo(Abrigo * endAbrigo);

void setNumAnimais(Abrigo * endAbrigo, int numAnimais);
int getNumAnimais(Abrigo abrigo);

void setListaAnimal(Abrigo * endAbrigo, Animal * listaAnimal);
Animal * getListaAnimal(Abrigo * endAbrigo);

/**************************************/
/* Função para inserir um novo animal */
void inserirAnimal(Abrigo * endAbrigo, Animal * novoAnimal);

/* Desalocar Abrigo */
void destroiAbrigo(Abrigo * endAbrigo);

#endif