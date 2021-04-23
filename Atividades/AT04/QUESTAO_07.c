/*7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras.*/
#include <stdio.h>

#define TAM_PALAVRA 47

typedef struct Palavras
{
	char palavra1[TAM_PALAVRA];
	char palavra2[TAM_PALAVRA];
	char palavra3[TAM_PALAVRA];
}listaPalavras;

void ler3Palavras(listaPalavras *palavras);


int main(){

	listaPalavras palavras;
	listaPalavras *p_palavras = &palavras;
	

	ler3Palavras(p_palavras);
	
	printf("%s\n", palavras.palavra1);
	printf("%s\n", palavras.palavra2);
	printf("%s\n", palavras.palavra3);


	return 0;
}

void ler3Palavras(listaPalavras *palavras)
{	
	printf("Informe uma palavra\n");
	fflush(stdin);
	fgets(palavras->palavra1, TAM_PALAVRA, stdin);
	printf("Informe uma palavra\n");
	fflush(stdin);
	fgets(palavras->palavra2, TAM_PALAVRA, stdin);	
	printf("Informe uma palavra\n");
	fflush(stdin);
	fgets(palavras->palavra3, TAM_PALAVRA, stdin);

}
