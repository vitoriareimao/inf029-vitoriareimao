#include <stdio.h>

//Assinatura das funções.
void Exibir_Menu();
int Receber_Codigo();
int Processar_Codigo();

int main (){

  int interacao;
  interacao = Processar_Codigo();


  return 0;
}


void Exibir_Menu(){

  printf("\nInforme a operacao desejada:\n\n0 - Sair\n1 - Somar\t2 - Subtrair\n3 - Multiplicar\t4 - Dividir\n\n");

  return;
}


int Receber_Codigo(){

  int  cod;
  scanf("%d", &cod);
  
  return cod;
}

int Processar_Codigo(){
  
  int resultado;

  do{
    
    Exibir_Menu();
         
    resultado = Receber_Codigo();
    
    if(resultado == 1)
      printf("\n'SOMAR' foi a operacao selecionada!\n");
    if(resultado == 2)
      printf("\n'SUBTRAIR' foi a operacao selecionada!\n");
    if(resultado == 3)
      printf("\n'MULTIPLICAR' foi a operacao selecionada!\n");
    if(resultado == 4)
      printf("\n'DIVIDIR' foi a operacao selecionada!\n");  
  
    }while(resultado != 0);

  printf("\n'SAIR' foi a operacao selecionada!\n");

}
