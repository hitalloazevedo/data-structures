#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_h

typedef struct node {
	int value;
    int priority;
	struct node * next;
    struct node * previous;
} t_node;

typedef struct queue {
	t_node * head;
	t_node * tail;
	int size;
} t_queue;

t_queue * q_init();
void q_enqueue(t_queue * queue, int value, int priority);
int q_dequeue(t_queue * queue);
int q_size();
int q_seek_top(t_queue * queue);

#endif