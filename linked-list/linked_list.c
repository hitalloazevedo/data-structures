#include "linked_list.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

t_linked_list * ls_init(){
    t_linked_list * ptr = (t_linked_list*)malloc(sizeof(t_linked_list));
    ptr->size = 0;
    ptr->head = NULL;
    return ptr;
}

t_node * ls_new_node(int value){
    t_node * node = (t_node*)malloc(sizeof(t_node));
    node->value = (int*)malloc(sizeof(int));
    *node->value = value;
    node->next = NULL;
    return node;
}

void ls_push_front(t_linked_list * ls, t_node * new_node){
    new_node->next = ls->head;
    ls->head = new_node;
    ls->size++;
}

void ls_push_back(t_linked_list * ls, t_node * new_node){

    if (ls->head == NULL){
        ls->head = new_node;
        ls->size++;
        return;
    }

    t_node * current = ls->head;
    while (current != NULL) {
        if (current->next == NULL){
            current->next = new_node;
            break;
        }
        current = current->next;
    }
    ls->size++;
}

void ls_print(t_linked_list * ls){

    if (ls->size == 0){
        printf("linked list is empty.\n");
        return;
    }

    t_node * current = ls->head;
    int i = 0;
    while (current != NULL) {
        printf("%d", *current->value);
        if (i != ls->size - 1){
            printf("->");
        }
        current = current->next;
        i++;
    }
    printf("\n");
}

void ls_pop(t_linked_list * ls){
    
    if (ls->size == 0){
        printf("cannot pop linked list is empty.\n");
        return;
    }

    if (ls->size == 1){
        ls->head = NULL;
        ls->size = 0;
        return;
    }
    
    t_node * current = ls->head;
    int i = 0;
    while (i < ls->size) {
        if (i == ls->size - 2){
            free(current->next);
            current->next = NULL;
            break;
        }
        current = current->next;
        i++;
    }
    ls->size--;  
}

