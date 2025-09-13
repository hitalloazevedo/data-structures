#include "linked_list.h"
#include <stdio.h>

int main(){
	t_node * linked_list = ls_init();

	ls_push_front(&linked_list, ls_new_node(5));
	ls_push_back(&linked_list, ls_new_node(3));
	ls_push_back(&linked_list, ls_new_node(1));
	ls_push_back(&linked_list, ls_new_node(9));
	ls_push_back(&linked_list, ls_new_node(0));

	ls_print(linked_list);
	ls_reverse(&linked_list);
	ls_print(linked_list);
	// ls_push_back(&linked_list, ls_new_node(8));
	// ls_push_back(&linked_list, ls_new_node(5));
	// ls_print(linked_list);
	
	// ls_pop(&linked_list);
	// ls_print(linked_list);

	// ls_pop(&linked_list);
	// ls_print(linked_list);

	// ls_pop(&linked_list);
	// ls_print(linked_list);

	// ls_print(linked_list);

	// ls_push_back(&linked_list, ls_new_node(9));
	// 	ls_print(linked_list);
	// ls_push_front(&linked_list, ls_new_node(3));
	// 	ls_print(linked_list);
	// ls_push_front(&linked_list, ls_new_node(2));
	// 	ls_print(linked_list);


	return 0;
}
