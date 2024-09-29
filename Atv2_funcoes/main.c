#include <stdio.h>
#include <stdbool.h>
#include <math.h>  // Necessário para as funções trigonométricas e pow

int opcao = 0;
float a, b, c, k, x, fx;
float resultado = 0;
float limite_max = 100.0;
float limite_min = -100.0;
const float PI = 3.14159265359;

float calcular_funcao_linear(float a, float b, float x);
float calcular_funcao_quadratica(float a, float b, float c, float x);
float calcular_exponencial(float k, float x);
float calcular_logaritmo(float k, float x);
float calcular_seno(float x);
float calcular_cosseno(float x);
float calcular_tangente(float x);
bool entrada_valida(float *valor);
bool verifica_limite(float valor, float limite_min, float limite_max);
float graus_para_radianos(float graus);

int main(void) {
  while(opcao != 8){
    printf("\n ==============Menu==============\n");
    printf("\n1- f(x) = a*x + b");
    printf("\n2- f(x) = a*x^2 + b*x + c");
    printf("\n3- f(x) = k^x");
    printf("\n4- f(x) = log_k(x)");
    printf("\n5- f(x) = sin(x)");
    printf("\n6- f(x) = cos(x)");
    printf("\n7- f(x) = tan(x)");
    printf("\n8- Sair;\n");
    printf("\nSua Escolha: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        printf("\n---------f(x) = a*x + b---------\n");
        // Pedindo os valores e validando como já foi feito antes
        do {
            printf("Digite o valor de a (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&a)) {
                printf("Entrada inválida. Digite um número válido para a: ");
            }
        } while (!verifica_limite(a, limite_min, limite_max));

        do {
            printf("Digite o valor de b (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&b)) {
                printf("Entrada inválida. Digite um número válido para b: ");
            }
        } while (!verifica_limite(b, limite_min, limite_max));

        do {
            printf("Digite o valor de x (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        resultado = calcular_funcao_linear(a, b, x);
        printf("\nResultado de f(x) = a*x + b: %.8f", resultado);
        if (a > 0) {//crescente ou decrescente
            printf("A função é crescente.\n");
        } else if (a < 0) {
            printf("A função é decrescente.\n");
        } else {
            printf("A função é constante.\n");
        }
        if (a != 0) {//Zero da função
            float zero_da_funcao = -b / a;
            printf("O zero da função é x = %.2f\n", zero_da_funcao);
        } else {
            printf("Não há zero da função, pois a = 0.\n");
        }
        printf("\n ");
      break;

      case 2:
        printf("\n---------f(x) = a*x^2 + b*x + c---------\n");

        do {
            printf("Digite o valor de a (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&a)) {
                printf("Entrada inválida. Digite um número válido para a: ");
            }
        } while (!verifica_limite(a, limite_min, limite_max));

        do {
            printf("Digite o valor de b (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&b)) {
                printf("Entrada inválida. Digite um número válido para b: ");
            }
        } while (!verifica_limite(b, limite_min, limite_max));

        do {
            printf("Digite o valor de c (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&c)) {
                printf("Entrada inválida. Digite um número válido para c: ");
            }
        } while (!verifica_limite(c, limite_min, limite_max));

        do {
            printf("Digite o valor de x (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        resultado = calcular_funcao_quadratica(a, b, c, x);
        printf("\nResultado de f(x) = a*x^2 + b*x + c: %.8f", resultado);
        if (a > 0) {// concava para cima ou para baixo
            printf("\nA função é côncava para cima.\n");
        } else if (a < 0) {
            printf("\nA função é côncava para baixo.\n");
        } else {
            printf("\nA função não é uma parábola (a = 0).\n");
        }

        // Cálculo dos vértices Xv e Yv
        if (a != 0) {
            float xv = -b / (2 * a);  // Cálculo de Xv
            float delta = (b * b) - (4 * a * c);  // Cálculo do discriminante (Delta)
            float yv = -delta / (4 * a);  // Cálculo de Yv

            printf("O vértice da função é: Xv = %.2f, Yv = %.2f\n", xv, yv);

            // Cálculo das raízes x1 e x2 (zeros da função)
            if (delta > 0) {
                float x1 = (-b + sqrt(delta)) / (2 * a);
                float x2 = (-b - sqrt(delta)) / (2 * a);
                printf("As raízes da função são: x1 = %.2f, x2 = %.2f\n", x1, x2);
            } else if (delta == 0) {
                float x1 = -b / (2 * a);  // Quando delta é 0, as raízes são iguais
                printf("A função tem uma raiz real: x1 = %.2f\n", x1);
            } else {
                printf("A função não tem raízes reais (Delta < 0).\n");
            }
        } else {
            printf("A função não é uma parábola, pois a = 0.\n");
        }
        printf("\n ");
      break;

      case 3:
        printf("\n---------f(x) = k^x---------\n");

        do {
            printf("Digite o valor de k (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&k)) {
                printf("Entrada inválida. Digite um número válido para k: ");
            }
        } while (!verifica_limite(k, limite_min, limite_max));

        do {
            printf("Digite o valor de x (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));
        if (k > 1) {//crescente ou decrescente
            printf("\nA função é crescente.\n");
        } else if (k > 0 && k < 1) {
            printf("\nA função é decrescente.\n");
        } else if (k == 1) {
            printf("\nA função é constante.\n");
        } else {
            printf("\nValor inválido para k. k deve ser maior que 0.\n");
        }
        resultado = calcular_exponencial(k, x);
        printf("\nResultado de f(x) = k^x: %.8f", resultado);
        printf("\n ");
      break;

      case 4:
        printf("\n---------f(x) = log_k(x)---------\n");

        do {
            printf("Digite o valor de k (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&k)) {
                printf("Entrada inválida. Digite um número válido para k: ");
            }
        } while (!verifica_limite(k, limite_min, limite_max));

        do {
            printf("Digite o valor de x (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        if (k <= 0 || x <= 0) {
            printf("Valores inválidos para logaritmo. O valor de k e x devem ser maiores que 0.\n");
        } else {
            // Verificação se a função é crescente ou decrescente e validade
            if (k > 1) {
                printf("\nA função é crescente.\n");
            } else if (0 < k && k < 1) {
                printf("\nA função é decrescente.\n");
            } else {
                printf("\nValor inválido para k. k deve ser maior que 0 e diferente de 1.\n");
                break; // Para evitar cálculo se k não é válido
            }
            resultado = calcular_logaritmo(k, x);
            printf("\nResultado de f(x) = log_k(x): %.8f", resultado);
        }
        printf("\n ");
      break;

      case 5:
        printf("\n---------f(x) = sin(x)---------\n");

        do {
            printf("Digite o valor de x em graus (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        resultado = calcular_seno(graus_para_radianos(x));
        printf("\nResultado de f(x) = sin(x): %.8f", resultado);
        printf("\n ");
      break;

      case 6:
        printf("\n---------f(x) = cos(x)---------\n");

        do {
            printf("Digite o valor de x em graus (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        resultado = calcular_cosseno(graus_para_radianos(x));
        printf("\nResultado de f(x) = cos(x): %.8f", resultado);
        printf("\n ");
      break;

      case 7:
        printf("\n---------f(x) = tan(x)---------\n");

        do {
            printf("Digite o valor de x em graus (entre %.2f e %.2f): ", limite_min, limite_max);
            while (!entrada_valida(&x)) {
                printf("Entrada inválida. Digite um número válido para x: ");
            }
        } while (!verifica_limite(x, limite_min, limite_max));

        resultado = calcular_tangente(graus_para_radianos(x));
        printf("\nResultado de f(x) = tan(x): %.8f", resultado);
        printf("\n ");
      break;

      case 8:
        printf("\nVocê Saiu do Menu\n");
        break;

        default:
            printf("\nEscolha Inválida!\n");
    }
  }
    return 0;
}

// Função para verificar se a entrada é válida
bool entrada_valida(float *valor) {
    int resultado = scanf("%f", valor);
    while (getchar() != '\n'); // Limpa o buffer
    return resultado == 1;
}

// Função para verificar se o valor está dentro dos limites
bool verifica_limite(float valor, float limite_min, float limite_max) {
    if (valor < limite_min || valor > limite_max) {
        printf("Valor fora dos limites permitidos (%.2f a %.2f).\n", limite_min, limite_max);
        return false;
    }
    return true;
}

// Função para converter graus para radianos
float graus_para_radianos(float graus) {
    return graus * (PI / 180.0);
}

// Função para calcular f(x) = a*x + b
float calcular_funcao_linear(float a, float b, float x) {
    return a * x + b;
}

// Função para calcular f(x) = a*x^2 + b*x + c
float calcular_funcao_quadratica(float a, float b, float c, float x) {
    return a * x * x + b * x + c;
}

// Função para calcular f(x) = k^x
float calcular_exponencial(float k, float x) {
    return pow(k, x);
}

// Função para calcular f(x) = log_k(x)
float calcular_logaritmo(float k, float x) {
    return log(x) / log(k); // Mudança de base para logaritmo
}

// Função para calcular f(x) = sin(x)
float calcular_seno(float x) {
    return sin(x);
}

// Função para calcular f(x) = cos(x)
float calcular_cosseno(float x) {
    return cos(x);
}

// Função para calcular f(x) = tan(x)
float calcular_tangente(float x) {
    return tan(x);
}

