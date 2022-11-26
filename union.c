#include <stdio.h>

// UNION é um conjunto de variáveis que apontam para o mesmo endereço da memória

union U {
	char chr[2];                                     // char[2] e short int para corrigir os erros causados pela diferença de # de bytes
	short int num;                                   // que ocorre por conta da ordenação Little Endian
};

int main() {
	union U var;

	var.chr[0] = 'A';                             // chr = 'A', num = 65 (código de 'A' na tabela ASCII)
	var.chr[1] = '\0';
	
	printf("CARACTERE: %s\nNÚMERO: %d\n", var.chr, var.num);

	return 0;
}

// %X imprime o número em HEX
