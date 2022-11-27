/*
 * A memória ocupada por uma variável depende de seu tipo
 * A memória de estruturas compostas como vetores, matrizes, structs, ... são contínuas
 */

#include <stdio.h>

typedef unsigned char byte;
typedef unsigned int uint;

struct Student {
	char l1;
	char l2;
	byte age;
};

void s1(int vet[], uint size);

int main() {
	byte a = 1;
	byte b = 2;
	byte c = 3;

	byte nums[] = {1, 2, 3};

	struct Student me;

	me.l1 = 'A';
	me.l2 = 'B';
	me.age = 18;

	printf("a:      0x%X\n", &a);
	printf("b:      0x%X\n", &b);
	printf("c:      0x%X\n", &c);

	printf("\n");

	printf("1:      0x%X\n", &nums[0]);
	printf("2:      0x%X\n", &nums[1]);
	printf("3:      0x%X\n", &nums[2]);

	printf("\n");

	printf("me.l2:  0x%X\n", &nums[0]);
	printf("me.l1:  0x%X\n", &nums[1]);
	printf("me.age: 0x%X\n", &nums[2]);


	return 0;
}
