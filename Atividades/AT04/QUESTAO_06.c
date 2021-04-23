/*6) Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/
#include <stdio.h>

void ler3Letras(char letras[]);

int main(){

	char letras[3];
	ler3Letras(letras);
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%c\n", letras[i]);
	}
	
	return 0;
}
void ler3Letras(char letras[])
{		
	for(int i = 0; i < 3; i++)
	{
		printf("Informe uma letra\n");
		scanf("%s", &letras[i]);
	}
}