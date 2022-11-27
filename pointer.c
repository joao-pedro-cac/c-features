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
 */

#include <stdio.h>

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
	printf("MÊS: %d\n", h -> mes);           //	printf("DIA: %d\n", hoje.mes);
	printf("ANO: %d\n\n", h -> ano);         //	printf("DIA: %d\n", hoje.ano);

	printf("&DIA: 0x%X\n", hoje.d);          // printf("&DIA: 0x%X\n", &hoje.dia);
	printf("&MÊS: 0x%X\n", hoje.m);          // printf("&MÊS: 0x%X\n", &hoje.mes);
	printf("&ANO: 0x%X\n", hoje.a);          // printf("&ANO: 0x%X\n", &hoje.ano);

	return 0;
}
