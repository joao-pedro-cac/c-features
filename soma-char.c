#include <stdio.h>

int main() {
	char a, b;
	
	printf("CHARS : ");
	scanf("%c %c", &a, &b);

	printf("%c + %c = %c\n", a, b, a + b);

	return 0;
}
