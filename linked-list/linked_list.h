#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int value;
    struct node * next;
} t_node;

t_node * ls_init();
t_node * ls_new_node(int value);
// void ls_insert(t_node ** head, t_node * new_node, int index);
void ls_push_back(t_node ** head, t_node * new_node);
void ls_push_front(t_node ** head, t_node * new_node);
void ls_pop(t_node ** head);
// void ls_remove(t_node * head, int index);
void ls_print(t_node * head);
void ls_reverse(t_node ** head);

#endif