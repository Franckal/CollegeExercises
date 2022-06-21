/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#include "InterfaceOng.h"

void clear()
{
	while(getchar()!='\n');
}

//Funções de Menu.
int menuPrincipal()
{
	int op;
	do
	{
		
		printf("\n••••••••••••••••••••••••••••••••••••••••••••\n");
		printf("•			AÇÕES FILANTRÓPICAS		   	   •\n");
		printf("•				ONG C.F.I.J				   •\n");
		printf("••••••••••••••••••••••••••••••••••••••••••••\n");
		printf("( 1 ) Inserir Ação       ( 4 ) Gravar dados\n"
				"( 2 ) Buscar Ação        ( 5 ) Sair\n"
				"( 3 ) Buscar Voluntario\n=> ");
		scanf("%d", &op);	
		if(op < 1 || op > 5)
			printf("Opção Inválida!\n\n");
	}while(op < 1 || op > 5 );
	clear();
	return op;
}

int menuBuscarAcao()
{
	int escolha;
	do
	{
		printf("( 1 ) Inserir Voluntarios  ( 3 ) Remover Ação\n"
				"( 2 ) Listar Voluntarios   ( 4 ) Menu Principal\n =>");
		scanf("%d", &escolha);	
		if(escolha < 1 || escolha > 4)
			printf("Opção Inválida!\n\n");
	}while(escolha < 1 || escolha > 4);
	return escolha;
}

int menuBuscarVolun()
{
	int escolha;
	do
	{
		printf("( 1 ) Menu Principal  ( 2 ) Remover Voluntario\n=> ");
		scanf("%d", &escolha);
		if(escolha != 1 && escolha != 2)
			printf("Opção Inválida!\n\n");
	}while(escolha != 1 && escolha != 2);
	return escolha;
}

