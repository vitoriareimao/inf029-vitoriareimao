/*#### Funcionalidades da Versão v01 ####

Estrutura básica para representar aluno
Estrutura inicial de menu e switch
Lista de alunos
Inserir aluno
Listar alunos
Criar uma pasta chamada Escola, dentro dela adicionar a pasta v01*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tipo_aluno {
		char nome[100], sexo, cpf[12], dataNascimento[11];
		int matricula;
}ALUNO;

int main(){
	ALUNO vetAlunos[3];
    int opcao = 0;
    int qtdAlunos = 0;
	do
	{ 
	    printf ("\n******************************ALUNO*****************************\n\n"); 	
	    printf ("\t1 - INSERIR\t\t2 - LISTAR\t\t0 - SAIR\t\t\n\n"); 	
	    printf ("******************************************************************\n"); 
		scanf ("%d", &opcao);  
		
		switch (opcao)
		{
			case 0:
			{
				printf ("Saindo...\n"); 
				break;
			}
			case 1:
			{
				printf("Insira o Nome do aluno(a): ");
				setbuf(stdin, NULL);
				fgets(vetAlunos[qtdAlunos].nome, 100, stdin);
				printf("Insira a data de nascimento do aluno(a) (dd/mm/aaaa): ");
				setbuf(stdin, NULL);
				fgets(vetAlunos[qtdAlunos].dataNascimento, 11, stdin);
				printf("Informe o sexo ('f' ou 'F') - ('m' ou 'M') - ('o' ou 'O'): ");
				scanf("%s", &vetAlunos[qtdAlunos].sexo);
				printf("Informe o CPF:");
				setbuf(stdin, NULL);
				fgets(vetAlunos[qtdAlunos].cpf, 12, stdin);
				vetAlunos[qtdAlunos].matricula = 1001 + qtdAlunos;
				printf("Cadastrado realizado com sucesso!\n");
				printf("Matricula gerada: %d\n", vetAlunos[qtdAlunos].matricula);
				qtdAlunos++;
				break;
			}
			case 2:
			{
					int opcao2 = 0;
					char aux[100];
				do
				{
					printf ("\n******************************ALUNO*****************************\n\n"); 	
					printf ("\t1 - TODOS\t2 - MASCULINO/FEMININO\t3 - ORDEM ALFABETICA \t4 - IDADE\t0 - VOLTAR\n\n"); 	
					printf ("******************************************************************\n"); 
					scanf ("%d", &opcao2);
					switch (opcao2)
					{
						case 1:
						{
							if(qtdAlunos==0)
							{
								printf("Nenhum aluno consta no cadastro.\n");
								break;
							}
							printf("**********ALUNOS**********\n");
							for (int i=0;i<qtdAlunos;i++){
								printf("Nome: %s\nSexo: %c\nCPF: %s\nMatricula: %d\n\n----\n", vetAlunos[i].nome, 
								vetAlunos[i].sexo, vetAlunos[i].dataNascimento, vetAlunos[i].cpf, vetAlunos[i].matricula);
							}		
							break;
						}    
						case 2:
						{
							if(qtdAlunos==0)
							{
								printf("Nenhum aluno consta no cadastro.\n");
								break;
							}
							printf("**********ALUNOS DO SEXO MASCULINO**********\n");
							for (int i=0;i<qtdAlunos;i++){
								if(vetAlunos[i].sexo == 'M' || vetAlunos[i].sexo == 'm')
									printf("%s\n", vetAlunos[i].nome);
							}
							printf("\n");
							printf("**********ALUNOS DO SEXO FEMININO**********\n"); 
							for (int i=0;i<qtdAlunos;i++){
								if((vetAlunos[i].sexo == 'F') || (vetAlunos[i].sexo == 'f'))
									printf("%s\n", vetAlunos[i].nome);
							}
							break;
						}
						case 3:
						{
							if(qtdAlunos==0)
							{
								printf("Nenhum aluno consta no cadastro.\n");
								break;
							}
							printf("**********ALUNOS ORDEM ALFABETICA*********\n");
							for (int i=0;i<qtdAlunos-1;i++){
								for(int j=i+1;j<qtdAlunos;j++){
									if(strcmp(vetAlunos[i].nome, vetAlunos[j].nome) > 0){
										strcpy(aux, vetAlunos[i].nome);
										strcpy(vetAlunos[i].nome, vetAlunos[j].nome);
										strcpy(vetAlunos[j].nome, aux);	
									}
								}
							}
							for (int i=0;i<qtdAlunos;i++){
								printf("%s\n", vetAlunos[i].nome);
							}
							break;
						}
						case 4:
						{
							if(qtdAlunos==0)
							{
								printf("Nenhum aluno consta no cadastro.\n");
								break;
							}
							printf("**********ALUNOS POR IDADE*********\n");
							printf("ATENCAO! Funcionalidade em manutencao.\n");
							break;
						}
						default:
						{
							printf ("OPCAO INVALIDA!\n");
							break;
						} 
					}
				}while(opcao2!=0);
			}
			default:
			{
				printf ("OPCAO INVALIDA!\n");
				break;
			}	
		}
	}while(opcao!=0);
    return 0;
}