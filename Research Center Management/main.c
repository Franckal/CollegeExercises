/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#include <stdio.h>
#include <stdbool.h>
#include "ArquivoCentro.h"
#include "Centro.h"
#include "InterfaceCentro.h"
#define NOMEARQV "ArquivoAbrigo.bsi"

int main(void) 
{
	bool dadosAtualizados = true;
  	Centro * centro = carregaDados(NOMEARQV);

	if(centro==NULL)
	{
		printf("\nNão há dados gravados no arquivo!\n");
		
		printf("\n-----------------   CRIANDO CENTRO  -----------------\n");
		
		int numDepartamentos, i, i2;
		char aux[100];
		
		printf("Digite o numero de Departamentos: ");
		scanf("%d", &numDepartamentos);
		clear();
			
		centro = criaCentro(numDepartamentos);
		printf("\n-----------------------------------------------------\n");
		printf("               NOMES DOS DEPARTAMENTOS        \n");
		printf("-----------------------------------------------------\n");
		for(i=0; i<numDepartamentos; i++)
		{
			printf("Nome do Departamento %d: ", i+1);
			scanf("%s", aux);
			setNomesDepartamentos(centro, aux, i);
		}
		printf("\nCentro criado com sucesso!\n");
		dadosAtualizados = false;
	}

	int escolha;
	do
	{
		escolha = menuPrincipal();
		switch(escolha)
		{
			case 1://Insere Pesqusador
			{
				Pesquisador * novoPesquisador = criaPesquisadorVazio();
				if(entraPesquisador(centro, novoPesquisador))
				{
					if(inserePesquisador(centro, novoPesquisador))
					{
						printf("\nPesquisador Inserido com Sucesso!\n");
						dadosAtualizados = false;
					}			
					else
						printf("\nErro ao inserir pesquisador!\n");	
				}
				
				break;
			}
			case 2://Mostra Departamentos
			{
				interfaceMostraDepartamentos(centro);
				break;
			}
			case 3://Mostra pesquisadores
			{
				clear();
				int codDepartamento = -1, i;
				char opt;
				printf("Selecionar Departamento por:\n[C]ódigo  |  [N]ome\n->");
				opt = getchar();
				
				if(opt == 'C' || opt == 'c')
				{
					printf("\nDigite o código do Departamento:");
					scanf("%d", &codDepartamento);
					if(codDepartamento < 0 || codDepartamento >= getNumDepartamentos(*centro))
					{
						printf("\nNão existe departamento com o código dado!\n");
						codDepartamento = -1;
					}	
				}
				
				if(opt == 'N' || opt == 'n')
				{
					char nome[50];
					printf("Digite o nome do departamento: ");
					scanf("%s", nome);
					for(i=0; i<getNumDepartamentos(*centro); i++)
					{
						if(strcmp(getNomesDepartamentos(centro, i), nome) == 0)
						{
							codDepartamento = i;
							break;
						} 	
					}
					if(codDepartamento == -1)
						printf("\nNão existe departamento com o nome dado!\n");
				}
				
				if(codDepartamento != -1)
				{
					printf("\n_____________________________________________________\n");
					printf("\n # PESQUISADORES DO DEPARTAMENTO [ %s ]\n\n", getNomesDepartamentos(centro, codDepartamento));
					interfaceMostraPesquisadores(centro, codDepartamento);
				}
				
				
				break;
			}
			case 4:// Busca Pesquisador
			{
				int matricula;
				printf("Digite a matricula do Pesquisador: ");
				scanf("%d", &matricula);
				clear();
				Pesquisador * pesqAux = buscaPesquisador(centro, matricula);
				if(pesqAux != NULL)
				{
					char opt;
					exibePesquisador(pesqAux);
					printf("\nOpções:\n[M]enu Principal\n[R]emover Pesquisador\n->");
					opt = getchar();
					if(opt == 'R' || opt == 'r')
					{
						if(removePesquisador(centro, getMatricula(pesqAux))!=NULL)
						{
							dadosAtualizados = false;
							printf("Pesquisador Removido com sucesso!\n");
						}	
						else
							printf("Erro ao remover Pesquisador!\n");
					}
				}
				else
					printf("Pesquisador não existe ou não foi encontrado!\n");
				break;
			}
			case 5://Grava Dados
			{
				int aux = gravaDados(centro, NOMEARQV);
				if(aux==1)
				{
					printf("Dados Gravados com Sucesso!");
					dadosAtualizados = true;
				}
				else if(aux == -1)
					printf("Houve algum problema ao tentar abrir o arquivo!");
				else if(aux == -2)
					printf("Erro ao gravar o número de Departamentos!");
				else if(aux == -3)
					printf("Erro ao gravar o nome dos Departamentos!");
				else
					printf("Erro ao gravar os Pesquisadores!");
				break;
			}
			case 6://Sair
			{
				clear();
				if(!dadosAtualizados)
				{
					char op;
					printf("\nExistem informações que foram atualizadas!\n");
					printf("Deseja salva-las no arquivo?\n");
					printf("[S]im     |     [N]ao\n->");
					
					op = getchar();
					if(op=='S' || op == 's')
					{
						if(gravaDados(centro, NOMEARQV) == 1)
							printf("\nDados atualizados com sucesso!!\n");
						else
							printf("\nOs dados não foram atualizados!!\n");
					}
						
				}
				desalocarCentro(centro);
			}
		}
	}while(escolha!=6);
	printf("\nPrograma Encerrado!!\n");
} 