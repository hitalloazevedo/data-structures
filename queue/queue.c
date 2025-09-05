#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

t_queue * q_init(){
	t_queue * queue = (t_queue*)malloc(sizeof(t_queue));
	t_node * new_node = (t_node*)malloc(sizeof(t_node));
	new_node->next = NULL;
	new_node = NULL;

	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void q_enqueue(t_queue * queue, int value){
	t_node * new_node = (t_node*)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;

	if (queue->size == 0){
		queue->head = new_node;
		queue->tail = new_node;
		queue->size++;
		return;
	}

	queue->tail->next = new_node;
	queue->tail = new_node;
	queue->size++;	
}

int q_dequeue(t_queue * queue){
	t_node * current = queue->head;
	if (current == NULL){
		printf("queue is empty.\n");
		exit(1);
	}
	int value = current->value;
	queue->head = current->next;
	free(current);
	queue->size--;
	return value;
}

int q_size(t_queue * queue){
	return queue->size;
}

int q_seek_top(t_queue * queue){
	if (queue->head == NULL){
		perror("cannot get the top element, the queue is empty");
	}
	return queue->head->value;
}