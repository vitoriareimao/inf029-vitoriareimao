/*5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do
usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize
struct para fazer o retorno.*/
#include <stdio.h>

typedef struct Numeros
{
	double n1;
	double n2;
	double n3;
	double n4;
}listaNumeros;

void ler4Numeros(listaNumeros *numeros);

int main(){

	listaNumeros numeros;
	listaNumeros *p_numeros = &numeros;
	
	ler4Numeros(&numeros);
	
	printf("%.2lf\n", numeros.n1);
	printf("%.2lf\n", numeros.n2);
	printf("%.2lf\n", numeros.n3);
	printf("%.2lf\n", numeros.n4);


	return 0;
}
void ler4Numeros(listaNumeros *numeros)
{	
	printf("Informe um numero\n");
	scanf("%lf", &numeros->n1);
	printf("Informe um numero\n");
	scanf("%lf", &numeros->n2);	
	printf("Informe um numero\n");
	scanf("%lf", &numeros->n3);
	printf("Informe um numero\n");
	scanf("%lf", &numeros->n4);
}