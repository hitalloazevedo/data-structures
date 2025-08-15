#include "linked_list.h"

int main(){
	
	t_linked_list * linked_list = ls_init();

	ls_push_front(linked_list, ls_new_node(5));
	ls_push_back(linked_list, ls_new_node(3));
	ls_push_back(linked_list, ls_new_node(8));
	ls_push_back(linked_list, ls_new_node(5));

	ls_pop(linked_list);
	ls_pop(linked_list);
	ls_pop(linked_list);
	ls_pop(linked_list);

	ls_push_back(linked_list, ls_new_node(9));
	ls_push_front(linked_list, ls_new_node(3));
	ls_push_front(linked_list, ls_new_node(2));

	ls_print(linked_list);

	return 0;
}
