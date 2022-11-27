#include <stdio.h>

// TYPEDEF é um comando que fornece um apelido a um tipo
// Seguem regras de escopo (podem ser locais ou globais)

/*typedef
	struct S {
		int a;
		int b;
	}
S;*/

typedef struct S S;
typedef unsigned char byte;

struct S {
	int a;
	int b;
};

int main() {
	struct S structure;             // Similar a 'struct S structure;' 
	
	structure.a = 1;
	structure.b = 0;

	printf("a = %d\nb = %d\n", structure.a, structure.b);

	return 0;
}
