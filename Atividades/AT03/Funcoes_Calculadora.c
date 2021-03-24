#include <stdio.h>
#include <string.h>

#include "Assinatura_Funcoes_Calculadora.h"

void Exibir_Menu(){

  printf("\nInforme a operacao desejada:\n\n0 - Sair\n1 - Somar\t2 - Subtrair\n3 - Multiplicar\t4 - Dividir\n\n");

  return;
}


int Receber_Codigo(){

  int  cod;
  scanf("%d", &cod);
  
  return cod;
}

int Processar_Codigo(){
  
  int resultado, resultado_operacao;

  do{
    
    Exibir_Menu();
         
    resultado = Receber_Codigo();
    
    if(resultado == 1){
      printf("\n'SOMAR' foi a operacao selecionada!\n");
      resultado_operacao = Operacao_Somar(10,2);
    }

    if(resultado == 2){
      printf("\n'SUBTRAIR' foi a operacao selecionada!\n");
      resultado_operacao = Operacao_Subtrair(5,2);
    }

    if(resultado == 3){
      printf("\n'MULTIPLICAR' foi a operacao selecionada!\n");
      resultado_operacao = Operacao_Multiplicar(5,3);
    }

    if(resultado == 4){
      printf("\n'DIVIDIR' foi a operacao selecionada!\n");  
      resultado_operacao = Operacao_Dividir(20,2);
    }
    
    }while(resultado != 0);

  printf("\n'SAIR' foi a operacao selecionada!\n");

}


int Operacao_Somar(int valor_A, int valor_B){

  int resultado = valor_A + valor_B;
  printf("\nO resultado da soma dos valores %d e %d eh:\t%d", valor_A, valor_B, resultado);

  return resultado;

}

int Operacao_Subtrair(int valor_A, int valor_B){

  int resultado = valor_A - valor_B;
  printf("\nO resultado da subtacao dos valores %d e %d eh:\t%d", valor_A, valor_B, resultado);

  return resultado;

}

int Operacao_Multiplicar(int valor_A, int valor_B){

  int resultado = valor_A * valor_B;
  printf("\nO resultado da multiplicacao dos valores %d e %d eh:\t%d", valor_A, valor_B, resultado);

  return resultado;

}

int Operacao_Dividir(int valor_A, int valor_B){

  int resultado = valor_A / valor_B;
  printf("\nO resultado da divisão dos valores %d e %d eh:\t%d", valor_A, valor_B, resultado);

  return resultado;

}