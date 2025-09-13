#include "linked_list.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

t_node * ls_init(){
    t_node * head = (t_node*)malloc(sizeof(t_node));
    head = NULL;
    return head;
}

t_node * ls_new_node(int value){
    t_node * node = (t_node*)malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return node;
}

void ls_push_front(t_node ** head, t_node * new_node){
    new_node->next = *head;
    *head = new_node;
}

void ls_push_back(t_node ** head, t_node * new_node){
    if (*head == NULL){
        *head = new_node;
        return;
    }

    t_node * current = *head;
    while (current != NULL) {
        if (current->next == NULL){
            current->next = new_node;
            break;
        }
        current = current->next;
    }
}

void ls_print(t_node * head){
    if (head == NULL){
        printf("error: list is empty.");
        return;
    }

    t_node * current = head;
    int i = 0;
    while (current != NULL) {
        printf("(%d)", current->value);
        if (current->next != NULL){
            printf("->");
        }
        current = current->next;
        i++;
    }
    printf("\n");
}

void ls_pop(t_node ** head){
    if (*head == NULL){
        printf("cannot pop linked list is empty.\n");
        return;
    }
    
    t_node * current = *head;
    t_node * aux = NULL;
    while (current != NULL) {
        if (current->next == NULL){
            free(current);
            if (*head == current){
                *head = NULL;
            }
            if (aux != NULL){
                aux->next = NULL;
            }
            break;
        }
        aux = current;
        current = current->next;
    }
}

void ls_reverse(t_node ** head){
    if (*head == NULL){
        printf("error: cannot invert empty list\n");
        return;
    }

    t_node * aux1 = *head;
    t_node * aux2 = NULL;
    t_node * aux3 = NULL;

    if ((*head)->next == NULL){
        return;
    }

    aux2 = (*head)->next;
    if ((*head)->next->next == NULL){
        *head = aux2;
        (*head)->next = aux1;
        aux1->next = NULL;
        return;
    }

    aux3 = (*head)->next->next;
    aux1->next = NULL;
    while(aux3 != NULL){
        aux2->next = aux1;
        aux1 = aux2;
        aux2 = aux3;
        aux3 = aux3->next;
        aux2->next = aux1;
    }

    *head = aux2;


}