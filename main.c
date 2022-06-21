#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "Abrigo.h"
#include "ArquivoAbrigo.h"
#include "InterfaceAbrigo.h"
#define NOME_ARQAB "Abg.bsi"
#define NOME_ARQAN "AnAbrigo"
/* Programa Feito Por: Franck Allyson da Silva Rocha 
Arquivo tipo Binário. */

int main()
{
    int op;
    do
    {
        
        printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
        printf("|             EXERCÍCIO 1             |\n");
        printf("|_____________________________________|\n");
        printf("\n[ 1 ] Inserir Abrigo\n[ 2 ] Pesquisar Abrigo\n[ 3 ] Sair\n"
                "Opção: ");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1://Inserir Abrigo
            {
                int i, numAbrigos;
                char op1;
                while(1)
                {    
                    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("Digite o número de Abrigos: ");
                    scanf("%d", &numAbrigos);
                    clear();
                    
                    
                    if(numAbrigos<1)
                        printf("Gravar um ou mais Abrigos!\n");
                    else
                        break;
                }    
                
                Abrigo abrigos[numAbrigos];
                for(i=0; i<numAbrigos; i++)
                {
                    
                    printf("\n=======================================\n");
                    printf("|           Abrigo %d                  |\n", i+1);
                    entraAbrigo(&abrigos[i]);
                    clear();
                    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    
                    long int abGravados = escreveAbrigo(NOME_ARQAB, &abrigos[i], 1);
                    if(abGravados==0)
                        printf("\nErro ao gravar o Abrigo!!\n");
                    else
                    {
                        printf("\nAbrigo gravado com sucesso!\n");
                        do
                        {
                            printf("\nDeseja cadastrar animais neste abrigo?\n"
                                "[ 1 ] Sim | [ 2 ] Não\n"
                                "Opção: ");
                            op1 = getchar();
                            if(op1!='1'&&op1!='2')
                                printf("\nDigite apenas [1] ou [2]!\n");
                            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        }while(op1!='1'&&op1 !='2');    
                        if(op1=='1')
                        {
                            int numAnimais = 0;
                            char nomeArquivoAnimal[30];
                            int i2;
                            
                            printf("Digite o número de animais: ");
                            scanf("%d", &numAnimais);
                            clear();
                            setNumAnimais(&abrigos[i], numAnimais);
                                
                            printf("=======================================\n");
                            
                            Animal * animais = NULL;
                            animais = calloc(numAnimais, sizeof(Animal));
                            //Optei por usar o Calloc aqui pois estou criando uma Lista de animais
                            //Poderia ter criado uma função de alocação de uma lista dentro do meu TAD Animal.
                            //Porém não quis criar muitas funções além das pedidas no enunciado do exercício. 
                            for(i2=0; i2<numAnimais;i2++)
                            {
                               
                                printf("·······································\n");
                                printf("           %dº Animal         \n", i2+1);
                                entraAnimais(&animais[i2]);
                                
                            }
                            printf("·······································\n");
                            printf("=======================================\n");
                            long int anGravados = escreveAnimal(NOME_ARQAN, NOME_ARQAB, animais, abrigos[i].codigo, numAnimais);
                            
                            if(anGravados==0)
                                printf("\nErro ao gravar!\n");
                            else if(anGravados < numAnimais)
                                printf("\nForam Gravados %ld de %d animais!\n", anGravados, numAnimais);
                            else
                                printf("\nAnimais gravados com Sucesso!\n");
                                
                            printf("=======================================\n");
                        }
                        else if(op1=='2')
                            clear();
                    }
                }
                break;
            }
            case 2://Pesquisa Abrigo
            {
                clear();
                int i, numAnimais, c=0;
                Abrigo * abrigo = NULL;/*Criando o Abrigo que vai ser Manipulado*/
                Animal * animal = NULL;/*Criando a Lista de animais que vai ser Manipulada*/
                char op2, nomeAbrigo[50];
                
                printf("---------------------------------------\n");
                printf("Digite o nome do Abrigo: ");
                scanf("%50[^\n]", nomeAbrigo);
                abrigo = pesquisaAbrigo(nomeAbrigo, NOME_ARQAB, NOME_ARQAN);
                if(abrigo==NULL)
                {
                    printf("O nome do abrigo não foi encontrado!\n");
                    clear();    
                    break;
                }
                
                exibeAbrigo(abrigo);
                
                do
                {
                    numAnimais = getNumAnimais(*abrigo);/*Pegando Número de Animais Atualizado*/
                    animal = getListaAnimal(abrigo);
                               
                    printf("\n|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
                    printf("          MENU (%s)           \n", getNomeAbrigo(abrigo));
                    printf(" ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ \n");
                    printf("\n[ 1 ] Listar animais\n[ 2 ] Inserir novo animal\n"
                        "[ 3 ] Menu principal\nOpção: ");
                    op2 = getchar();
                    
                    switch(op2)
                    {
                        case '1'://Listar Animais
                        {
                            if(numAnimais!=0)
                            {
                                for(i=0;i<numAnimais;i++)
                                {
                                    printf("·······································\n");
                                    printf("                Animal %d        \n", i+1);
                                    exibeAnimal(&animal[i]);
                                    printf("·······································\n");
                                }
                            }
                            else
                                printf("\nNão há Animais neste abrigo!\n");
                                clear();
                            
                            break;
                        }
                        case '2'://Inserir novoAnimal
                        {
                            
                            clear();
                            Animal novoAnimal;
                            
                            printf("·······································\n");
                            printf("              Novo Animal         \n");
                            entraAnimais(&novoAnimal);
                            printf("·······································\n");
                            
                            /* 
                                Optei por utilizar a função inserir animal, pois assim poderei
                                    maniular meu ponteiro de animais mais facilmente. 
                                Isso trata erros a respeito do usuário não voltar para o menu
                                    principal, pois assim, eu não atualizaria o abrigo(função pesquisaAbrigo está fora deste escopo), 
                                    e permaneceria com as informações desatualizadas. 
                                    Então armazeno os dados na variável e manipulo 
                                    neste escopo.
                            */
                            inserirAnimal(abrigo, &novoAnimal);
                            printf("=======================================\n");
                            
                            long int anNovoGravado = escreveAnimal(NOME_ARQAN, NOME_ARQAB,&novoAnimal, abrigo->codigo, 1);
                            /*
                            Coloquei Parametro numAnimais como 1, pois optei por adicionar um animal de cada vez:
                            No enunciado do exercício no classroom dizia: ou inserir UM novo animal, interpretei dessa forma.
                            Porém a função é totalmente funcional com qualquer número de animais caso o main seja
                            implementado dessa forma.(linha 90).
                            */
                            
                            if(anNovoGravado==0)
                                printf("\nErro ao gravar Animal!\n");
                            else
                                printf("\nAnimal gravado com Sucesso!\n");
                                
                            printf("=======================================\n");
                        }
                    }
                }while(op2!='3');
                if(abrigo!=NULL)
                    destroiAbrigo(abrigo);
                if(animal!=NULL)
                    destroiAnimal(animal);
                
            }
        }
    }while(op!=3);
           
}