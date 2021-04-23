// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Vitoria Gomes Reimao Teles
//  email: vi.reimao@gmail.com
//  Matrícula:  2019116048
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include<stdlib.h>


/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    char dia[3], mes[3], ano[6]; 
    int k, i, j = 0, contBarra=0;
    // Verifica se ha algum caractere estranho a '/' e numeros e se tem mais de duas '/'
    for (k=0; k < strlen(data); k++){
        if (data[k]=='/')
            contBarra++;
        if (contBarra>2)
            return 0;        
        if(data[k]!='/' && data[k]!='0' && data[k]!='1' && data[k]!='2' && data[k]!='3' && 
           data[k]!='4' && data[k]!='5' && data[k]!='6' && data[k]!='7' && data[k]!='8' && 
           data[k]!='9')
           return 0;
    }
    dia[0]='\0';
    mes[0]='\0';
    ano[0]='\0';
    // Separa os numeros baseado na separacao dos '/'
    for (i=0;  data[i]!='/'; i++)
        dia[i] = data[i];
    for (i=i+1;  data[i]!='/'; i++){
        mes[j] = data[i];
        j++;
    }
    j=0;
    for (i=i+1; i <= strlen(data); i++ ){
        ano[j]=data[i];
        j++;
    }
    // Verifica de algum campo ficou vazio
    if (dia[0]=='\0' || mes[0]=='\0' || ano[0]=='\0')
        return 0;
    // Converte dia mes e ano em inteiros    
    int intDia = atoi(dia);
    int intMes = atoi(mes);
    int intAno = atoi(ano);
    if (intAno >= 00 && intMes <= 2020){
	    if (intMes >= 1 && intMes <= 12){
	        if ((intDia >= 1 && intDia <= 31) && (intMes == 1 || intMes == 3 || intMes == 5 || intMes == 7 || intMes == 8 || intMes == 10 || intMes == 12))
                return 1;
            else if ((intDia >= 1 && intDia <= 30) && (intMes == 4 || intMes == 6 || intMes == 9 || intMes == 11))
                return 1;
            else if ((intDia >= 1 && intDia <= 28) && (intMes == 2))
                return 1;
            else if (intDia == 29 && intMes == 2 && intAno % 400 == 0 || (intAno % 4 == 0 && intAno % 100 != 0))
                return 1;
            else
                return 0;
        }else
            return 0;
    }else
        return 0;  
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;


    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;




    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int i, qtdOcorrencias = 0;
    if (isCaseSensitive == 1){
        for(i=0; i<strlen(texto); i++){
            if (texto[i] == c)
                qtdOcorrencias++;
        }
    }
    else{                                               //***ALERTA DE ARMENGUE*** p/ n usar ctype.h
        if (c >= 65 && c <= 90){                        //Verifca se o carac eh maiusc atraves
            for(i=0; i<strlen(texto); i++){             //de seu codigo ASCII e soma 32
                if (texto[i] == c || texto[i] == c+32)  //p/ achar o minusc correspondente
                    qtdOcorrencias++;
            }
        }else if (c >= 97 && c <= 122){                 //Mesma verificacao p/ minusc porem -32
            for(i=0; i<strlen(texto); i++){
                if (texto[i] == c || texto[i] == c-32)
                    qtdOcorrencias++;
            } 
        }   
    } 
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = -1;

    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int i = 10, cont = 0;                   //***ALERTA DE ARMENGUE*** p/ n usar math.h
    while (1){                              //fazendo a contagem dos digitos, poderia fazer
        if(num/i<1)                         //com log()
            break;
        i*=10;
        cont++;
    }
    int numInvertido = 0, aux, j=1, k;
    i=1;                                    //***ALERTA DE ARMENGUE*** p/ n usar math.h
    for(k=0; k<cont; k++)                   //fazendo a potencia, poderia fazer com pow(double,double)
        i*=10;
    while(i>=1){
        aux = num/i;
        num = num%i;
        numInvertido += aux*j;
        i/=10;
        j*=10;
    }
    return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    return qtdOcorrencias;
}
