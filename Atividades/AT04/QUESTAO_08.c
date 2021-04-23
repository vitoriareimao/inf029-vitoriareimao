/*8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente*/
#include <stdio.h>


typedef struct Cliente
{
	char nome[60];
	char dataNascimento[11];
	char cpf[12];
	char sexo;
}Cliente;

void cadastrarCliente(Cliente *clientes);


int main(){

	Cliente clientes;
	Cliente *p_clientes = &clientes;

	cadastrarCliente(p_clientes);

	printf("Nome: %s\n", clientes.nome);
	printf("Data de nascimento: %s\n", clientes.dataNascimento);
	printf("CPF: %s\n", clientes.cpf);
	printf("Sexo: %c\n", clientes.sexo);

	return 0;
}

void cadastrarCliente(Cliente *clientes)
{
	printf("Informe o nome:\n");
	fflush(stdin);
	fgets(clientes->nome, 60, stdin);
	printf("Informe o Data de nascimento:\n");
	fflush(stdin);
	fgets(clientes->dataNascimento, 11, stdin);
	printf("Informe o CPF:\n");
	fflush(stdin);
	fgets(clientes->cpf, 12, stdin);
	printf("Informe o sexo ('m', 'f' ou 'o'):\n");
	fflush(stdin);
	scanf("%c", &clientes->sexo);
}