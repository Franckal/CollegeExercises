#include "InterfaceAbrigo.h"
/* Programa Feito Por: Franck Allyson da Silva Rocha */


void clear()
{
    while(getchar()!='\n');
}

void entraAbrigo(Abrigo * endAbrigo)
{
    char entrada[100];
    int numAnimais;
    
    printf("Nome: ");
    scanf("%99[^\n]", entrada);
    setNomeAbrigo(endAbrigo, entrada);
    clear();

    printf("Responsável: ");
    scanf("%99[^\n]", entrada);
    setResponsavelAbrigo(endAbrigo, entrada);
    clear();
    
    printf("Endereço: ");
    scanf("%99[^\n]", entrada);
    setEnderecoAbrigo(endAbrigo, entrada);
    
    /*Inicializando a variável numAnimais com 0, para adicionar depois*/
    setNumAnimais(endAbrigo, 0);
    
}

void entraAnimais(Animal * endAnimal)
{
    char entrada[200];
    int i, idade;
    
    printf("Nome: ");
    scanf("%99[^\n]", entrada);
    setNome(endAnimal, entrada);
    
    clear();
    
    printf("Especie: ");
    scanf("%99[^\n]", entrada);
    setEspecie(endAnimal, entrada);
    
    clear();
    
    printf("Idade: ");
    scanf("%d", &idade);
    setIdade(endAnimal, idade);
    clear();
    
    printf("Obsevacoes: ");
    scanf("%99[^\n]", entrada);
    setObservacoes(endAnimal, entrada);
    
    clear();
}

void exibeAbrigo(Abrigo * endAbrigo)
{
    printf("---------------------------------------\n");
    printf("                 ABRIGO                \n");
    printf("Codigo = %d\n", getCodigo(*endAbrigo));
    printf("Nome = %s\n", getNomeAbrigo(endAbrigo));
    printf("Responsavel = %s\n", getResponsavelAbrigo(endAbrigo));
    printf("Endereco = %s\n", getEnderecoAbrigo(endAbrigo));
    printf("Número de Animais = %d\n", getNumAnimais(*endAbrigo));
    clear();
}

void exibeAnimal(Animal * endAnimal)
{
    printf("Nome = %s\n", getNome(endAnimal));
    printf("Espécie = %s\n", getEspecie(endAnimal));
    printf("Idade = %d\n", getIdade(*endAnimal));
    printf("Observacoes = %s\n", getObservacoes(endAnimal));
    
}