/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#include "Voluntario.h"

//Funções de alocação dinâmica
Voluntario * _criaVoluntario()
{
	return malloc(sizeof(Voluntario));
}

Voluntario * criaVoluntario(char matricula[6], char nomeVolun[50], char contato[50], Acao * acao)
{
	Voluntario * novoVolun = _criaVoluntario();
	setMatricula(novoVolun, matricula);
	setNomeVolun(novoVolun, nomeVolun);
	setContato(novoVolun, contato);
	setAcao(novoVolun, acao);

	return novoVolun;
}

//Funções de manibulação
void setMatricula(Voluntario * endVolun, char matricula[6])
{
	strcpy(endVolun -> matricula, matricula);
}
char * getMatricula(Voluntario * endVolun)
{
	return endVolun -> matricula;	
}

void setNomeVolun(Voluntario * endVolun, char nomeVolun[50])
{
	strcpy(endVolun -> nomeVolun, nomeVolun);
}
char * getNomeVolun(Voluntario * endVolun)
{
	return endVolun -> nomeVolun;
}

void setContato(Voluntario * endVolun, char contato[50])
{
	strcpy(endVolun -> contato, contato);
}
char * getContato(Voluntario * endVolun)
{
	return endVolun -> contato;
}

void setAcao(Voluntario * endVolun, Acao * acao)
{
	endVolun -> acao = acao;
}
Acao * getAcao(Voluntario * endVolun)
{
	return endVolun -> acao;
}

