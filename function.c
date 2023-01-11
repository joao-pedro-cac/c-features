/*
 * Ao passar uma variável para uma função como parâmetro, apenas seu valor é captado (a variável é inafetada)
 * No entanto, ao passar um vetor para uma função como parâmetro, sua referência é captada (o vetor é afetado)
 * Funções não podem retornar vetores
 * Caso uma matriz n-dimensional seja passada como parâmetro, apenas sua primeira dimensão pode ser vazia
 *     Ex:
 *     void printMat(int matriz[][3][3], int X, int Y, int Z);
 */

#include <stdio.h>

typedef unsigned int uint;

void vetPlus1(int vetor[], uint size);
void printArray(int array[], uint size);
void printPositive(uint v);

int main() {
	int arr[7] = {1, 2, 3, 4, 5, 6, 7};

	printArray(arr, 7);

	vetPlus1(arr, 7);

	printArray(arr, 7);

	for (uint i = 0; i < 10; i++)
		printPositive(i);

	return 0;
}

void printArray(int array[], uint size) {
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);

		if (i < size - 1) {
			printf(", ");
		}
	}

	printf("\n");
}

void vetPlus1(int vetor[], uint size) {
	for (int i = 0; i < size; i++) {
		vetor[i]++;
	}
}

void printPositive(uint v) {
	if (v == 0) return;                                         // Uma função do tipo 'void' retorna NADA, e com isso, é possível usar o comando 'return' sem valor de retorno
	printf("%u\n", v);
}
