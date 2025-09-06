#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

t_queue * q_init(){
    t_queue * queue = (t_queue*)malloc(sizeof(t_queue));
	t_node * new_node = (t_node*)malloc(sizeof(t_node));
	new_node = NULL;

	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void q_enqueue(t_queue * queue, int value, int priority){
	t_node * new_node = (t_node*)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
    new_node->previous = NULL;
    new_node->priority = priority;

	if (queue->size == 0){
		queue->head = new_node;
		queue->tail = new_node;
		queue->size++;
		return;
	}   

    t_node * current = queue->head;

    if (priority > current->priority){
        new_node->next = current;
        current->previous = new_node;
        queue->head = new_node;
        queue->size++;	
        return;
    }

    if (priority >= current->priority){
        while(current != NULL && priority >= current->priority){
            if (current->next != NULL){
                if (current->next->priority >= priority){
                    current = current->next; 
                } else {
                    break;
                }
            }
            if (current->next == NULL){
                break;
            }
        }


        new_node->previous = current;
        if (current->next != NULL){
            new_node->next = current->next;
            current->next->previous = new_node;
        }
        current->next = new_node;

        queue->size++;	
        return;
    }

    if (priority <= queue->tail->priority){
        new_node->previous = queue->tail;
        queue->tail->next = new_node;
        queue->tail = new_node;
        queue->size++;	
        return;
    } 
    
    if (priority > queue->tail->priority){
        current = queue->tail;
        while(current != NULL && priority >= current->priority){
            current = current->previous;
        }

        new_node->next = current->next;
        new_node->previous = current;
        current->next = new_node;
        new_node->next->previous = new_node;
        queue->size++;	
        return;
    }

}

int q_dequeue(t_queue * queue);
int q_size();
int q_seek_top(t_queue * queue); 