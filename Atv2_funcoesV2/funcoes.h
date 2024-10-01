#ifndef FUNCOES_H // Verifica se FUNCOES_H não foi definido
#define FUNCOES_H // Define FUNCOES_H
#include <stdbool.h> // Biblioteca para booleano

/**
 *Local para armazenar a documentacao das funcoes.
 */

/**
 *
 * @param a Valor de a da funcao
 * @param b valor de b para a funcao
 * @param x valor de x para a funcao
 * @return o resultado da funcao
 */
float calcular_funcao_linear(float a, float b, float x);

/**
 *
 * @param a valor de a da funcao
 * @param b valor de b da funcao
 * @param c valor de c da funcao
 * @param x valor de x da funcao
 * @return o resultado da funcao
 */
float calcular_funcao_quadratica(float a, float b, float c, float x);

/**
 *
 * @param k valor da base da funcao
 * @param x valor do expoente
 * @return o resultado da funcao
 */
float calcular_exponencial(float k, float x);

/**
 *
 * @param k valor do log de baixo da divisão
 * @param x valor do log de cima da divisão
 * @return resultado do calculo
 */
float calcular_logaritmo(float k, float x);

/**
 *
 * @param x valor angular
 * @return resultado do calculo
 */
float calcular_seno(float x);

/**
 *
 * @param x valor angular
 * @return resultado do calculo
 */
float calcular_cosseno(float x);

/**
 *
 * @param x valor angular
 * @return resultado do calculo
 */
float calcular_tangente(float x);

/**
 *
 * @param valor parametro para verificacao
 * @return validade do valor inserido
 */
bool entrada_valida(float *valor);

/**
 *
 * @param valor valor para comparacao
 * @param limite_min limite maximo
 * @param limite_max limite minimo
 * @return validade do valor inserido
 */
bool verifica_limite(float valor, float limite_min, float limite_max);

/**
 *
 * @param graus valor em graus
 * @return valor em radianos
 */
float graus_para_radianos(float graus);

/**
 *
 * @param funcao string para exibição do resultado da funcao por ponteiro
 * @param resultado variavel que recebe o resultado da funcao resolvida para ser exibida
 */
void exibir_resultado(const char* funcao, float resultado);

#endif