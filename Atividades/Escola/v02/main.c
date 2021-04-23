/*
#### Funcionalidades da Versão v02 ####

Criar funções e mover o código de inserir e listar para dentro de funções
Usar define TAM = 5, para definir um tamanho dos vetores, use em todo o código o TAM
Fazer o mesmo da versão 01 para Professor e Disciplina 
Dentro da pasta Escola, adicionar a pasta v02 e colocar o código dentro dela*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM 5

typedef struct tipo_pessoa
{
	char nome[100], sexo, cpf[12], dataNascimento[11];
	int matricula;
}PESSOA;

typedef struct  tipo_disciplina
{
	char nome[100], codigo[6], semestre;
	PESSOA professor;	
}DISCIPLINA;

void menuPrincipal();
void menuAluno();
void menuProfessor();
void menuDisciplina();
void menuListar();
int inserirPessoa();
int inserirDiciplina();
int listarDados();
int listarDadosPorSexo();
int listarDadosOrdemAlfabetica();
int listaDadosPorIdade();


int main(){
	PESSOA vetAlunos[TAM];
	PESSOA vetProfessores[TAM];
	DISCIPLINA vetDisciplinas[TAM];
    int opcao = 0, qtdAlunos = 0, qtdProfessores = 0, qtdDisciplinas = 0;
	
 	do
 	{
 		menuPrincipal();
		scanf ("%d", &opcao);
		switch(opcao)
		{
			case 0:
			{
				printf ("Saindo...\n"); 
				break;
			}
//------ALUNOS-----------------------
			case 1:
			{	
				do
				{ 
				    menuAluno();
					scanf ("%d", &opcao);  
					switch (opcao)
					{
						case 1:
						{
							inserirPessoa(vetAlunos, &qtdAlunos);
							break;
						}
						case 2:
						{
								int opcao2 = 0;
							do
							{
								menuListar();
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
										listarDados(vetAlunos, &qtdAlunos);
										break;
									}    
									case 2:
									{
										if(qtdAlunos==0)
										{
											printf("Nenhum aluno consta no cadastro.\n");
											break;
										}
										printf("**********ALUNOS POR SEXO**********\n");
										listarDadosPorSexo(vetAlunos, &qtdAlunos);
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
										listarDadosOrdemAlfabetica(vetAlunos, &qtdAlunos);
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
										listaDadosPorIdade(vetAlunos, &qtdAlunos);	
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
			}
//------PROFESSORES------------------
			case 2:
				{
				do
				{ 
				    menuProfessor();
					scanf ("%d", &opcao);  
					switch (opcao)
					{
						/*case 0:
						{
							printf ("Saindo...\n"); 
							break;
						}*/
						case 1:
						{
							inserirPessoa(vetProfessores, &qtdProfessores);
							break;
						}
						case 2:
						{
							int opcao2 = 0;
							do
							{
								menuListar(); 
								scanf ("%d", &opcao2);
								switch (opcao2)
								{
									case 1:
									{
										if(qtdProfessores==0)
										{
											printf("Nenhum professor consta no cadastro.\n");
											break;
										}
										printf("**********PROFESSORES**********\n");
										listarDados(vetProfessores, &qtdProfessores);
										break;
									}    
									case 2:
									{
										if(qtdProfessores==0)
										{
											printf("Nenhum professor consta no cadastro.\n");
											break;
										}
										printf("**********PROFESSORES POR SEXO**********\n");
										listarDadosPorSexo(vetProfessores, &qtdProfessores);
										break;
									}
									case 3:
									{
										if(qtdProfessores==0)
										{
											printf("Nenhum professor consta no cadastro.\n");
											break;
										}
										printf("**********PROFESSORES ORDEM ALFABETICA*********\n");
										listarDadosOrdemAlfabetica(vetProfessores, &qtdProfessores);
										break;
									}
									case 4:
									{
										if(qtdProfessores==0)
										{
											printf("Nenhum professor consta no cadastro.\n");
											break;
										}
										printf("**********PROFESSORER POR IDADE*********\n");
										listaDadosPorIdade(vetProfessores, &qtdProfessores);	
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
			}
//------DISCIPLINAS------------------
			case 3:
			{
				do
				{ 
				    menuDisciplina();
					scanf ("%d", &opcao);  
					switch (opcao)
					{
						/*case 0:
						{
							printf ("Saindo...\n"); 
							break;
						}*/
						case 1:
						{
							inserirDiciplina(vetDisciplinas, &qtdDisciplinas);
							break;
						}
						case 2:
						{
							printf("listar\n");		
						}
					}while(opcao!=0);
				
				}while(opcao!=0);
			}

		}
	}while(opcao!=0);
	return 0;
}
void menuListar()
{
	printf ("\n******************************LISTAR*****************************\n\n"); 	
	printf ("\t1 - TODOS\t2 - MASCULINO/FEMININO\t3 - ORDEM ALFABETICA \t4 - IDADE\t0 - VOLTAR\n\n"); 	
	printf ("******************************************************************\n"); 
}
void menuPrincipal()
{
	printf ("\n************************MENU PRINCIPAL**************************\n\n"); 	
	printf ("\t1 - ALUNO\t\t2 - PROFESSOR\t\t3 - DISCIPLINA\t\t0 - SAIR\t\t\n\n"); 	
	printf ("******************************************************************\n"); 
}
void menuAluno()
{
    printf ("\n******************************ALUNO*****************************\n\n"); 	
    printf ("\t1 - INSERIR\t\t2 - LISTAR\t\t0 - VOLTAR\t\t\n\n"); 	
    printf ("******************************************************************\n"); 
}
void menuProfessor()
{
    printf ("\n***************************PROFESSOR*****************************\n\n"); 	
    printf ("\t1 - INSERIR\t\t2 - LISTAR\t\t0 - VOLTAR\t\t\n\n"); 	
    printf ("******************************************************************\n"); 
}
void menuDisciplina()
{
    printf ("\n***************************DISCIPLINA****************************\n\n"); 	
    printf ("\t1 - INSERIR\t\t2 - LISTAR\t\t0 - VOLTAR\t\t\n\n"); 	
    printf ("******************************************************************\n"); 
}
int inserirPessoa(PESSOA vetor[], int *indiceAtualDoVetor)
{
	printf("Insira o Nome do aluno(a): ");
	setbuf(stdin, NULL);
	fgets(vetor[*indiceAtualDoVetor].nome, 100, stdin);
	printf("Insira a data de nascimento do aluno(a) (dd/mm/aaaa): ");
	setbuf(stdin, NULL);
	fgets(vetor[*indiceAtualDoVetor].dataNascimento, 11, stdin);
	printf("Informe o sexo ('f' ou 'F') - ('m' ou 'M') - ('o' ou 'O'): ");
	scanf("%s", &vetor[*indiceAtualDoVetor].sexo);
	printf("Informe o CPF:");
	setbuf(stdin, NULL);
	fgets(vetor[*indiceAtualDoVetor].cpf, 12, stdin);
	vetor[*indiceAtualDoVetor].matricula = 1001 + *indiceAtualDoVetor;
	printf("Cadastrado realizado com sucesso!\n");
	printf("Matricula gerada: %d\n", vetor[*indiceAtualDoVetor].matricula);
	*indiceAtualDoVetor++;
	return 0;
}																					
int listarDados(PESSOA vetor[], int *indiceAtualDoVetor)
{
	for (int i=0;i<*indiceAtualDoVetor;i++){
		printf("Nome: %s\nSexo: %c\nCPF: %s\nMatricula: %d\n\n----\n", vetor[i].nome, 
		vetor[i].sexo, vetor[i].dataNascimento, vetor[i].cpf, vetor[i].matricula);
	}
	return 0;
}		
int listarDadosPorSexo(PESSOA vetor[], int *indiceAtualDoVetor)
{
	printf("**********MASCULINO**********\n");
	for (int i=0;i<*indiceAtualDoVetor;i++){
		if(vetor[i].sexo == 'M' || vetor[i].sexo == 'm')
			printf("%s\n", vetor[i].nome);
	}
	printf("\n");
	printf("**********FEMININO**********\n"); 
	for (int i=0;i<*indiceAtualDoVetor;i++){
		if((vetor[i].sexo == 'F') || (vetor[i].sexo == 'f'))
			printf("%s\n", vetor[i].nome);
	}
		return 0;
}
int listarDadosOrdemAlfabetica(PESSOA vetor[], int *indiceAtualDoVetor)
{ 
	char aux[100];
	for (int i=0;i<*indiceAtualDoVetor-1;i++){
		for(int j=i+1;j<*indiceAtualDoVetor;j++){
			if(strcmp(vetor[i].nome, vetor[j].nome) > 0){
				strcpy(aux, vetor[i].nome);
				strcpy(vetor[i].nome, vetor[j].nome);
				strcpy(vetor[j].nome, aux);	
			}
		}
	}
	for (int i=0;i<*indiceAtualDoVetor;i++){
		printf("%s\n", vetor[i].nome);
	}
	return 0;
}
int listaDadosPorIdade(PESSOA vetor[], int *indiceAtualDoVetor)
{
	printf("ATENCAO! Funcionalidade em manutencao.\n");
	return 0;
}
int inserirDiciplina(DISCIPLINA vetor[], int *indiceAtualDoVetor){
	int i, sair = 1;

	printf("\n***********************CADASTRO DE DISCIPLINA*************************\n\n");
    	
	do{
		for(i=*indiceAtualDoVetor;i<TAM;i++){
			printf("Informe o nome da Disciplina:\n ");
			setbuf(stdin, NULL);
			fgets(vetor[i].nome, 100, stdin);
				
	
	    	printf("Digite o codigo da Disciplina:\n ");
	    	setbuf(stdin, NULL);
			fgets(vetor[i].codigo, 6, stdin);
	
	    	printf("Informe o semestre da Disciplina:\n ");
	    	scanf("%c", &vetor[i].semestre);

	    	printf("Informe o nome do Professor:\n ");
	    	setbuf(stdin, NULL);
			fgets(vetor[i].professor.nome, 60, stdin);

			*indiceAtualDoVetor++;
	
			printf("DISCIPLINA CADASTRADA COM SUCESSO!\n\nDigite 1 para cadastrar outra disciplina ou digite 0 para sair:\n ");
	    	scanf("%d", &sair);
	    	
	    	if (sair==0)
	    		break;
			else if (sair!=1){
				printf("OPCAO INVALIDA!");
				break;
			}
		}
				
	}while(sair==1);
	return 0;	
}