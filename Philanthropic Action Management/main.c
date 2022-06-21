/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/

#include <stdio.h>
#include <stdbool.h>
#include "GerenciaOng.h"
#include "InterfaceOng.h"
#include "ArquivoOng.h"
#define NOMEARQV_AC "Acoes.bsi"
#define NOMEARQV_VO "Voluntarios.bsi"

int main()
{
	GerenciaOng * ong = carregaArquivo(NOMEARQV_AC, NOMEARQV_VO);
	//Variável que valida se há dados atualizados ou não.
	// True> Dados não estão atualizados | False> Dados estão atualizados.
	bool dadosNaoAtualizados = false;
	int option;
	do
	{
		option = menuPrincipal();
		switch(option)
		{
			case 1://Insere Ação
			{
				Acao * novaAcao = entraAcao(ong);
				// Se ação for válida:
				if(novaAcao!=NULL)
				{
					dadosNaoAtualizados = true;
					Voluntario * novoVolun;
					char op;
					do
					{
						novoVolun = entraVoluntarios(ong, novaAcao);
						if(novoVolun==NULL)
							printf("\nErro ao inserir Voluntario!\n");
						do
						{
							printf("\nDeseja adicionar mais um voluntário?\n");
							printf("[S]im || [N]ão\n");
							printf("-> ");
							op = getchar();
							if(op!='\n')
								getchar();
						}while(op!='S' && op!= 's' && op!= 'N' && op!= 'n');
						
					}while(op!= 'N' && op!= 'n'); 
					while(tamanhoLista(*getVoluntarios(novaAcao))==0)
					{
						int opc;
						do
						{
							printf("\nATENÇÃO");
							printf("\nToda ação precisa de no mínimo um voluntario!\n");
							printf("\nDecida:\n[ 1 ] Adicionar Voluntario\n"
								"[ 2 ] Remover Ação\n=>");
							scanf("%d", &opc);
							if(opc != 1 && opc != 2)
								printf("Opção Inválida!\n\n");
						}while(opc != 1 && opc != 2);
						if(opc==1)
						{
							novoVolun = entraVoluntarios(ong, novaAcao);	
						}
						else if(opc==2)
						{
							if(removeAcao(ong, novaAcao))
							{
								printf("\nAção removida com sucesso!\n");
							}
							else
							{
								printf("\nErro ao remover ação!\n");
							}
						}	
					}
				}
				else
				{
					printf("\nErro ao inserir ação!\n");
					dadosNaoAtualizados = false;
				}
					
				break;	
			}
			case 2://Buscar Ação
			{
				Acao * acaoPesquisada;
				printf("\n--------------------------------------------\n");
				char op;
				do
				{	
					printf("\nDeseja fazer a pesquisa por:\n"
						   "[C]ódigo | [T]ítulo\n -> ");
					op = getchar();
					if(op!='\n')
						getchar();
				}while(op!='C' && op!= 'c' && op!= 'T' && op!= 't');
			
				
				if(op=='C' || op=='c')
				{
					char codAcao[6];
					printf("\nDigite o Código da ação: ");
					scanf("%5s", codAcao);
					acaoPesquisada = pesquisaAcaoByCodigo(ong, codAcao, strlen(codAcao));	
				}
				else if(op=='T' || op=='t')
				{
					char tituloAcao[50];
					printf("\nDigite o Título da ação: ");
					scanf("%49[^\n]", tituloAcao);
					acaoPesquisada = pesquisaAcaoByTitulo(ong, tituloAcao);					
				}
				if(acaoPesquisada!=NULL)
				{
					exibeAcao(*acaoPesquisada);
					int escolha;
					do
					{
						escolha = menuBuscarAcao();
						if(escolha == 1)//Inserir voluntario
						{
							char op;
							do
							{
								Voluntario * novoVolun = entraVoluntarios(ong, acaoPesquisada);
								if(novoVolun==NULL)
								{
									printf("Erro ao inserir voluntario!");
									dadosNaoAtualizados = false;
								}	
								else
								{
									printf("Voluntario Adicionado com Sucesso!");
									dadosNaoAtualizados = true;
								}
								do
								{
									printf("\nDeseja adicionar mais um voluntário?\n");
									printf("[S]im || [N]ão\n");
									printf("-> ");
									op = getchar();
									if(op!='\n')
										getchar();
								}while(op!='S' && op!= 's' && op!= 'N' && op!= 'n');
								
							}while(op!= 'N' && op!= 'n'); 	
						}
						else if(escolha == 2)//Exibir Voluntarios
						{
							exibeTodosVoluntarios(acaoPesquisada);
						}
						else if(escolha == 3)//Remover Acao
						{
							if(removeAcao(ong, acaoPesquisada))
							{
								printf("\nAção removida com sucesso!\n");
                                dadosNaoAtualizados = true;
							}
							else
							{
								printf("\nErro ao remover ação!\n");
								dadosNaoAtualizados = false;
							}
							break;
						}
					}while(escolha!=4);
				}
				else
				{
					printf("\nAção não encontrada!\n");
				}
				break;
			}
			case 3://Buscar Voluntario
			{
				
				Voluntario * volunPesquisado = _criaVoluntario();
				printf("\n--------------------------------------------\n");
				char op;
				do
				{	
					printf("\nDeseja fazer a pesquisa por:\n"
						   "[M]atricula | [N]ome\n -> ");
					op = getchar();
					if(op!='\n')
						getchar();
				}while(op!='M' && op!= 'm' && op!= 'N' && op!= 'n');
				
				if(op=='M' || op=='m')
				{
					char matricula[6];
					printf("\nDigite a Matricula do Voluntario: ");
					scanf("%5s", matricula);
					volunPesquisado = pesquisaVolunByMatricula(ong, matricula, strlen(matricula));	
				}
				else if(op=='N' || op=='n')
				{
					char nomeVolun[50];
					printf("\nDigite o Nome do Voluntário: ");
					scanf("%49[^\n]", nomeVolun);
					volunPesquisado = pesquisaVolunByNome(ong, nomeVolun);					
				}
				
				if(volunPesquisado!=NULL)
				{
					exibeVoluntario(*volunPesquisado);
					int escolha = menuBuscarVolun();
					
					if(escolha == 2)//Excluir voluntario
					{
						char op;
						if(tamanhoLista(*getVoluntarios(getAcao(volunPesquisado)))==1)
						{
							printf("\nA ação referente a esse voluntário possui somente ele!\n");
							printf("Caso exclua o Voluntário a ação também será excluída.\n");
							clear();
							
							do
							{	
								printf("Deseja continuar?\n[S]im  |  [N]ao\n =>");
								op = getchar();
								if(op!='\n')
									getchar();
							}while(op!='S' && op!= 's' && op!= 'N' && op!= 'n');
						}
						if(op == 'S' || op == 's')
						{
							if(removeVoluntario(ong, volunPesquisado))
							{
								printf("\nVoluntário excluído com sucesso!\n");
								dadosNaoAtualizados = true;
							}
							else
							{
								printf("\nErro ao remover voluntário!\n");
								dadosNaoAtualizados = false;
							}	
						}

					}
				}
				else
				{
					printf("\nVoluntário não encontrado!\n");
				}
				break;
			}
			case 4://Gravar
			{
				if(gravaArquivo(NOMEARQV_AC, NOMEARQV_VO, *ong))
				{
					printf("\nArquivo Gravado com Sucesso!\n");
					dadosNaoAtualizados = false;
				}
				else
				{
					printf("\nErro ao Gravar!\n");
					dadosNaoAtualizados = true;
				}
				break;
			}
			case 5://Sair
			{
				
				if(dadosNaoAtualizados)
				{
					char op;
					do
					{
						printf("\nVocê alterou informações que não foram salvas\n"
						"Deseja salva-las?\n[S]im  | [N]ao\n-> ");
						op = getchar();
						if(op!='\n')
							getchar();		
					}while(op!='S' && op!='s' && op!='N' && op!='n');
					if(op=='S' || op=='s')
					{
						if(gravaArquivo(NOMEARQV_AC, NOMEARQV_VO, *ong))
						{
							printf("\nArquivo Gravado com Sucesso!\n");
							dadosNaoAtualizados = false;
						}
						else
						{
							printf("\nErro ao Gravar!\n");
							dadosNaoAtualizados = true;
						}
					}
				}
				deletaOng(ong);
			}
		}	
	}while(option != 5);	
	printf("\nPrograma Encerrado!\n");
}