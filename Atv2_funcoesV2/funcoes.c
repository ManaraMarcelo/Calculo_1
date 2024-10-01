#include "funcoes.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

extern double a, b, c, k, x, fx, resultado;
extern double limite_max, limite_min;
extern const double PI;


float calcular_funcao_linear(float a, float b, float x) {
    return (a * x) + b;
}

float calcular_funcao_quadratica(float a, float b, float c, float x) {
    return (a * pow(x, 2)) + (b * x) + c;
}

float calcular_exponencial(float k, float x) {
    return pow(k, x);
}

float calcular_logaritmo(float k, float x) {
    return log(x) / log(k);  // Mudança de base
}

float calcular_seno(float x) {
    return sin(x);
}

float calcular_cosseno(float x) {
    return cos(x);
}

float calcular_tangente(float x) {
    return tan(x);
}

bool entrada_valida(float *valor) {
    return scanf("%f", valor) == 1;  // Retorna verdadeiro se a leitura foi bem-sucedida
}

bool verifica_limite(float valor, float limite_min, float limite_max) {
    return valor >= limite_min && valor <= limite_max;  // Retorna verdadeiro se o valor estiver dentro dos limites
}

float graus_para_radianos(float graus) {
    return graus * (PI / 180.0);  // Converte graus para radianos
}

void exibir_resultado(const char* funcao, float resultado) {
    printf("Resultado da função %s: %.8f\n", funcao, resultado);
}
