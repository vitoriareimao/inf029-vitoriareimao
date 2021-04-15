/*
1) Crie um programa que tenha uma funcao soma e a funcao main.
A funcao main deve ler dois valores, enviar para a funcao soma.
A funcao soma deve realizar a soma e retornar o valor. A
Funcao main deve imprimir o resultado da soma.
*/

#include <stdio.h>


int operacao_somar();


int main()
{
  int valorA, valorB, resultado;
  printf("Informe o primeiro valor\n");    
  scanf ("%d", &valorA);
  printf("Informe o segundo valor\n");    
  scanf ("%d", &valorB);
  resultado = operacao_somar(valorA, valorB);
  printf("\nO resultado da soma dos valores %d e %d eh: %d", valorA, valorB, resultado);

  return 0;
}

int operacao_somar(int valor_A, int valor_B)
{
  int resultado = valor_A + valor_B;
  return resultado;
}
