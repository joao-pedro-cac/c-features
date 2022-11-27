#include <stdio.h>

// Macros são trechos de códigos que são substituídos durante o pré-processamento (antes da compilação)
//
// Vantagens:
//     Podem tornar o código mais legível
//     Evita a leitura de dados da memória
//     Evita procedimentos que ocorrem ao chamarmos uma função -> execução de código mais rápida
//     Parâmetros são genéricos (não possuem tipos) -> aceitam int, float, double, etc.
//     Constantes globais
//
// Desvantagens:
//     Não obedecem regras de escopo
//     Mais memória comparado a funções
//     Podem ser difíceis de usar

#define PI 3.141592
#define SOMA(x, y) x + y
#define soma(x, y) (x + y)
#define printar1 printf("abcdef\n");
#define printar2 printf("123456\n")
#define cube(x) (x * x * x)
#define retornar return 3;

int ret();

int main() {
//	float PI = 2.0;                       Gera erro
	int a = 10;
	int b = 11;

	printf("PI = %f\n", PI);

	printf("%d\n\n", SOMA(a, b));         // SOMA(a,b) = SOMA(a, b) = SOMA(  a , b ) = ...

	printar1                              // Não tem ; porque sua definição já tem ;
	printar2;                             // Tem ; porque sua definição não tem ;

	int soma1 = 5 * SOMA(a, b);           // 5 * a + b
	int soma2 = 5 * (SOMA(a, b));         // 5 * (a + b)
 
	printf("\nsoma1 = %d\n", soma1);
	printf("soma2 = %d\n", soma2);

	int soma3 = 5 * soma(a, b);           // 5 * (a + b)
	int soma4 = 5 * (soma(a, b));         // 5 * ((a + b))
 
	printf("\nsoma3 = %d\n", soma3);
	printf("soma4 = %d\n", soma4);

	printf("\na³ = %d\n\n", cube(a));

	printf("ret() -> %d\n", ret());

	return 0;
}

int ret() {
	retornar
}
