#include "dynamic_stack.h"
#include <stdlib.h>
#include <stdio.h>

t_node * st_init(){
    t_node * head = (t_node*)malloc(sizeof(t_node));
    head = NULL;
    return head;
}

int st_pop(t_node ** head){
    if (*head == NULL){
        printf("stack underflow\n");
        exit(1);
    }
    t_node * current = *head;
    *head = current->next;
    int value = current->value;
    free(current);
    return value;
}

int st_top(t_node * head){
    return head->value;
}

void st_push(t_node ** head, int value){
    if (*head == NULL){
        *head = (t_node*)malloc(sizeof(t_node));
        (*head)->next = NULL;
        (*head)->value = value;
        return;
    }
    t_node * new_node = (t_node*)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

int st_size(t_node * head){
    int size = 0;
    t_node * current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;
}