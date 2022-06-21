#include "ArquivoAbrigo.h"
/* Programa Feito Por: Franck Allyson da Silva Rocha */


int escreveAbrigo(const char * nomeArquivo, Abrigo * abrigos, int numAbrigos)
{
    /* Função de criar arquivo caso não exista,
    e escrever os abrigos.*/
    if(abrigos==NULL)
        return -1;
    
    FILE * arquivo = fopen(nomeArquivo, "rb+");
    
    int i, id;
    
    if(arquivo==NULL)
    {
        arquivo = fopen(nomeArquivo, "wb");
        if(arquivo==NULL)
            return -3;
        id = 0;
        if(fwrite(&id, sizeof(int), 1, arquivo)!=1)
        {
            fclose(arquivo);
            return -4;
        }
    }
    else if(fread(&id, sizeof(int), 1, arquivo)!=1)
    {
        fclose(arquivo);
        return -5;
    }
    
    for(i=0; i<numAbrigos; i++)
    {
        id++;
        setCodigo(&abrigos[i], id);
    }
    
    
    fseek(arquivo, 0, SEEK_END);
    
    size_t quant = fwrite(abrigos, sizeof(Abrigo), numAbrigos, arquivo);
    
    if(quant!=0)
    {
        fseek(arquivo, 0, SEEK_SET);
        fwrite(&id, sizeof(int), 1, arquivo);
    }
    
    
    fclose(arquivo);
    return quant;
}



int escreveAnimal(const char * NOME_ARQAN, const char * NOME_ARQAB, Animal * animais, int codAbrigo, int numAnimais)
{
    /* Esta Função Cria caso não exista arquivo e adiciona dados caso exista.
        Fiz a Associação do Arquivo de Abrigos ao Arquivo de Animais 
        por meio da atribuição do ID do Abrigo ao nome do arquivo animal. */
    if(animais==NULL)
        return -1;
    
    if(numAnimais==0)
        return -2;
        
    /* Criação do nome do arquivo animal */    
    char nomeArquivoAnimal[50];
    snprintf(nomeArquivoAnimal, 50, "%s%d", NOME_ARQAN, codAbrigo);
    
    FILE * arquivoAnimal = fopen(nomeArquivoAnimal, "rb+");
    
    if(arquivoAnimal==NULL)
    {
        arquivoAnimal = fopen(nomeArquivoAnimal, "wb");
        if(arquivoAnimal==NULL)
            return -3;
        
    }

    fseek(arquivoAnimal, 0, SEEK_END);
    size_t quant = fwrite(animais, sizeof(Animal), numAnimais, arquivoAnimal);
    /*Caso Grave, irei atualizar o meu numero de animais que consta no 
    arquivoabrigo*/
    if(quant!=0)
    {
        /*Essa função atualiza o número de animais dentro do abrigo
        depois que eu recebi um novo animal.*/
        FILE * arquivo = fopen(NOME_ARQAB, "rb+");
        Abrigo abAtualizado;
        fseek(arquivo, ((codAbrigo-1) * sizeof(Abrigo))+sizeof(int), SEEK_SET);
        size_t abLidos = fread(&abAtualizado, sizeof(Abrigo), 1, arquivo);
        abAtualizado.numAnimais += numAnimais;
        
        fseek(arquivo, ((codAbrigo-1) * sizeof(Abrigo))+sizeof(int), SEEK_SET);
        size_t quantAbrigos = fwrite(&abAtualizado, sizeof(Abrigo), 1, arquivo);
        
        if(arquivo!=NULL)
            fclose(arquivo);
    }
    if(arquivoAnimal!=NULL)
        fclose(arquivoAnimal);
    return quant;  
}

Abrigo * pesquisaAbrigo(const char * nomeAbrigo, const char * nomeArquivoAbrigo, const char * nomeArqAn)
{
    /* Esta função me retorna um Abrigo a partir do nome pesquisado pelo usuário
    caso não exista retorna NULL.*/
    FILE * arquivo = fopen(nomeArquivoAbrigo, "rb");
    
    if(arquivo==NULL)
    {
        return NULL;
    }
        
    int i, numAbrigos, numAnimais;
    char nomeArquivoAnimal[50];
    Abrigo * abrigo = _criaAbrigo();
    
    
    size_t quantNumAb = fread(&numAbrigos, sizeof(int), 1, arquivo);
    

    for(i=0; i<numAbrigos;i++)
    {
        fseek(arquivo, (i*sizeof(Abrigo)) + sizeof(int), SEEK_SET);
        size_t quant = fread(abrigo, sizeof(Abrigo), 1, arquivo);
        
        if(strcmp(nomeAbrigo, getNomeAbrigo(abrigo))==0)
        {
            numAnimais = getNumAnimais(*abrigo);
            Animal * listaAnimal = calloc(numAnimais, sizeof(Animal));
            
            snprintf(nomeArquivoAnimal, 50, "%s%d", nomeArqAn, getCodigo(*abrigo));
            FILE * arquivoAnimal = fopen(nomeArquivoAnimal, "rb");
            size_t quantAn = fread(listaAnimal, sizeof(Animal), numAnimais, arquivoAnimal);
            setListaAnimal(abrigo, listaAnimal); 
            if(arquivoAnimal!=NULL)
                fclose(arquivoAnimal);
            if(arquivo!=NULL)
                fclose(arquivo);
            return abrigo;
        }
        destroiAbrigo(abrigo);
    }
    if(arquivo!=NULL)
        fclose(arquivo);
    return NULL;
    
}