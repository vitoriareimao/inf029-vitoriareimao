/*4) Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.*/
#include <stdio.h>

void ler3Numeros(double numeros[]);

int main(){

	double numeros[3];
	ler3Numeros(numeros);
	for (int i = 0; i < 3; i++)
	{
		printf("%.2lf\n", numeros[i]);
	}
	
	return 0;
}
void ler3Numeros(double numeros[])
{		
	for(int i = 0; i < 3; i++)
	{
		printf("Informe um numero\n");
		scanf("%lf", &numeros[i]);
	}
}