/*
2) Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração.
*/

#include <stdio.h>


int operacao_subtrair();


int main()
{
  int valorA, valorB, valorC, resultado;
  printf("Informe o primeiro valor\n");    
  scanf ("%d", &valorA);
  printf("Informe o segundo valor\n");    
  scanf ("%d", &valorB);
  printf("Informe o terceiro valor\n");    
  scanf ("%d", &valorC);
  resultado = operacao_subtrair(valorA, valorB, valorC);
  printf("\nO resultado da subtracao dos valores %d, %d e %d eh: %d", valorA, valorB, valorC, resultado);

  return 0;
}

int operacao_subtrair(int valor_A, int valor_B, int valor_C)
{
  int resultado = (valor_A - valor_B) - valor_C;
  return resultado;
}