Acao * entraAcao(GerenciaOng * ong)
{
	ArvoreBinaria * avAcoes = getAcoesOng(ong);
	Acao * novaAcao = _criaAcao();
	Acao * auxCod, * auxTit = _criaAcao();
	
	char entrada[100];
	printf("\n¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	printf("             	 NOVA ACAO                  \n");
	printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");

	
	printf("-> Código da Ação: ");
	scanf("%5s", entrada);
	setCodAcao(novaAcao, entrada);	
	
	auxCod = pesquisaAcaoByCodigo(ong, getCodAcao(novaAcao), strlen(getCodAcao(novaAcao)));
	
	if(auxCod!=NULL)
	{
		printf("\nJá existe uma ação com o Código Passado!\n");
		exibeAcao(*auxCod);
		return NULL;
	}
	clear();
	
	
	printf("-> Título da Ação: ");
	scanf("%49[^\n]", entrada);
	setTituloAcao(novaAcao, entrada);
	
	auxTit = pesquisaAcaoByTitulo(ong, getTituloAcao(novaAcao));
	
	if(auxTit!=NULL)
	{
		printf("\nJá existe uma ação com o Título Passado!\n");
		exibeAcao(*auxTit);
		return NULL;
	}	
	clear();
	
	printf("-> Descrição: ");
	scanf("%99[^\n]", entrada);
	setDescricao(novaAcao, entrada);
	clear();

	//Preencho minha ong e retorno a ação adicionada.
	Registro regAcao;
	iniciaRegistro(&regAcao, novaAcao, getCodAcao(novaAcao), strlen(getCodAcao(novaAcao)));
	insereArvore(avAcoes, regAcao);
	setAcoesOng(ong, avAcoes); 
	return novaAcao;
}

bool buscarVoluntarioNaAcao(Acao * acao, Voluntario * volun)
{
	
	Lista * listaVolunAux = getVoluntarios(acao);
	
	resetaAtual(listaVolunAux);
	do
	{
		if(atualLista(*listaVolunAux)==NULL)
			return false;
		//Aqui vou procurar o voluntario que possui a matricula igual.
		if(strcmp(getMatricula(atualLista(*listaVolunAux)), getMatricula(volun)) == 0)
			return true;	
	}while(proximoLista(listaVolunAux));
}


Voluntario * entraVoluntarios(GerenciaOng * ong, Acao * acaoDest)
{
	ArvoreBinaria * avVolun = getVoluntariosOng(ong);
	Voluntario * novoVolun = _criaVoluntario();
	char entrada[100];
	printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	printf("           	   NOVO VOLUNTARIO              \n");
	printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	printf("-> Matricula: ");
	scanf("%5s", entrada);
	setMatricula(novoVolun, entrada);
	clear();
	Voluntario * volunAux = pesquisaVolunByMatricula(ong, getMatricula(novoVolun), strlen(getMatricula(novoVolun)));
	if(volunAux!=NULL)
	{
		exibeVoluntario(*volunAux);
		char op;
		if(buscarVoluntarioNaAcao(acaoDest, volunAux))
		{
			printf("\nVoluntario com essa matricula já está nesta ação!\n");
			return NULL;
		}
		
		printf("\nVoluntario com a matrícula dada já existe!\n");
		if(pesquisaArvore(getAcoesOng(ong), getCodAcao(getAcao(volunAux)), strlen(getCodAcao(getAcao(volunAux)))))
		{
			char nomeAcao[50];  
			strcpy(nomeAcao, getTituloAcao(getDadosRegistro(*getRegistroAtual(*getAcoesOng(ong)))));
			
			if(tamanhoLista(*getVoluntarios(getDadosRegistro(*getRegistroAtual(*getAcoesOng(ong)))))==1)
			{
				printf("\nA ação [%s] possui apenas um voluntário,\n"
					"logo, caso transfira o voluntário,\n" 
					"ela será removida!\n", nomeAcao);
			}
		}
		
		printf("\nDeseja transferi-lo para esta Ação?\n");
		printf("[S]im || [N]ão\n ->");
		op = getchar();
		if(op!='\n')
			getchar();
		if(op=='S' || op=='s')
		{
			transfereVoluntario(ong, volunAux, acaoDest);
		}
		else
		{
			printf("\nVoluntario que ia ser adicionado foi descartado!\n");
			return NULL;
		}
		Registro regVolun;
		iniciaRegistro(&regVolun, volunAux, getMatricula(volunAux), strlen(getMatricula(volunAux)));
		insereArvore(avVolun, regVolun);
		setVoluntariosOng(ong, avVolun); 
		return volunAux;
	}
	
	printf("-> Nome do Voluntário: ");
	scanf("%49[^\n]", entrada);
	setNomeVolun(novoVolun, entrada);
	clear();

	printf("-> Contato: ");
	scanf("%49[^\n]", entrada);
	setContato(novoVolun, entrada);
	clear();

	printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
	//Insiro a ação referenciada pelo voluntario.
	setAcao(novoVolun, acaoDest);
	//Insiro o voluntario na lista da nova Ação.
	insereNaLista(getVoluntarios(acaoDest), novoVolun);
	
	//preencho a ong
	Registro regVolun;
	iniciaRegistro(&regVolun, novoVolun, getMatricula(novoVolun), strlen(getMatricula(novoVolun)));
	insereArvore(avVolun, regVolun);
	setVoluntariosOng(ong, avVolun); 
	return novoVolun;
}


void transfereVoluntario(GerenciaOng * ong, Voluntario * volun, Acao * acaoNova)
{
	ArvoreBinaria * avAcoes = getAcoesOng(ong);
	
	//Salvo Minha ação antiga para não perder a referencia ao transferir
	Acao * acao = getAcao(volun);

	Lista * listaVolunAux = getVoluntarios(acao);
	
	resetaAtual(listaVolunAux);
	
	do
	{
		if(atualLista(*listaVolunAux)==NULL)
			break;
		//Aqui vou procurar o voluntario que possui a matricula igual. 
		if(strcmp(getMatricula(atualLista(*listaVolunAux)), getMatricula(volun))==0)
		{
			//Apago o dado da Lista
			removeDaLista(listaVolunAux);
			
			//Insiro o voluntario na lista da nova Ação.
			insereNaLista(getVoluntarios(acaoNova), volun);

			//Referencio a nova ação ao voluntario:
			setAcao(volun, acaoNova);
			printf("\nVoluntario transferido com Sucesso!\n");
			
			if(listaVazia(*listaVolunAux))
			{
				//Se minha lista for vazia, a ação não possui Voluntarios e precisa ser excluída.
				if(pesquisaArvore(avAcoes, getCodAcao(acao), strlen(getCodAcao(acao))))
				{
					char nomeAcao[50];  
					
					strcpy(nomeAcao, getTituloAcao(getDadosRegistro(*getRegistroAtual(*avAcoes))));
					//Apago a Ação que não tem voluntarios.
					removeAtualArvore(avAcoes);
					printf("\nAção [%s] removida por falta de voluntarios!\n", nomeAcao);
				}
			}
		}
	}while(proximoLista(listaVolunAux));
}

bool removeAcao(GerenciaOng * ong, Acao * acao)
{
	ArvoreBinaria * avAcoes = getAcoesOng(ong);
	//ArvoreBinaria * avVoluntarios = getVoluntariosOng(ong);
	Lista * listaVolunAcao = getVoluntarios(acao);
	
	//Removendo Voluntarios da ação
	resetaAtual(listaVolunAcao);
	do
	{
		if(atualLista(*listaVolunAcao)==NULL)
			break;
		if(pesquisaArvore(getVoluntariosOng(ong), getMatricula(atualLista(*listaVolunAcao)), strlen(getMatricula(atualLista(*listaVolunAcao)))))
		{
			removeAtualArvore(getVoluntariosOng(ong));
			removeDaLista(listaVolunAcao);
		}		
	}while(proximoLista(listaVolunAcao));
	if(pesquisaArvore(getAcoesOng(ong), getCodAcao(acao), strlen(getCodAcao(acao))))
	{
		removeAtualArvore(getAcoesOng(ong));
		return true;
	}
	else
		return false;
}

bool removeVoluntario(GerenciaOng * ong, Voluntario * volun)
{
	ArvoreBinaria * avVolun = getVoluntariosOng(ong);
	ArvoreBinaria * avAcoes = getAcoesOng(ong);

	//Açao ao qual o voluntário a ser excluído pertence
	Acao * acao = getAcao(volun);

	//Lista de voluntarios que vou manipular.
	Lista * listaVolunAux = getVoluntarios(acao);
	
	resetaAtual(listaVolunAux);
	do
	{
		if(atualLista(*listaVolunAux)==NULL)
			return false;
		//Aqui vou procurar o voluntario que possui a matricula igual. 
		if(strcmp(getMatricula(atualLista(*listaVolunAux)), getMatricula(volun))==0)
		{
			//Apago o dado da Lista
			Voluntario * volunRemov = removeDaLista(listaVolunAux);	
			
			if(volunRemov!=NULL)
			{	
				
				if(pesquisaArvore(avVolun, getMatricula(volunRemov), strlen(getMatricula(volunRemov))))
				{
					removeAtualArvore(avVolun);
					if(listaVazia(*listaVolunAux))
					{
						//Se minha lista for vazia, a ação não possui Voluntarios e precisa ser excluída.
						if(pesquisaArvore(avAcoes, getCodAcao(acao), strlen(getCodAcao(acao))))
						{
							char nomeAcao[50];
							strcpy(nomeAcao, getTituloAcao(getDadosRegistro(*getRegistroAtual(*avAcoes))));
							//Apago a Ação que não tem voluntarios.
							removeAtualArvore(avAcoes);
							printf("\nAção [%s] removida por falta de voluntarios!\n", nomeAcao);
						}	
					}
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	}while(proximoLista(listaVolunAux));
}

void exibeAcao(Acao acao)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("					AÇÃO            	 	\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Codigo: %s \n", acao.codAcao);
	printf("Título: %s \n", acao.tituloAcao);
	printf("Descrição: %s \n", acao.descricao);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
}

void exibeVoluntario(Voluntario voluntario)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("				VOLUNTARIO            	 	\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Matricula: %s \n", voluntario.matricula);
	printf("Nome: %s \n", voluntario.nomeVolun);
	printf("Contato: %s \n", voluntario.contato);
	printf("Pertence a Ação: %s\n", (voluntario.acao)->tituloAcao);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void exibeTodosVoluntarios(Acao * acao)
{
	Lista * listaVolunAcao = getVoluntarios(acao);

	resetaAtual(listaVolunAcao);
	do
	{
		if(atualLista(*listaVolunAcao)==NULL)
			break;
		Voluntario * voluntarioAtual = atualLista(*listaVolunAcao);
		exibeVoluntario(*voluntarioAtual);
	}while(proximoLista(listaVolunAcao));
}



