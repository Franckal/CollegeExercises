/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/

#ifndef INTERFACEONG_H
#define INTERFACEONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GerenciaOng.h"
#include "ArquivoOng.h"

void clear();
//Funções de MENU.
int menuPrincipal();
int menuBuscarAcao();
int menuBuscarVolun();

/* Insiro uma ação na ong.
Retorna um ponteiro para o endereço inserido. 
Caso Codigo ou Título já exista, retorna NULL.*/
Acao * entraAcao(GerenciaOng * ong);

/* Criei essa função apenas para validar caso o voluntario ja esteja
dentro da ação de destino e não precise ser transferido. */
bool buscarVoluntarioNaAcao(Acao * acao, Voluntario * volun);

/* Insiro um voluntario na ong, 
Retorno um ponteiro para o endereço inserido. 
Caso Matrícula ja Exista, trata as seguintes situações:
Voluntario Já exista e: Esteja na própria ação: Retorna NULO; 
Esteja em outra ação: Pergunta sobre a transferência.
Avisa se a ação remetente tem apenas um voluntario. */
Voluntario * entraVoluntarios(GerenciaOng * ong, Acao * acaoDest);


/* Transfiro o voluntario de ação caso o usuario deseje. 
Se a ação antiga possuia apenas o voluntario transferido, é excluída. */
void transfereVoluntario(GerenciaOng * ong, Voluntario * volun, Acao * acaoNova);

/* Removo a ação desejada da ong e todos os voluntários dentro dela */
bool removeAcao(GerenciaOng * ong, Acao * acao);

/* Remove o voluntário e trata se a ação possuia apenas aquele voluntário
em caso afirmativo, a ação é excluída */
bool removeVoluntario(GerenciaOng * ong, Voluntario * volun);

/* Exibe a ação desejada */
void exibeAcao(Acao acao);

/* Exibe o Voluntário desejado */
void exibeVoluntario(Voluntario voluntario);

/* Exibe TODOS os voluntários da ação. */
void exibeTodosVoluntarios(Acao * acao);

#endif

