/*
Grupo(Exercício2)
{
	Aluno Franck Allyson da Silva Rocha; 
}Professor Alison Zille Lopes;
*/
#include "ArquivoOng.h"

//Funções de formatação
VolunFormatado formataVoluntario(Voluntario * voluntario)
{
	VolunFormatado novoVolun;
	strcpy(novoVolun.matricula, voluntario->matricula);
	strcpy(novoVolun.nomeVolun, voluntario->nomeVolun);
	strcpy(novoVolun.contato, voluntario->contato);
	strcpy(novoVolun.codAcao, getAcao(voluntario)->codAcao);
	
	return novoVolun;
}

AcaoFormatada formataAcao(Acao * acao)
{
	AcaoFormatada novaAcao;
	strcpy(novaAcao.codAcao, acao->codAcao);
	strcpy(novaAcao.tituloAcao, acao->tituloAcao);
	strcpy(novaAcao.descricao, acao->descricao);

	return novaAcao;
}


GerenciaOng * carregaArquivo(char nomeArqvAcoes[], char nomeArqvVolun[])
{
	
	FILE * arqv;
	GerenciaOng * ong = criaOngVazia();
	
 	// Carregando ações
	arqv = fopen(nomeArqvAcoes, "rb");
	Acao * novaAcao;
	AcaoFormatada acaoAtual;
	Registro regAcoes;
	
	if(arqv!=NULL)
	{
		while(!feof(arqv))
		{
			if(!fread(&acaoAtual, sizeof(AcaoFormatada), 1, arqv))
                break;
            novaAcao = criaAcao(acaoAtual.codAcao, acaoAtual.tituloAcao, acaoAtual.descricao, criaLista());      
        	if(novaAcao==NULL)
                break;
			
            iniciaRegistro(&regAcoes, novaAcao, getCodAcao(novaAcao), strlen(getCodAcao(novaAcao)));
            insereArvore(getAcoesOng(ong), regAcoes);	
		} 
		fclose(arqv);
	}

	
	//Carregando voluntarios
	arqv = fopen(nomeArqvVolun, "rb");
	Voluntario * novoVolun;
	VolunFormatado volunAtual;
	Acao * acaoAux;
	Registro regVolun;
	
	if(arqv!=NULL)
	{
		while(!feof(arqv))
		{
			//Leio o voluntario formatado atual
			if(!fread(&volunAtual, sizeof(VolunFormatado), 1, arqv))
                break;
			
			//Pesquiso a acao que o voluntario está associado por meio da função de pesquisa
			acaoAux = pesquisaAcaoByCodigo(ong, volunAtual.codAcao, strlen(volunAtual.codAcao));
			
			//Insiro a Acao ao voluntario, deixando a estrutura completa para o retorno.
            novoVolun = criaVoluntario(volunAtual.matricula, volunAtual.nomeVolun, volunAtual.contato, acaoAux);      
            if(novoVolun==NULL)
                break;
			
			//Atualizo minha lista de voluntarios da Acao
			insereNaLista(getVoluntarios(acaoAux), novoVolun);
			
            iniciaRegistro(&regVolun, novoVolun, getMatricula(novoVolun), strlen(getMatricula(novoVolun)));
            insereArvore(getVoluntariosOng(ong), regVolun);			
		}
		fclose(arqv);
	} 
	  
	return ong;
}

bool gravaArquivo(char nomeArqvAcoes[], char nomeArqvVolun[], GerenciaOng ong)
{
	//**************
	//Gravando Ações
	FILE * arqvAcoes = fopen(nomeArqvAcoes, "wb");
	ArvoreBinaria * acoes = getAcoesOng(&ong);
	Fila fila;
	EndNoh item;
	
	if(arqvAcoes==NULL)
		return false;

	
	if(getRaiz(acoes)==NULL)
	{
		//Se a raiz for nula, basta reiniciar o arquivo, pois não há dados.
		fclose(arqvAcoes);
	}
	else
	{
		AcaoFormatada acaoFormatada;
		Acao * acao;
		
		iniciaFila(&fila);
		insereNaFila(&fila, *getRaiz(acoes));

		
		
		
		while(!filaVazia(fila))
		{
			item = removeDaFila(&fila);
			if(*getFilhoEsquerda(item)!=NULL)
				insereNaFila(&fila, *getFilhoEsquerda(item));
			if(*getFilhoDireita(item)!=NULL)
				insereNaFila(&fila, *getFilhoDireita(item));
	
			//recebo os dados do item e formatado para gravar
			acao = getDadosRegistro(*getRegistroNoh(item));
			acaoFormatada = formataAcao(acao);
			
			if(!fwrite(&acaoFormatada, sizeof(AcaoFormatada), 1, arqvAcoes))
				return false;
		}
		fclose(arqvAcoes);
	}
	
	
	//********************
	//Gravando Voluntarios
	FILE * arqvVolun = fopen(nomeArqvVolun, "wb");
	//ArvoreBinaria * voluntarios = getVoluntariosOng(&ong);
	
	if(arqvVolun==NULL)
		return false;

	if(getRaiz(getVoluntariosOng(&ong))==NULL)
	{
		//Se a raiz é nula, não há porque salvar dados, basta reiniciar o arquivo. 
		fclose(arqvVolun);
	}
	else
	{
		VolunFormatado voluntarioFormatado;
		Voluntario * volun;
		insereNaFila(&fila, *getRaiz(getVoluntariosOng(&ong)));
	
		while(!filaVazia(fila))
		{
			item = removeDaFila(&fila);
			if(*getFilhoEsquerda(item)!=NULL)
				insereNaFila(&fila, *getFilhoEsquerda(item));
			if(*getFilhoDireita(item)!=NULL)
				insereNaFila(&fila, *getFilhoDireita(item));
	
			//recebo os dados do item e formatado para gravar
			volun = getDadosRegistro(*getRegistroNoh(item));
			voluntarioFormatado = formataVoluntario(volun);
			
			if(!fwrite(&voluntarioFormatado, sizeof(VolunFormatado), 1, arqvVolun))
				return false;
		}
		fclose(arqvVolun); 
	}
	return true;
}