#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int * value;
    struct node * next;
} t_node;

typedef struct linked_list {
    t_node * head;
    int size;
} t_linked_list;

t_linked_list * ls_init();
t_node * ls_new_node(int value);
void ls_insert(t_linked_list * ls, t_node * new_node, int index);
void ls_push_back(t_linked_list * ls, t_node * new_node);
void ls_push_front(t_linked_list * ls, t_node * new_node);
void ls_pop(t_linked_list * ls);
void ls_remove(t_linked_list * ls, int index);
void ls_print(t_linked_list * ls);

#endif