/*
 * CLASSE DE ARMAZENAMENTO: register
 * TEMPO DE VIDA: bloco (stack ou registrador da CPU)
 * ESCOPO: bloco
 * VALOR PADRÃO DE INICIALIZAÇÃO: não-inicializada (a variável definida começa com lixo)
 *
 * 'register' é uma palavra-chave utilizada na declaração de variáveis
 * Sua função é SUGERIR ao compilador que ele armazene a variável em questão em um registrador ao invés da memória
 * O compilador então decide se é possível colocar a variável em um registrador
 *
 * Atualmente é desnecessária, pois compiladores modernos otimizam bem
 * Variáveis podem ser colocadas em registradores mesmo que não haja o uso da palavra-chave
 * Pode haver alguma significância no desenvolvimento de sistemas embarcados
 *
 * Impede o uso do operador de endereço (&), pois o operador busca o endereço na memória
 * Como a variável não está na memória, o operador não funciona, gerando um aviso ou erro (depende do compilador)
 */

#include <stdio.h>
#include <time.h>

#define N 5E7						// número de operações
#define BYTE_MAX 255

typedef unsigned char byte;

void errorMessage();

int main () {
	byte var = 0;					// variável armazenada em qualquer lugar (memória, registrador, etc.)
	register byte reg = 0;			// variável PREFERIVELMENTE armazenada em registrador

	clock_t before, after;			// contadores de clock
	float msDefault, msRegister;	// millisegundos


	// printf("Address (var): %p\n", &var);			// funciona
	// printf("Address (reg): %p\n", &reg);			// não funciona (gera erro/aviso)



	// variável padrão
	before = clock();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < BYTE_MAX; j++) var++;	// incremento até o valor máximo (255)
		for (int j = 0; j < BYTE_MAX; j++) var--;	// decremento até o valor mínimo (0)
	}
	after = clock();

	if (before == (clock_t)(-1) || after == (clock_t)(-1)) {	// verificação de erro
		errorMessage();
		return 1;
	}
	msDefault = (after - before) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed for default variable: %.2f ms\n", msDefault);



	// variável alterada
	before = clock();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < BYTE_MAX; j++) reg++;	// incremento até o valor máximo (255)
		for (int j = 0; j < BYTE_MAX; j++) reg--;	// decremento até o valor mínimo (0)
	}
	after = clock();

	if (before == (clock_t)(-1) || after == (clock_t)(-1)) {	// verificação de erro
		errorMessage();
		return 1;
	}
	msRegister = (after - before) * 1000.0 / CLOCKS_PER_SEC;
	printf("Time elapsed for register variable: %.2f ms\n", msRegister);



	// ganho de desempenho
	printf("Overall speedup: %.3f\n", msDefault / msRegister);

	return 0;
}

void errorMessage() {
	printf("Clock information unavailable in your system. Shutting down program.\n");
}
