/*
 * É possível fazer conversão entre tipos de dados ("type casting" ou "type-conversion")
 * A notação é: (NOME_TIPO) EXPRESSÃO
 * É possível também fazer conversão para ponteiros
 * Ex:
 *     char *p;
 *     p = (char*) malloc(1);
 */

#include <stdio.h>

int main() {
	int a = 29, b = 7;

	float v1 = (float) a / b;
	float v2 = (float) (a / b);

	printf("(float) %d / %d   = %f\n", a, b, v1);
	printf("(float) (%d / %d) = %f\n", a, b, v2);

	return 0;
}
