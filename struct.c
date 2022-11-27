#include <stdio.h>

// STRUCT é um conjunto de variáveis que apontam para diferentes lugares na memória
// É a base para o POO (objeto é um "struct+")
// Não pode ter funções dentro
// Podem ser copiados

struct S {
	char nome[256];                     // Não podem receber valores na inicialização
	int idade;
};

void fill(char *a, char *b);

int main() {
	struct S estudante;
	fill(estudante.nome, "João Pedro");

	estudante.idade = 18;

	printf("%s, %d anos\n", estudante.nome, estudante.idade);

	return 0;
}

void fill(char *a, char *b) {
	int i;
	for (i = 0; b[i]; i++) {
		a[i] = b[i];
	}
	a[i] = '\0';
}
