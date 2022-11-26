#include <stdio.h>

int main() {
	char str[60];

	printf("STRING LIXO: ");

	for (int i = 0; i < 60; i++) {
		printf("%c", str[i]);
	}

	printf("\n\nNUMS: ");

	for (int i = 0; i < 60; i++) {
		printf("%d ", str[i], str[i]);
	}

	printf("\n");

	return 0;
}
