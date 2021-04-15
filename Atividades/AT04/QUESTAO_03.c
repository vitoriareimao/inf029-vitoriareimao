/*
3) Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial
deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do
usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
*/

#include <stdio.h>

int fatorial();

int main()
{
	int valor, resultado;
	printf("Informe o numero inteiro que deseja saber seu fatorial\n");   
	scanf ("%d", &valor);
	
	resultado = fatorial(valor);
	if (resultado != -1)
		printf("O fatorial eh %d\n", resultado);
	else
		printf("Nao eh possivel calcular o fatorial de %d\n", valor);

	return 0;
}

int fatorial(int n)
{	
	int resultado;
	 if(n>=0)
    {
           resultado=1;
           while(n>0)
           {
                     resultado*=n;   
                     n--;
           }
           printf("%d!=%d\n",n,resultado);
    }
    else 
    	resultado = -1; 
    return resultado;
}
