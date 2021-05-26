#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "VitoriaTeles-2019116048-T2.h"

void dobrar(int *x)
{

    *x = *x * 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0, resposta;
        resposta = ehPosicaoValida(posicao);
        if (resposta == SUCESSO)
        {
            posicao--;
            if (tamanho>=1)
            {
                if(lista[posicao].aux==NULL)
                {
                    lista[posicao].aux=(int *)malloc(tamanho * sizeof(int));
                    lista[posicao].tamanhoEstrutura=tamanho;
                    retorno= SUCESSO;
                }
                else
                {
                    retorno=JA_TEM_ESTRUTURA_AUXILIAR;
                }   
            }
            else
            {
                retorno= TAMANHO_INVALIDO;
            }   
        }
        else

        {
            retorno=POSICAO_INVALIDA;
        }
        
        return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno=0, resposta;
      resposta= ehPosicaoValida(posicao);
        if(resposta==SUCESSO)
        {
            posicao--;  
            if(lista[posicao].aux!=NULL)
            {
                if(lista[posicao].qtdElementos < lista[posicao].tamanhoEstrutura)
                {
                    lista[posicao].aux[lista[posicao].qtdElementos]=valor;
                    lista[posicao].qtdElementos++;
                    retorno=SUCESSO;
                }
                else
                {
                    retorno=SEM_ESPACO;
                }
            }
            else
            {
                retorno=SEM_ESTRUTURA_AUXILIAR;
            }
        }
        else
        {
            retorno = POSICAO_INVALIDA;
        }
        return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno=0, resposta;
      resposta= ehPosicaoValida(posicao);
        if(resposta==SUCESSO){
            posicao--;      
            if(lista[posicao].aux!=NULL)
            {
                if(lista[posicao].qtdElementos>0){
                    lista[posicao].aux[lista[posicao].qtdElementos]=lista[posicao].aux[lista[posicao].qtdElementos+1];
                    lista[posicao].qtdElementos--;
                    retorno=SUCESSO;
                }
                else{
                    retorno=ESTRUTURA_AUXILIAR_VAZIA;
                }
        
            }
            else{
                retorno=SEM_ESTRUTURA_AUXILIAR;
            }
        }
        else{
            retorno= POSICAO_INVALIDA;
        }
        
        return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int x, y, retorno=0, resposta;
    resposta= ehPosicaoValida(posicao);
    if(resposta==SUCESSO)
    {
        posicao--;
        if(lista[posicao].aux!=NULL)
        {
            if(lista[posicao].qtdElementos!=0)
            {
                for(x=0; x<lista[posicao].qtdElementos; x++)
                {
                    if(lista[posicao].aux[x]==valor)
                    {
                        for(y=x; y<lista[posicao].qtdElementos-1; y++)
                        {
                            lista[posicao].aux[y]=lista[posicao].aux[y+1];
                        }
                        retorno=SUCESSO;
                        lista[posicao].qtdElementos--;
                    }
                    else
                    {
                        retorno=NUMERO_INEXISTENTE;
                    }
                }
            }
            else
            {
                retorno=ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
                retorno=SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno= POSICAO_INVALIDA;
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int x, retorno=0, resposta;
    resposta= ehPosicaoValida(posicao);
    if(resposta==SUCESSO)
    {
        posicao--;
        if(lista[posicao].aux!=NULL)
        {
            for (x=0; x<lista[posicao].qtdElementos ;x++)
            {
                vetorAux[x]=lista[posicao].aux[x];
                retorno= SUCESSO;
            }   
        }
        else
        {
            retorno=SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno=POSICAO_INVALIDA;
    }   

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int x, retorno=0, resposta;
    resposta= ehPosicaoValida(posicao);
    if(resposta==SUCESSO){
        posicao--;
        if(lista[posicao].aux!=NULL){
            for (x=0; x<lista[posicao].qtdElementos ;x++){
                vetorAux[x]=lista[posicao].aux[x];
                retorno= SUCESSO;
            }
            ordenar(vetorAux, posicao);
        }
        else{
            retorno=SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else{
        retorno=POSICAO_INVALIDA;
    }  
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int x, y, z = 0, retorno=SUCESSO;
    for(x=0; x<TAM; x++)
    {
        if(lista[x].aux!=NULL)
        {
            for(y=0; y<lista[x].qtdElementos; y++)
            {
                vetorAux[z]=lista[x].aux[y];
                z++;
            }
        }
        else
        {
            retorno=TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;    
        }       
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int x, y, z = 0, retorno=0, resultado;    
    for(x=0; x<TAM; x++)
    {
        if(lista[x].aux!=NULL)
        {
            for(y=0; y<lista[x].qtdElementos; y++)
            {
                vetorAux[z]=lista[x].aux[y];
                z++;
            }
            retorno= SUCESSO;
            for (x=0; x<TAM; x++)
            {
                ordenar(vetorAux, x);
            }
        }
        else
        {
            retorno=TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        }
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno=0, tamanhoAtualizado, resposta;
    resposta= ehPosicaoValida(posicao);
    if(resposta==SUCESSO)
    {
        posicao--;
        tamanhoAtualizado= novoTamanho + lista[posicao].tamanhoEstrutura;
        if (tamanhoAtualizado>=1)
        {
            if(lista[posicao].aux==NULL)
            {
                retorno=SEM_ESTRUTURA_AUXILIAR;
            }
            else
            {
                lista[posicao].aux=(int *)malloc(tamanhoAtualizado * sizeof(int));
                lista[posicao].tamanhoEstrutura=tamanhoAtualizado;
                retorno= SUCESSO;
            }   
        }
        else
        {
            retorno= NOVO_TAMANHO_INVALIDO;
        }       
    }
    else
    {
        retorno=POSICAO_INVALIDA;
    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno=0, resposta;
    resposta= ehPosicaoValida(posicao);
    if(resposta==SUCESSO)
    {
        posicao--;
        if(lista[posicao].aux!=NULL)
        {
            if(lista[posicao].qtdElementos == 0)
            {
                retorno=ESTRUTURA_AUXILIAR_VAZIA;
            }
            else
            {
                retorno = lista[posicao].qtdElementos;
            }
        }
    }
    else
    {
        retorno=POSICAO_INVALIDA;       
    }
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
}

void ordenar(int vetorAux[], int posicao)
{
    int resposta, i, j, reserva;
    resposta= ehPosicaoValida(posicao);
    if (resposta==SUCESSO)
    {
        for(i=0;i<lista[posicao].qtdElementos;i++)
        {
            for(j=i+1;j<lista[posicao].qtdElementos; j++)
            {
                if(vetorAux[i]>vetorAux[j])
                {
                    reserva=vetorAux[i];
                    vetorAux[i]=vetorAux[j];
                    vetorAux[j]=reserva;
                }
            }
        }
    }   
}