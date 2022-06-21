/*
typedef group exc3
{
	Aluno Franck Allyson da Silva Rocha
	Professor Alison Zille Lopes
}Hash;
*/

#include "ArquivoCentro.h"

Centro * carregaDados(char nomeArqv[])
{
	FILE * arqv;
	int numDepartamentos, index, i;
	
	arqv = fopen(nomeArqv, "rb");
	
	if(arqv!=NULL)
	{
		
		if(!fread(&numDepartamentos, sizeof(int), 1, arqv))
			return NULL;
		
		Centro * centroCarregado = criaCentro(numDepartamentos);
		for(i=0; i<numDepartamentos; i++)
		{
			if(!fread(getNomesDepartamentos(centroCarregado, i), sizeof(char)*100, 1, arqv))				
				return NULL;	
		}
		
		while(!feof(arqv))
		{
			Pesquisador * pesqAux = criaPesquisadorVazio();
			if(!fread(pesqAux, sizeof(Pesquisador), 1, arqv))
				break;

			inserePesquisador(centroCarregado, pesqAux);
			
		}
		
		return centroCarregado;
	}
	
	return NULL;
}


int gravaDados(Centro * endCentro, char nomeArqv[])
{
	FILE * arqv = fopen(nomeArqv, "wb");
	int i, index;
	int numDepartamentos = getNumDepartamentos(*endCentro);
	
	if(arqv==NULL)
		return -1;

	if(!fwrite(&numDepartamentos, sizeof(int), 1, arqv))
		return -2;


	for(i=0; i<numDepartamentos; i++)
	{
		if(!fwrite(getNomesDepartamentos(endCentro, i), sizeof(char)*100, 1, arqv))	
			return -3; 		
	}
	
	for(i=0; i<numDepartamentos; i++)
	{
		
		Lista * listaAux = getListaPesquisadores(endCentro, i);
		resetaAtual(listaAux);
		do
		{
			if(atualLista(*listaAux) == NULL)
				break;
			if(!fwrite(atualLista(*listaAux), sizeof(Pesquisador), 1, arqv))
				return -4;
		}while(proximoLista(listaAux));
	}   
	fclose(arqv);
	return 1;
}