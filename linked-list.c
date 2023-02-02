/*
 * Listas ligadas (ou encadeadas) são listas formadas por 'structs', denominados nós ou nódulos, alocados dinamicamente
 * Cada nó possui informações próprias e um ponteiro que aponta para o próximo nó
 * O primeiro aponta para o segundo, o segundo para o terceiro, etc.
 * O último nó aponta para NULL
 *
 *
 * A lista não pode ser acessada diretamente
 * Os nós estão espalhados pela memória heap
 * Amplamente utilizadas na implementação de estruturas de dados como filas, pilhas, grafos, árvores, etc.
 *
 *
 * Existem diversas variações, como listas circulares, listas duplamente ligadas, listas com nó cabeça, listas com nó sentinela, etc.
 *
 * LISTAS CIRCULARES: o último
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAM sizeof(Node)


typedef unsigned int uint;
typedef int Type;
typedef struct Node Node;


void printList(Node *L);
bool isEmpty(Node *L);
uint size(Node *L);
long getIndex(Node *L, Type elem);
uint count(Node *L, Type elem);

void insertBegin(Node **p, Type v);
void insertEnd(Node **p, Type v);
void insert(Node **p, Type v, uint index);

Type deleteBegin(Node **p);
Type deleteEnd(Node **p);
Type delete(Node **p, uint index);
void clear(Node **p);


struct Node {
	Type info;
	Node *next;
};


int main() {
	Node *L = NULL;                                           // Ponteiro de acesso à lista
	Type del;                                                 // Elemento a ser removido

	Type elems[] = {521, 0, 23, -1, 5, 3, -41, 99, 101};
	uint sizeElems = sizeof(elems) / sizeof(Type);


	printf("ESTADO: %s\n\n", isEmpty(L) ? "VAZIA" : "OK");    // Estado inicial

	// Inserção na lista
	insertBegin(&L, 0);
	insertBegin(&L, 3);
	insertBegin(&L, 2);
	insertEnd(&L, 0);
	insertEnd(&L, 1);
	insertEnd(&L, -41);
	insertBegin(&L, 18);
	insertBegin(&L, 512);
	insertEnd(&L, 99);
	insert(&L, -1, 7);

	printf("LISTA : ");                                       // Lista preenchida
	printList(L);

	printf("Tamanho : %u\n\n", size(L));                      // Tamanho da lista



	printf("----------------------------------------------------\n\n");



	for (uint i = 0; i < sizeElems; i++) {
		uint index = getIndex(L, elems[i]);
		printf("%-5díndice %-2d %s\n", elems[i], index, index == -1 ? "(inexistente)" : "(encontrado)");
	}

	printf("\nESTADO: %s\n\n", isEmpty(L) ? "VAZIA" : "OK");  // Estado pós-inserção



	printf("----------------------------------------------------\n\n");



	// Remoção na lista
	printf("DELETANDO INÍCIO:  ");
	del = deleteBegin(&L);
	printList(L);
	printf("Elemento deletado: %d\n\n", del);

	printf("DELETANDO FIM:     ");
	del = deleteEnd(&L);
	printList(L);
	printf("Elemento deletado: %d\n\n", del);

	printf("DELETANDO ÍND 2:   ");
	del = delete(&L, 2);
	printList(L);
	printf("Elemento deletado: %d\n\n", del);

	printf("DELETANDO ÍND 0:   ");
	del = delete(&L, 0);
	printList(L);
	printf("Elemento deletado: %d\n\n", del);

	printf("DELETANDO ÍND 5:   ");
	del = delete(&L, 5);
	printList(L);
	printf("Elemento deletado: %d\n\n", del);

	printf("ESTADO: %s\n\n", isEmpty(L) ? "VAZIA" : "OK");    // Estado pós-remoção



	printf("----------------------------------------------------\n\n");



	printf("> Limpando lista...\n\n");

	clear(&L);                                                // Limpeza da lista

	printf("ESTADO: %s\n\n", isEmpty(L) ? "VAZIA" : "OK");    // Estado pós-limpeza (final)
	printf("LISTA : ");
	printList(L);

	return 0;
}



//////////////////////////
// Comandos Miscelâneos //
//////////////////////////



// Impressão dos itens
void printList(Node *L) {
	Node *aux = L;

	while (aux) {
		printf("%d", aux -> info);
		if (aux -> next) printf(", ");
		aux = aux -> next;
	}
	printf("\n");
}

// Verificação de vacuidade
bool isEmpty(Node *L) {
	return L ? false : true;
}

// Tamanho da lista
uint size(Node *L) {
	Node *aux = L;
	uint c = 0;

	while (aux) {
		aux = aux -> next;
		c++;
	}

	return c;
}

// Índice da primeira ocorrência de um elemento
long getIndex(Node *L, Type elem) {
	Node *aux = L;

	for (long i = 0; i < size(L); i++) {
		if (aux -> info == elem) return i;
		aux = aux -> next;
	}
	return -1;
}

// Número de ocorrências
uint count(Node *L, Type elem) {
	uint c = 0;
	Node *aux = L;

	while (aux) {
		if (aux -> info == elem) c++;
		aux = aux -> next;
	}

	return c;
}



//////////////////////////
// Comandos de inserção //
//////////////////////////



// Inserir no início
void insertBegin(Node **p, Type v) {
	Node *item = (Node *) malloc(TAM);

	item -> info = v;
	item -> next = *p;
	*p = item;
}


// Inserir no fim
void insertEnd(Node **p, Type v) {
	Node *item = (Node *) malloc(TAM);

	item -> info = v;
	item -> next = NULL;

	if (isEmpty(*p)) {
		*p = item;
	}
	else {
		Node *aux = *p;
		while (aux -> next) aux = aux -> next;
		aux -> next = item;
	}
}


// Inserir por índice
void insert(Node **p, Type v, uint index) {
	if (index > size(*p)) return;

	if (!index) insertBegin(p, v);
	else if (index == size(*p)) insertEnd(p, v);
	else {
		Node *aux = *p;

		Node *item = (Node *) malloc(TAM);
		item -> info = v;

		for (uint i = 0; i < index - 1; i++) aux = aux -> next;

		item -> next = aux -> next;
		aux -> next = item;
	}
}



/////////////////////////
// Comandos de remoção //
/////////////////////////



// Remover no início
Type deleteBegin(Node **p) {
	if (!isEmpty(*p)) {
		Node *aux = *p;
		*p = (*p) -> next;

		Type v = aux -> info;
		free(aux);

		return v;
	}
}

// Remover no fim
Type deleteEnd(Node **p) {
	if (!isEmpty(*p)) {
		Node *aux = *p;
		Node *del = *p;
		Type v;

		if (aux -> next == NULL) *p = NULL;
		else {
			while (aux -> next -> next) aux = aux -> next;
			del = aux -> next;
			aux -> next = NULL;
		}

		v = del -> info;
		free(del);

		return v;
	}
}

// Remover por índice
Type delete(Node **p, uint index) {
	if (index <= size(*p)) {
		Type v;

		if (!index) v = deleteBegin(p);
		else if (index == size(*p)) v = deleteEnd(p);
		else {
			Node *aux = *p;
			Node *del;

			for (uint i = 0; i < index - 1; i++) aux = aux -> next;

			del = aux -> next;
			aux -> next = del -> next;

			v = del -> info;
			free(del);
		}

		return v;
	}
}

// Apagar toda a lista
void clear(Node **p) {
	while (!isEmpty(*p)) deleteBegin(p);
}
