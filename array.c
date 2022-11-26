#include <stdio.h>

void outArray(int *vet, int size);

int main() {
//	int vet[5] = {1, 4, 9, 16, 25};                Notação exclusiva para inicialização e atribuição simultânea
	int vet[5];
	
	// vet = {1, 2, 3, 4, 5};                      Não funciona
	
	vet[0] = 1;
	vet[1] = 2;
	vet[2] = 3;
	vet[3] = 4;
	vet[4] = 5;

	outArray(vet, 5);

	//////////////////////////////////////////////////////

//	int mat[2][2] = {{1, 2},
//	                 {0, 1}};

	int mat[2][2];

//	mat[0] = {1, 2};                               Não funciona
//	mat[1] = {0, 1};                               Não funciona

	mat[0][0] = 1;
	mat[0][1] = 2;

	mat[1][0] = 0;
	mat[1][1] = 1;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void outArray(int *vet, int size) {
	printf("vet = {");

	for (int i = 0; i < size; i++) {
		printf("%d", vet[i]);

		if (i < size - 1) {
			printf(", ");
		}
	}

	printf("}\n");
}
