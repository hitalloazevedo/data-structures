typedef struct node {
    int value;
    struct node * next;
} t_node;

t_node * st_init();
int st_pop(t_node ** head);
int st_top(t_node * head);
void st_push(t_node ** head, int value);
int st_size(t_node * head);