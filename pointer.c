/*
 * Ponteiros são variáveis especiais que armazenam ENDEREÇO
 * Um pointeiro pode ter o valor NULL (ou zero), que é um endereço inválido
 * Podem ser copiados
 * Ex:
 *     int i = 10, *p = NULL, *q = NULL;
 *     p = &i;
 *     q = p;
 *     *q = 101;
 *
 * p e q apontam para o mesmo endereço
 *
 *
 *
 * Ao passar uma VARIÁVEL como parâmetro de função, copia-se apenas seu VALOR (similar a atribuição, a variável é inafetada)
 * Ao passar um PONTEIRO como parâmetro de função, copia-se seu endereço e a REFERÊNCIA à variável (a variável é afetada)
 *
 * Ponteiros podem apontar para uma posição qualquer de um vetor
 * O endereço da primeira posição de um vetor (&v[0]) pode ser abreviado pelo nome do vetor (v) ou pelo seu endereço (&v)
 * Ex:
 *     int *p;
 *     p = v;          OU          p = &v[0];          OU          p = &v;
 *
 * Isso significa que 'v' e '&v' retornam '&v[0]'
 *
 *
 *
 * Ao trabalhar com vetores, é possível fazer aritmética de ponteiros
 * Se 'p' é '&v[i]', então 'p + j' é '&v[i + j]' e 'p - j' é '&v[i - j]'
 * Isso acontece porque vetores são armazenados em posições consecutivas na memória do computador
 * OBS:
 *     - Cada elemento de um vetor 'int' ocupa 4 bytes
 *     - Ao somar 1 em um ponteiro 'int *', estamos "pulando" 4 bytes na memória
 *     - O compilador ajusta os detalhes internos de modo que a diferença de 'v[i]' a 'v[i + j]' seja 1 para qualquer tipo de dado
 *
 * As expressões '*(v + i)', 'v[0 + i]' e 'v[i]' são equivalentes
 * As expressões '(v + i)', '&v[0 + i]' e '&v[i]' são equivalentes
 *
 *
 *
 * É possível criar ponteiros para ponteiros (**p)
 * Para acessar o conteúdo de um ponteiro para ponteiro, utilizamos o operador **
 * Ex:
 *     char i;
 *     char *p = &i;
 *     char **q = &p;
 *
 *     **q = 'a';          OU          *p = 'a'          OU          i = 'a';
 *
 * O ponteiro 'q' armazena o endereço de 'p', que por sua vez, armazena o endereço de 'i'
 */

#include <stdio.h>

int troca(int *a, int *b);
int *max(int *a, int *b);

struct Data {
	int dia, mes, ano;
	int *d, *m, *a;                          // Structs podem conter ponteiros
};

int main() {
	struct Data hoje;

	hoje.dia = 27;
	hoje.mes = 11;
	hoje.ano = 2022;

	hoje.d = &hoje.dia;
	hoje.m = &hoje.mes;
	hoje.a = &hoje.ano;

	struct Data *h = &hoje;

	char i;
	char *p = NULL;                          // Em geral, inicializa-se um ponteiro com o valor NULL (com isso, podemos verificar se o endereço é válido)

//	*p = 30;                                 Não se pode atribuir valor para o endereço apontado pelo ponteiro sem ter um endereço válido

	if (p != NULL) {
		*p = 30;
	}

	i = 'A';
	p = &i;

	printf("VALUE:  %d\n", *p);              // printf("VALUE: %d\n", i);
	printf("ADDRESS: 0x%X\n\n", p);          // printf("ADDRESS: 0x%X\n", &i);
	
	// 'h -> dia' equivale a '(*h).dia'
	printf("DIA: %d\n", h -> dia);           //	printf("DIA: %d\n", hoje.dia);
	printf("MÊS: %d\n", h -> mes);           //	printf("MÊS: %d\n", hoje.mes);
	printf("ANO: %d\n\n", h -> ano);         //	printf("ANO: %d\n", hoje.ano);

	printf("&DIA: 0x%X\n", hoje.d);          // printf("&DIA: 0x%X\n", &hoje.dia);
	printf("&MÊS: 0x%X\n", hoje.m);          // printf("&MÊS: 0x%X\n", &hoje.mes);
	printf("&ANO: 0x%X\n\n", hoje.a);        // printf("&ANO: 0x%X\n", &hoje.ano);

	////////////////////////////////////////////////////////////////////////////////////////

	int var1 = 8;
	int var2 = 4;

	printf("ANTES:   var1 = %d\tvar2 = %d\n", var1, var2);

	troca(&var1, &var2);
	
	printf("DEPOIS:  var1 = %d\tvar2 = %d\n\n", var1, var2);

	printf("max(var1, var2) = %d\n\n", *max(&var1, &var2));

	int arr[5] = {1, 2, 3, 4, 5};
	int *arp = arr;                          // int *arp = &arr[0];

	printf("*arp\t\tADDRESS: 0x%X\n", &arp);

	// Usando aritmética de ponteiros, podemos fazer laços 'for' com ponteiros
	for (arp; arp < &arr[5]; arp++) {
		printf("ELEM: %d\t\tADDRESS: 0x%X\n", *arp, arp);
	}
	
	printf("\n");

	////////////////////////////////////////////////////////////////////////////////////////
	
	char val = 0;
	char *ptr1 = &val;
	char **ptr2 = &ptr1;                     // Ponteiro para ponteiro

	printf("val:  0x%X\n", ptr1);
	printf("ptr1: 0x%X\n", ptr2);
	printf("ptr2: 0x%X\n", &ptr2);

	return 0;
}

int troca(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

// Funções podem retornar ponteiros
int *max(int *a, int *b) {
	if (*a > *b) {
		return a;
	}
	else {
		return b;
	}
}
