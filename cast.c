/*
 * É possível fazer conversão entre tipos de dados ("type casting" ou "type-conversion")
 * A notação é: (NOME_TIPO) EXPRESSÃO
 * É possível também fazer conversão para ponteiros
 * Ex:
 *     char *p;
 *     p = (char*) malloc(1);
 *
 *
 *
 * Ponteiro do tipo 'void *' é aquele sem um tipo de dado associado a ele
 * Um ponteiro 'void *' pode receber qualquer endereço e ser convertido para qualquer tipo
 * Não é possível obter o valor da variável a partir de seu endereço usando um ponteiro 'void *' (não pode ser desreferenciado)
 * O padrão C não permite aritmética de ponteiros com ponteiros 'void *'
 *
 * VANTAGENS:
 *     - malloc() e calloc() retornam tipo 'void *', logo podem ser usadas para locar memória de qualquer tipo
 */

#include <stdio.h>

int main() {
	int a = 29, b = 7;

	float v1 = (float) a / b;
	float v2 = (float) (a / b);

	printf("(float) %d / %d   = %f\n", a, b, v1);
	printf("(float) (%d / %d) = %f\n\n", a, b, v2);

	///////////////////////////////////////////////////

	short int x = 73;
	char y = 'A';

	void *p = &x;                                  // Segura o endereço de um 'short int'
	p = &y;                     				   // Agora segura o endereço de um 'char'

//	printf("*p = %d\n", *p);                       Gera erro, pois 'void*' não pode ser desreferenciado
	printf("*p = %c\n", *(char *)p);               // Deve ser antes convertido para um tipo específico

	return 0;
}
