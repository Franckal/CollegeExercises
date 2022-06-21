#include "Abrigo.h"
#include "Animal.h"
/* Programa Feito Por: Franck Allyson da Silva Rocha  */
    
    

/* Alocação Dinamica do Abrigo */
Abrigo * _criaAbrigo()
{
    return malloc(sizeof(Abrigo));
}

Abrigo * criaAbrigo(char nome[50], char responsavel[50], char endereco[50], 
                    int numAnimais, Animal * listaAnimal)
{
    Abrigo * novoAbrigo = _criaAbrigo();
    setNomeAbrigo(novoAbrigo, nome);
    setResponsavelAbrigo(novoAbrigo, responsavel);
    setEnderecoAbrigo(novoAbrigo, endereco);
    setNumAnimais(novoAbrigo, numAnimais);
    setListaAnimal(novoAbrigo, listaAnimal);
    return novoAbrigo;
}

/* Funções de Manipulação */
void setCodigo(Abrigo * endAbrigo, int codigo)
{
    endAbrigo -> codigo = codigo;
}

int getCodigo(Abrigo abrigo)
{
    return abrigo.codigo;
}

void setNomeAbrigo(Abrigo * endAbrigo, char nome[50])
{
    strcpy(endAbrigo -> nome, nome);
}

char * getNomeAbrigo(Abrigo * endAbrigo)
{
    return endAbrigo -> nome;
}

void setResponsavelAbrigo(Abrigo * endAbrigo, char responsavel[50])
{
    strcpy(endAbrigo -> responsavel, responsavel);
}

char * getResponsavelAbrigo(Abrigo * endAbrigo)
{
    return endAbrigo -> responsavel;
}

void setEnderecoAbrigo(Abrigo * endAbrigo, char endereco[300])
{
    strcpy(endAbrigo -> endereco, endereco);
}

char * getEnderecoAbrigo(Abrigo * endAbrigo)
{
    return endAbrigo -> endereco;
}

void setNumAnimais(Abrigo * endAbrigo, int numAnimais)
{
    endAbrigo -> numAnimais = numAnimais;
}

int getNumAnimais(Abrigo abrigo)
{
    return abrigo.numAnimais;
}

void setListaAnimal(Abrigo * endAbrigo, Animal * listaAnimal)
{
    endAbrigo -> listaAnimal = listaAnimal;
}

Animal * getListaAnimal(Abrigo * endAbrigo)
{
    return endAbrigo -> listaAnimal;
}

/**************************************/
/* Função para inserir um novo animal */
void inserirAnimal(Abrigo * endAbrigo, Animal * novoAnimal)
{
    /* Atualizo meu Número de Animais*/
    /* Realoco a memória de lista animal com base no meu número atualizado*/
    /* Recebo o novo Animal na memória realocada.*/
    endAbrigo -> numAnimais += 1;
    endAbrigo -> listaAnimal = realloc(endAbrigo->listaAnimal, endAbrigo->numAnimais * sizeof(Animal));
    endAbrigo -> listaAnimal[(endAbrigo->numAnimais)-1] = *novoAnimal;
    
}

/* Desalocar Abrigo */
void destroiAbrigo(Abrigo * endAbrigo)
{
    free(endAbrigo);
    endAbrigo = NULL;
}