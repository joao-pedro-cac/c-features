#include <stdio.h>

// Ponteiros são variáveis especiais que armazenam ENDEREÇO
// Um pointeiro pode ter o valor NULL (ou zero), que é um endereço inválido
// Podem ser copiados
// Ex:
//     int i = 10, *p = NULL, *q = NULL;
//     p = &i;
//     q = p;
//     *q = 101;
//
// p e q apontam para o mesmo endereço

int main() {
	char i;

	char *p = NULL;                          // Em geral, inicializa-se um ponteiro com o valor NULL (com isso, podemos verificar se o endereço é válido)

//	*p = 30;                                 Não se pode atribuir valor para o endereço apontado pelo ponteiro sem ter um endereço válido

	if (p != NULL) {
		*p = 30;
	}

	i = 'A';
	p = &i;

	printf("VALUE:  %d\n", *p);              // printf("VALUE: %d\n", i);
//	printf("ADDRESS: %c\n", p);              // printf("ADDRESS: %d\n", &i);

	return 0;
}
