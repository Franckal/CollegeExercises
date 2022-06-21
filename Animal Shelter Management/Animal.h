#ifndef ANIMAL_H
#define ANIMAL_H
/* Programa Feito Por: Franck Allyson da Silva Rocha  */
typedef struct anml
{
    char nome[50];
    char especie[100];
    int idade;
    char observacoes[300];
}Animal;

/* Funções de Alocação dinâmica */
Animal * _criaAnimal();
Animal * criaAnimal(char nome[50], char especie[100], 
                    int idade, char observacoes[300] );

/* Funções de Manipulação */


void setNome(Animal * endAnimal, char nome[50]);
char * getNome(Animal * endAnimal);

void setEspecie(Animal * endAnimal, char especie[100]);
char * getEspecie(Animal * endAnimal);

void setIdade(Animal * endAnimal, int idade);
int getIdade(Animal animal);

void setObservacoes(Animal * endAnimal, char observacoes[300]);
char * getObservacoes(Animal * endAnimal);

/* Função de Desalocação */
void destroiAnimal(Animal * endAnimal);

#endif