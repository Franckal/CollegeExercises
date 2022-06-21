/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#include "InterfaceCentro.h"

void clear()
{
	while(getchar()!='\n');
}

int menuPrincipal()
{
	int aux;
	printf("\n-----------------------------------------------------\n");
	printf("                CENTRO DE PESQUISADORES        \n");
	printf("-----------------------------------------------------\n");
	printf("( 1 ) Inserir Pesquisador   ( 4 ) Buscar Pesquisador\n"
		   "( 2 ) Listar Departamentos  ( 5 ) Gravar Dados\n"
		   "( 3 ) Listar Pesquisadores  ( 6 ) Sair\n-> ");
	scanf("%d", &aux);
	return aux;
}

bool entraPesquisador(Centro * endCentro, Pesquisador * novoPesquisador)
{
	char entrada[100];
	int matricula;
	printf("\n-----------------------------------------------------\n");
	printf("                   NOVO PESQUISADOR       \n");
	printf("-----------------------------------------------------\n");	
	printf("Matricula: ");
	scanf("%d", &matricula);

	Pesquisador * pesqAux = buscaPesquisador(endCentro, matricula);
	if(pesqAux!=NULL)
	{
		printf("Pesquisador com essa matrícula já existe!\n");
		exibePesquisador(pesqAux);
		return false;
	}
		
	setMatricula(novoPesquisador, matricula);
	clear();

	printf("Nome: ");
	scanf("%s", entrada);
	setNome(novoPesquisador, entrada);
	clear();

	printf("Formacao: ");
	scanf("%s", entrada);
	setFormacao(novoPesquisador, entrada);
	clear();

	printf("Contato: ");
	scanf("%s", entrada);
	setContato(novoPesquisador, entrada);
	clear();
	return true;
}

void interfaceMostraDepartamentos(Centro * endCentro)
{
	int i;
	printf("\n-----------------------------------------------------\n");
	printf("                LISTA DE DEPARTAMENTOS       \n");
	printf("-----------------------------------------------------\n");
	
	for(i=0; i<getNumDepartamentos(*endCentro);i++)
	{
		printf("Departamento Indice[%d]: %s\n", i, getNomesDepartamentos(endCentro, i));	
	} 
}

void interfaceMostraPesquisadores(Centro * endCentro, int codDepartamento)
{
	
	
	/* printf("\nDigite o código do Departamento:");
	scanf("%d", &codigo); */
	

	Lista * listaPesquisadores = getListaPesquisadores(endCentro, codDepartamento);
	resetaAtual(listaPesquisadores);
	if(atualLista(*listaPesquisadores) == NULL)
	{
		printf("Esse departamento não possui Pesquisadores!");
	}
	else
	{
		do
		{
			if(atualLista(*listaPesquisadores) == NULL)
				break;
			exibePesquisador(atualLista(*listaPesquisadores));
		}while(proximoLista(listaPesquisadores));
	}	
	
}


void exibePesquisador(Pesquisador * pesquisador)
{
	
	printf("------------------   PESQUISADOR   -----------------\n");
	printf("Matricula: %d\n", pesquisador->matricula);
	printf("Nome: %s\n", pesquisador->nome);
	printf("Formacao: %s\n", pesquisador->formacao);
	printf("Contato: %s\n", pesquisador->contato);
}