#include <stdio.h>

int main() {
	char txt[10];
	int i = 0;

	printf("TEXTO: ");

	while (i < 10) {
		scanf("%c", &txt[i]);                           // scanf() NÃO pula linha; o que pula linha é o ENTER que pressiona-se na entrada

		if (txt[i] == '\n') {
			do {
				txt[i++] = '\0';
			} while (i < 10);

			break;
		}

		i++;

		if (i >= 10) {
			break;
		}
	}

	printf("Você escreveu:\t%s\n", txt);                // %s imprime a string até aparecer \0; se houver lixo logo após a string desejada, o lixo vai ser impresso até aparecer algum \0
	
	printf("Em números:\t");

	for (int i = 0; i < 10; i++) {
		printf("%d\t", txt[i]);
	}

	printf("\n");

	return 0;
}
