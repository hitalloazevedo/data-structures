#include "queue.h"
#include <stdio.h>

void printQueue(t_queue * queue){
    t_node* current = queue->head;
    int c = 0;
    while (current != NULL){
        printf("%d - (%p) -> (%p)\n", c, current, current->next);
        current = current->next;
        c++;
    }
}

int main(){

    t_queue * queue = q_init();
    q_enqueue(queue, 1);
    q_enqueue(queue, 2);
    printf("size: %d\n", q_size(queue));
    q_enqueue(queue, 3);
    q_enqueue(queue, 6);
    printf("top: %d\n", q_seek_top(queue));

    printf("size: %d\n", q_size(queue));

    printf("dequeue: %d\n", q_dequeue(queue));
    printf("dequeue: %d\n", q_dequeue(queue));
    printf("top: %d\n", q_seek_top(queue));
    printf("size: %d\n", q_size(queue));
    printf("dequeue: %d\n", q_dequeue(queue));
    printf("dequeue: %d\n", q_dequeue(queue));
    printf("size: %d\n", q_size(queue));
    printf("dequeue: %d\n", q_dequeue(queue));
    return 0;
}