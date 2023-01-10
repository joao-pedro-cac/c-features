#include <stdio.h>

// ENUM atribui apelidos para números, contando a partir do 0
enum semana {dom, seg, ter, qua, qui, sex, sab};

// dom = 0
// seg = 1
// ter = 2
// qua = 3
// qui = 4
// sex = 5
// sab = 6

enum boolAndOthers{T = 1, F = 0, E, G, H = 4, I};

// É possível alterar o valor dos números usando atribuições diretas

int main() {
	if (T) {
		printf("dom = %d\n", dom);
		printf("seg = %d\n", seg);
		printf("ter = %d\n", ter);
		printf("qua = %d\n", qua);
		printf("qui = %d\n", qui);
		printf("sex = %d\n", sex);
		printf("sab = %d\n", sab);

		printf("\nT = %d\n", T);
		printf("F = %d\n", F);
		printf("E = %d\n", E);
		printf("G = %d\n", G);
		printf("H = %d\n", H);
		printf("I = %d\n", I);

		printf("\nseg == T? %s\n", seg == T ? "SIM" : "NÃO");
	}

	return 0;
}
