/*
 * Declarações comuns alocam espaço na memória para variáveis definidas em tempo de compilação
 * A alocação é estática, acontece antes que o programa comece a ser executado
 * Em muitas aplicações, a quantidade de memória necessária só é conhecida durante a execução do programa
 * Uma solução é a alocação dinâmica de memória
 *
 *
 *
 * malloc():
 *     - Aloca um bloco consecutivo de bytes em memória e devolve o endereço desse bloco
 *     - Pertence à biblioteca 'stdlib.h'
 *     - O endereço retornado é do tipo genérico 'void *'
 *     - Retorna NULL caso aconteça algum erro (ex: se a memória do computador já estiver toda ocupada, a função não consegue alocar mais espaço)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *p;
	p = (char *) malloc(2);
	*p = 70;
	printf("%c\n", *p);
	return 0;
}
