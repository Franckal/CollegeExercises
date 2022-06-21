#include "Animal.h"
#include <string.h>
#include <stdlib.h>
/* Programa Feito Por: Franck Allyson da Silva Rocha  */
    
    
/********************************/
/* Funções de Alocação dinâmica */

Animal * _criaAnimal()
{
    return malloc(sizeof(Animal));
}

Animal * criaAnimal(char nome[50], char especie[100], 
                    int idade, char observacoes[300])
{
    /* Criando variável do tipo Animal e alocando a memória */
    Animal * newAnimal = _criaAnimal();
    
    /* Preenchendo a variável */
    setNome(newAnimal, nome);
    setEspecie(newAnimal, especie);
    setIdade(newAnimal, idade);
    setObservacoes(newAnimal, observacoes);
    
    return newAnimal;
}

/********************************/
/*    Funções de Manipulação    */

void setNome(Animal * endAnimal, char nome[50])
{
    strcpy(endAnimal -> nome, nome);
}

char * getNome(Animal * endAnimal)
{
    return endAnimal -> nome;
}

void setEspecie(Animal * endAnimal, char especie[100])
{
    strcpy(endAnimal -> especie, especie);
}

char * getEspecie(Animal * endAnimal)
{
    return endAnimal -> especie;
}

void setIdade(Animal * endAnimal, int idade)
{
    endAnimal -> idade = idade;
}

int getIdade(Animal animal)
{
    return animal.idade;
}

void setObservacoes(Animal * endAnimal, char observacoes[300])
{
    strcpy(endAnimal -> observacoes, observacoes);
}

char * getObservacoes(Animal * endAnimal)
{
    return endAnimal -> observacoes;
}

/*************************/
/* Função de Desalocação */
void destroiAnimal(Animal * endAnimal)
{
    free(endAnimal);
    endAnimal = NULL;
}
