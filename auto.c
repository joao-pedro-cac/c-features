/*
 * CLASSE DE ARMAZENAMENTO: auto
 * TEMPO DE VIDA: bloco (stack)
 * ESCOPO: bloco
 * VALOR PADRÃO DE INICIALIZAÇÃO: não-inicializada (a variável definida começa com lixo)
 *
 * 'auto' é uma palavra-chave utilizada para criar variáveis locais
 * Por padrão, toda variável local é uma variável automática
 * Em razão disso, 'auto' é redundante e raramente utilizado
 */

#include <stdio.h>

int main () {
	// linhas de código equivalentes
	char var1[1000];
	auto char var2[1000];

	// var1
	printf("\'char\' ARRAY:\n");
	for (int i = 0; i < 1000; i++) printf("%c", var1[i]);
	printf("\n\n");

	// var2
	printf("\'auto char\' ARRAY:\n");
	for (int i = 0; i < 1000; i++) printf("%c", var2[i]);
	printf("\n");

	return 0;
}
