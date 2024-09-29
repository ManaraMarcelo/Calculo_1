#include <stdio.h>
#include <string.h>
#include <math.h>

int opcao = 0;
double radiano = 0;
double grau = 0;

double radianos_para_graus(double radiano) {
    return radiano * (180.0 / M_PI);
}
double graus_para_radianos(double grau) {
    return grau * (M_PI / 180.0);
}
int linha(){
  printf("\n=================================\n");
}

int main(void) {
  while(opcao != 3){
    printf("\n ==============Menu==============\n");
    printf("\n1- Grau para Radiano;");
    printf("\n2- Radiano para Grau;");
    printf("\n3- Sair;");
    printf("\nSelecione uma das opções acima: ");
    scanf("%d", &opcao);
    printf("\n");
    linha();
    switch(opcao){
      case 1: 
        printf("\nVamos converter grau para radiano: ");
        printf("\nInsira o valor do grau: ");
        scanf("%lf", &grau);
        printf("%.4f graus é igual a %.4f radianos\n", grau, graus_para_radianos(grau));
        printf("\n");
      break;
      case 2: 
        printf("Vamos converter radiano para grau: ");
        printf("Insira o valor de radiano ja convertido com 4 casas decimais: ");
        scanf("%lf", &radiano);
        printf("%.4f radianos é igual a %.4f graus\n", radiano, graus_para_radianos(radiano));
        printf("\n");
      break;
      case 3: printf("\nVocê Saiu do Menu"); break;
      default: printf("\nEscolha Inválida!");
      printf("\n");
    }
  }
  return 0;
}