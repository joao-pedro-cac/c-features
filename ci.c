#include <stdio.h>

int main() {
	for (int i = 32; i <= 126; i++) {
		printf("%d\t%c", i, i);

		if ((i - 1) % 5) {
			printf("\t\t\t");
		}
		else {
			printf("\n");
		}
	}

	printf("\n");

	return 0;
}
