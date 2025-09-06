#include "priority_queue.h"
#include <stdio.h>

void printQueue(t_queue * queue){
    t_node* current = queue->head;
    int c = 0;
    while (current != NULL){
        printf("(v: %d, p: %d)\n", current->value, current->priority);
        current = current->next;
        c++;
    }
}

int main(){

    t_queue * queue = q_init();
    q_enqueue(queue, 1, 1);
    q_enqueue(queue, 2, 1);
    q_enqueue(queue, 2, 0);
    q_enqueue(queue, 7, 1);
    q_enqueue(queue, 7, 3);
    q_enqueue(queue, 7, 2);
    q_enqueue(queue, 7, 6);
    q_enqueue(queue, 7, -5);
    q_enqueue(queue, 7, 4);
    printQueue(queue);

    return 0;
}