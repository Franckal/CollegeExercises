/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/
#include "Centro.h"

Centro * iniciaCentro(Centro * endCentro, int numDepartamentos)
{
	int i;
	endCentro -> numDepartamentos = numDepartamentos;
	endCentro -> nomesDepartamentos = malloc(numDepartamentos*(sizeof(char*)));
	endCentro -> listaPesquisadores = malloc(numDepartamentos*(sizeof(Lista)));
	for(i=0; i<numDepartamentos; i++)
	{
		endCentro->nomesDepartamentos[i] = malloc(sizeof(char)*100);
		iniciaLista(&endCentro -> listaPesquisadores[i]);
	}
	
	return endCentro;
}

Centro * criaCentro(int numDepartamentos)
{
	Centro * novoCentro = malloc(sizeof(Centro));
	
	return iniciaCentro(novoCentro, numDepartamentos);
}

int funcaoHash(Centro centro, int matricula)
{
	int i;
	
	int valor = matricula % centro.numDepartamentos;
	if((valor>=0) && (valor <= centro.numDepartamentos))
		return valor; 
	return -1;
}

int getNumDepartamentos(Centro centro)
{
	return centro.numDepartamentos;
}

void setNomesDepartamentos(Centro * endCentro, char nomeDepartamento[100], int indiceDepartamento)
{
	strcpy(endCentro->nomesDepartamentos[indiceDepartamento], nomeDepartamento);
} 

char * getNomesDepartamentos(Centro * endCentro, int indiceDepartamento)
{
	return endCentro -> nomesDepartamentos[indiceDepartamento];
}

Lista * getListaPesquisadores(Centro * endCentro, int indiceDepartamento)
{
	return &(endCentro -> listaPesquisadores[indiceDepartamento]);
}

Pesquisador * buscaPesquisador(Centro * endCentro, int matricula)
{
	int indice = funcaoHash(*endCentro, matricula);
	
	Lista * listaNoIndice = &(endCentro->listaPesquisadores[indice]);
	
	resetaAtual(listaNoIndice);
	
	do
	{
		if(atualLista(*listaNoIndice) == NULL)
			return NULL;
		if(getMatricula(atualLista(*listaNoIndice)) == matricula)
			return atualLista(*listaNoIndice);
	}while(proximoLista(listaNoIndice));
	return NULL; 
}

bool inserePesquisador(Centro * endCentro, Pesquisador * endPesquisador)
{
	if(endPesquisador == NULL)
		return false;
	int indice = funcaoHash(*endCentro, getMatricula(endPesquisador));
	Lista * listaAux = getListaPesquisadores(endCentro, indice);

	resetaAtual(listaAux);

	do
	{
		if(atualLista(*listaAux)==NULL)
		{
			insereNaLista(listaAux, endPesquisador);
			return true;
		}
			
		if(strcmp(getNome(atualLista(*listaAux)), getNome(endPesquisador)) > 0)
		{
			insereNaLista(listaAux, endPesquisador);
			return true;
		}
			
			
	}while(proximoLista(listaAux));
	return false;

}


Pesquisador * removePesquisador(Centro * endCentro, int matricula)
{
	int indice = funcaoHash(*endCentro, matricula);
	
 	if(buscaPesquisador(endCentro, matricula) != NULL)
		return removeDaLista(getListaPesquisadores(endCentro, indice));
	return NULL;
}

void desalocarCentro(Centro * endCentro)
{
	
	int i;
	for(i=0; i<endCentro->numDepartamentos; i++)
	{
		free(endCentro -> nomesDepartamentos[i]);
		apagaLista((&endCentro -> listaPesquisadores[i]));
	}
	free(endCentro->nomesDepartamentos);
	free(endCentro->listaPesquisadores);
	free(endCentro);
	
}