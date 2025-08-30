#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>

int head = -1;

void push(int stack[], int value){
    if (head >= 10 - 1) {
        printf("stack overflow.\n");
        exit(1);
    }
    stack[++head] = value;
}

int pop(int stack[]){
    if (head < 0){
        printf("stack underflow.\n");
        exit(1);
    }
    int value = stack[head];
    head--;
    return value;
}

int size(){
    return head + 1;
}