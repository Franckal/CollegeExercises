#ifndef ARQUIVOABRIGO_H
#define ARQUIVOABRIGO_H
/* Programa Feito Por: Franck Allyson da Silva Rocha */


#include "Animal.h"
#include "Abrigo.h"


/* Escolhi arquivo Binário */

/* escreveAbrigo: Escreve qualquer quantidade de abrigos no arquivo Binário.
    Seta o ID, na hora de escrever. */
int escreveAbrigo(const char * nomeArquivo, Abrigo * abrigos, int numAbrigos);

/* Escreve qualquer quantidade de animais no arquivo de Animais,
    Arquivo Animal é associado ao abrigo através do ID de abrigo, que é referênciado no 
    Nome do Arquivo de Animais.
    Esta função também atualiza o numero de animais que consta no arquivoAbrigo*/
int escreveAnimal(const char * NOME_ARQAN, const char * NOME_ARQAB, Animal * animais, int codAbrigo, int coAbrigo);


/* Pesquisa um Abrigo Através do nome, retorna o Abrigo pesquisado ou NULO se falhar.*/
Abrigo * pesquisaAbrigo(const char * nomeArquivo, const char * nomeArquivoAbrigo, const char * nomeArqAn);

#endif