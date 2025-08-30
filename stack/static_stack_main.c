#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

int main(){
    
    int stack[10];
    
    printf("size: %d\n", size());
    push(stack, 5);
    push(stack, 2);
    push(stack, 4);
    push(stack, 7);
    push(stack, 8);
    push(stack, 6);
    push(stack, 2);
    push(stack, 0);
    push(stack, 1);
    push(stack, 8);
    printf("size: %d\n", size());
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("pop: %d\n", pop(stack));
    printf("size: %d\n", size());
    
    return 0;
}