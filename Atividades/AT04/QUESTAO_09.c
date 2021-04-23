/*9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERRO 1
#define SUCESSO 0


typedef struct tipoCliente
{
	char nome[60];	
	char cpf[12];
	char sexo;
	char dataNascimento[11];
}CLIENTE;

int cadastrarCliente(CLIENTE *clientes);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarCPF_extraiDigito(int soma);
int validarCPF_somatorio(int cpfConvertido[], int finalFor, int mutiplicador);
int validarNascimento(char data[]);


int main(){

	CLIENTE clientes;
	CLIENTE *p_clientes = &clientes;

	cadastrarCliente(p_clientes);

	printf("\n\n");
	printf("Nome: %s\n", clientes.nome);
	printf("Data de nascimento: %s\n", clientes.dataNascimento);
	printf("CPF: %s\n", clientes.cpf);
	printf("Sexo: %c\n", clientes.sexo);

	return 0;
}

int cadastrarCliente(CLIENTE *clientes)
{
	do
	{
		printf("Informe o nome:");
		fflush(stdin);
		fgets(clientes->nome, 60, stdin);
		if(validarNome(clientes->nome)==ERRO)
			printf("Nome invalido\n");
	}while(validarNome(clientes->nome)!=SUCESSO);
//---------------------------------------------------------------	
	int saida = 1;
	do
    {
        printf("Informe a data (Formato dd/mm/aaaa):");
        fflush(stdin);
        fgets(clientes->dataNascimento, 11, stdin);
        saida = validarNascimento(clientes->dataNascimento);
        if(saida!=1)
        	printf("Data invalida! **(Formato dd/mm/aaaa)**\n");
    }while(validarNascimento(clientes->dataNascimento)!=1);
//---------------------------------------------------------------*/

	do
	{
		printf("Informe o CPF:");
		fflush(stdin);
		fgets(clientes->cpf, 12, stdin);
			if(validarCPF(clientes->cpf)==ERRO)
				printf("CPF invalido\n");
	}while(validarCPF(clientes->cpf)!=SUCESSO);
	do
	{
		printf("Informe o sexo ('f' ou 'F') - ('m' ou 'M') - ('o' ou 'O'):");
		fflush(stdin);
		scanf("%c", &clientes->sexo);
			if(validarSexo(clientes->sexo)==ERRO)
				printf("Sexo invalido\n");
	}while(validarSexo(clientes->sexo)!=SUCESSO);

	return 0;
}

int validarSexo(char sexo)
{
	int retorno;
	if((sexo=='f')||(sexo=='F')||(sexo=='m')||(sexo=='M')||(sexo=='o')||(sexo=='O'))
		retorno = 0;
	else
		retorno = 1;
	return retorno;
}
int validarNome(char nome[])
{
	int retorno;
	int tam = strlen(nome);
	if(tam<=20)
		retorno = 0;
	else
		retorno = 1;
	return retorno;
}

int validarNascimento(char data[])
{
	char dia[3], mes[3], ano[6]; 
    int saida, k, i, j = 0, contBarra=0;
    // Verifica se ha algum caractere estranho a '/' e numeros e se tem mais de duas '/'
    for (k=0; k < strlen(data); k++){
        if (data[k]=='/')
            contBarra++;
        if (contBarra>2)
            saida =2;        
        if(data[k]!='/' && data[k]!='0' && data[k]!='1' && data[k]!='2' && data[k]!='3' && 
           data[k]!='4' && data[k]!='5' && data[k]!='6' && data[k]!='7' && data[k]!='8' && 
           data[k]!='9')
           saida = 3;
    }
    if(contBarra<2){
        saida = 4;
        return saida;
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
        saida = 5;
    // Converte dia mes e ano em inteiros    
    int intDia = atoi(dia);
    int intMes = atoi(mes);
    int intAno = atoi(ano);
    if (intAno >= 00 && intMes <= 9999){
        if (intMes >= 1 && intMes <= 12){
            if ((intDia >= 1 && intDia <= 31) && (intMes == 1 || intMes == 3 || intMes == 5 || intMes == 7 || intMes == 8 || intMes == 10 || intMes == 12))
                saida = 1;
            else if ((intDia >= 1 && intDia <= 30) && (intMes == 4 || intMes == 6 || intMes == 9 || intMes == 11))
                saida = 1;
            else if ((intDia >= 1 && intDia <= 28) && (intMes == 2))
                saida = 1;
            else if (intDia == 29 && intMes == 2 && intAno % 400 == 0 || (intAno % 4 == 0 && intAno % 100 != 0))
                saida = 1;
            else
                saida = 6;
        }else
            saida = 7;
    }else
        saida = 8;  
    return saida;
}
    
int validarCPF(char cpf[])
{
	int retorno;
	int cpfConvertido[10];
	int digito10, digito11, soma;
	for (int i = 0; i < 11; i++)
	{
		cpfConvertido[i] = cpf[i] - '0';
	}
	soma = validarCPF_somatorio(cpfConvertido, 9, 10);
	digito10 = validarCPF_extraiDigito(soma);
	soma = validarCPF_somatorio(cpfConvertido, 10, 11);
	digito11 = validarCPF_extraiDigito(soma);	
	if((digito10 == cpfConvertido[9])&&(digito11 == cpfConvertido[10]))
		retorno = 0;
	else
		retorno = 1;
	return retorno;
}
int validarCPF_somatorio(int cpfConvertido[], int finalFor, int mutiplicador)
{
	int soma = 0;	
	for (int i = 0; i < finalFor; i++)
	{
		soma = soma + (cpfConvertido[i]*mutiplicador);
		mutiplicador--;
	}
	return soma;
}
int validarCPF_extraiDigito(int soma)
{
	int digito, resto;
	resto = soma % 11;
	if(resto<2)
		digito = 0;
	else
		digito = 11 - resto;
	return digito;
}