/*
 * 'volatile' define uma variável suscetível a variações no tempo fora do controle do código
 * Previne o compilador de otimizar leituras e escritas subsequentes à variável volátil
 * Valores voláteis surgem principalmente em acesso ao hardware (I/O mapeada em memória) e threading
 * O compilador deve realizar toda leitura e escrita indicada no código, visto que o valor da variável pode mudar a qualquer momento
 * Acessos a variáveis voláteis não podem ser otimizadas, por exemplo, via registradores para armazenar valores intermediários
 */

#include <stdio.h>

void loopDefault();
void loopVolatile();


int defVal;
volatile int volVal;


int main() {
	int varDefault;
	volatile int varVolatile;

	varDefault = 5;
	varDefault = 5;			// o compilador pode retirar essa linha desnecessária, pois a variável vai manter o valor
	varDefault = 5;			// o compilador pode retirar essa linha desnecessária, pois a variável vai manter o valor

	varVolatile = 7;
	varVolatile = 7;		// o compilador NÃO pode retirar essa linha, pois a variável pode ter seu valor alterado
	varVolatile = 7;		// o compilador NÃO pode retirar essa linha, pois a variável pode ter seu valor alterado

	printf("Default variable: %d\n", varDefault);
	printf("Volatile variable: %d\n", varVolatile);

	return 0;
}


void loopDefault() {
	defVal = 0;
	while (defVal != 255);	// defVal nunca mudará, logo é um loop infinito -> equivalente a "while (true);"
}


void loopVolatile() {
	volVal = 0;
	while (defVal != 255);	// volVal pode mudar a qualquer momento por fatores externos ao programa, logo não é necessariamente um loop infinito
}
