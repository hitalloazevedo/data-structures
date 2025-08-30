#include "dynamic_stack.h"
#include <stdio.h>

int main(){
    t_node * head = st_init();

    st_push(&head, 5);
    st_push(&head, 9);
    st_push(&head, 23);
    st_push(&head, 90);
    
    printf("stack size: %d\n", st_size(head));
    printf("pop value: %d\n", st_pop(&head));
    printf("stack size: %d\n", st_size(head));
    printf("pop value: %d\n", st_pop(&head));
    printf("pop value: %d\n", st_pop(&head));
    printf("pop value: %d\n", st_pop(&head));
    printf("stack size: %d\n", st_size(head));


    return 0;
}