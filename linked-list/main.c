#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * next;
};
typedef struct node t_node;

void printList(t_node * head){
	t_node * current = head;
	while (current != NULL){
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int main(){
	
	t_node node1, node2, node3, node4;
	t_node * head;

	node1.value = 4;
	node2.value = 5;
	node3.value = 7;
	node4.value = 9;

	head = &node3;

	node3.next = &node1;
	node1.next = &node4;
	node4.next = &node2;
	node2.next = NULL;

	printList(head);

	return 0;
}
