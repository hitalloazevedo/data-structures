#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
	char name[30];
	int pages;
	struct book * next;
	struct book * prev;	
};

typedef struct book Book;

void addBook(Book * first, char * name, int pages);

Book * initList(char * name, int pages);

void printNode(Book * addr, char * name, int pages);

void printList(Book * first);

void removeBook(Book * head, char * name);


int main(){
	
	// adicionando o primeiro nó
	Book * first = initList("primeiro livro", 6);

	// adicionando nós de livros
	addBook(first, "teste", 5);
	addBook(first, "segundo livro", 76);
	addBook(first, "memorias postumas", 300);
	addBook(first, "revolução dos bichos", 256);
	addBook(first, "clean code", 500);

	printList(first);

	// remove o nó que contém um nome de "teste"
	removeBook(first, "teste");

	printf("\n\n\n");

	printList(first);

	return 0;
}


// functions definitions
void addBook(Book * first, char * name, int pages){
	Book * current = first;

	while (current->next != NULL){
		current = current->next;
	}

	current->next = (Book*)malloc(sizeof(Book));
	strcpy(current->next->name, name);
	current->next->pages = pages;
	current->next->next = NULL;
	current->next->prev = current;

}

Book * initList(char * name, int pages){
	Book * first = (Book*)malloc(sizeof(Book));
	strcpy(first->name, name);
	first->pages = pages;
	first->next = NULL;
	first->prev = NULL;

	return first;
}

void printNode(Book * addr, char * name, int pages){
	printf(
		"=========Node===========\ncurrent: %p\nnext: %p\nprev: %p\nbook name: %s\npages: %d\n========================\n", 
		addr, 
		addr->next, 
		addr->prev, 
		name, 
		pages
	);
}

void printList(Book * first){
	Book * current = first;

	while (current != NULL){
		printNode(current, current->name, current->pages);
		current = current->next;
	}
}

void removeBook(Book * head, char * name){
	Book * current = head;

	while (current->next != NULL){
		if (!strcmp(current->name, name)){
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current);
		}
		current = current->next;
	}
}