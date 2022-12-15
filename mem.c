/*
 * Declarações comuns alocam espaço na memória para variáveis definidas em tempo de compilação
 * A alocação é estática, acontece antes que o programa comece a ser executado
 * Em muitas aplicações, a quantidade de memória necessária só é conhecida durante a execução do programa
 * Uma solução é a alocação dinâmica de memória
 *
 *
 * A memória do computador durante a execução de um programa é organizada em 4 segmentos:
 *     - CÓDIGO EXECUTÁVEL: Contém o código binário do programa
 *     - DADOS ESTÁTICOS: Contém variáveis globais e estáticas que existem durante toda a execução do programa
 *     - PILHA (STACK): Contém as variáveis locais que são criadas na execução de uma função e depois são removidas da pilha ao término da função
 *     - HEAP: Contém as variáveis criadas por alocação dinâmica
 *
 *
 * A alocação dinâmica ocorre via funções pertencentes à biblioteca 'stdlib.h': malloc(), calloc(), realloc() e free()
 *
 *
 * malloc(SIZE):
 *     - "Memory allocation"
 *     - Aloca um bloco de SIZE bytes na memória e devolve o endereço desse bloco
 *     - O endereço retornado é do tipo genérico 'void *'
 *     - Não inicializa o bloco, portanto o valor inicial é lixo
 *     - Retorna um ponteiro NULL caso aconteça algum erro (ex: se a memória do computador já estiver toda ocupada, a função não consegue alocar mais espaço)
 *
 *
 * calloc(SIZE, TYPE):
 *     - "Contiguous allocation"
 *     - Aloca SIZE blocos contíguos de sizeof(TYPE) bytes na memória e devolve o endereço do primeiro bloco
 *     - O endereço retornado é do tipo 'void *'
 *     - Muito similar a malloc()
 *     - Inicializa cada bloco com o valor padrão de 0
 *     - Retorna um ponteiro NULL caso aconteça algum erro (ex: se a memória do computador já estiver toda ocupada, a função não consegue alocar mais espaço)
 *
 * realloc(POINTER, NEW_SIZE):
 *     - "Re-allocation"
 *     - Muda dinamicamente a memória de POINTER previamente alocada para um bloco de NEW_SIZE bytes
 *     - O endereço retornado é do tipo 'void *'
 *     - Espaços antigos conservam o valor, enquanto que novos espaços alocados têm valor inicial de lixo
 *     - Retorna um ponteiro NULL caso aconteça algum erro (ex: se a memória do computador já estiver toda ocupada, a função não consegue alocar mais espaço)
 *
 * free(POINTER):
 *     - Desaloca a memória dinâmica alocada para POINTER
 *     - Ao contrário da Pilha, variáveis alocadas dinamicamente não são desalocadas após o fim do programa (motivo de usar free)
 *     - Sistemas operacionais modernos conseguem lidar com programas de alocação dinâmica e que não usam free
 *     - No entanto, sistemas operacionais antigos e rudimentares não conseguem, e por isso, pode gerar problemas
 *     - A constante execução de programas com alocação dinâmica e sem free consome gradualmente a memória do Heap
 *     - Caso o SO seja antigo, tal problema não é tratado, e por isso, a memória vai sendo ocupada
 *     - Ao atingir o limite do Heap, a alocação dinâmica começa a usar outros segmentos da memória
 *     - Isso pode gerar problemas, como menos memória disponível para a inicialização de variáveis na Pilha
 *     - Após ocorrido, o problema é solucionado reiniciando o sistema computacional
 * 
 * 
 * --------------------------------------------------------------------------------------
 * |                malloc()               |                  calloc()                  |
 * --------------------------------------------------------------------------------------
 * | Um bloco de memória para uma variável | Vários blocos de memória para uma variável |
 * --------------------------------------------------------------------------------------
 * |             Um argumento              |               Dois argumentos              |
 * --------------------------------------------------------------------------------------
 * |              Mais rápido              |                Mais devagar                |
 * --------------------------------------------------------------------------------------
 * |        Alta eficiência de tempo       |          Baixa eficiência de tempo         |
 * --------------------------------------------------------------------------------------
 * |       Usado para alocação única       |        Usado para alocação contígua        |
 * --------------------------------------------------------------------------------------
 *
 *
 * A alocação de memória de um vetor possui um limite máximo
 * Ao digitar um número muito grande (ex: 4000000), o programa é encerrado com "segmentation fault"
 * Isso se deve ao fato de que o SO limita o que pode ser alocado na Pilha durante a execução de uma função
 * Esse limite não existe para o Heap (com exeção do limite de memória do computador)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *p;
	p = (char *) malloc(3);

	p[0] = 'A';
	p[1] = 'B';

	printf("%s\n", p);
	printf("0x%X\n", p);

	free(p);

	return 0;
}
