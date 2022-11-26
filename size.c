#include <stdio.h>

int main() {
	printf("char\t\t%lu bytes\n", sizeof(char));
	printf("int\t\t%lu bytes\n", sizeof(int));
	printf("short\t\t%lu bytes\n", sizeof(short));
	printf("long\t\t%lu bytes\n", sizeof(long));
	printf("long long\t%lu bytes\n", sizeof(long long));
	printf("float\t\t%lu bytes\n", sizeof(float));
	printf("double\t\t%lu bytes\n", sizeof(double));
	printf("long double\t%lu bytes\n", sizeof(long double));

	return 0;
}
