#include <stdio.h>
#include "list.h"

unsigned int list_size(node**);

/* Return the size of the linked list. */
unsigned int list_size (node** head_ptr) {
	if (head_ptr == NULL)
		return 0;
	int size = 0;
	node* curr = *head_ptr;
	while (curr != NULL) {
		++size;
		curr = curr->next;
	}
	return size;
}

int main() {
	//DO NOT EDIT ANY OF THE FOLLOWING CODE
	printf("*** NOTE: If you see (nil) as a node's next attribute in the output, don't worry. That's the same as NULL *** \n\n");
	node** head_ptr = malloc(sizeof(node*));
	*head_ptr = malloc(sizeof(node));
	(*head_ptr)->val = 1;
	(*head_ptr)->next = NULL;
	node* last_node = *head_ptr;
	append_node	(head_ptr, 2);
	last_node = (*head_ptr)->next;

	int is_correct = list_size(head_ptr) == 2 && last_node != NULL && last_node->val == 2 &&
						last_node->next == NULL;
	printf("Appending a node to a list of size 1. Size of list is %u and it should be 2, the new node's val and next "
		   "attributes are %i and %p and they should be 2 and NULL, respectively\n", list_size(head_ptr),
		   last_node->val, last_node->next);

	append_node	(head_ptr, 3);
	last_node = (last_node)->next;

	is_correct = list_size(head_ptr) == 3 && last_node != NULL && last_node->val == 3 &&
						last_node->next == NULL;
	printf("Appending a node to a list of size 2. Size of list is %u and it should be 3, the new node's val and next "
		   "attributes are %i and %p and they should be 3 and NULL, respectively\n", list_size(head_ptr),
		   last_node->val, last_node->next);

	int i;
	for (i = 4; i <= 10; i++) {
		append_node(head_ptr, i);
	}

	reverse_list(head_ptr);
	is_correct = is_correct && list_size(head_ptr) == 10;
	node* head = *head_ptr;
	node* curr = head;

	i = 1;
	printf("Reversing the linked list...\n Old list is 1 2 3 4 5 6 7 8 9 10 \n New list is ");

	while (curr != NULL) {
		is_correct = is_correct && curr->val == (11-i);
		printf("%i ", (11-i));
		if (i == 10) {
			is_correct = is_correct && curr->next == NULL;
		} else {
			is_correct = is_correct && curr->next != NULL;
		}
		curr = curr->next;
		++i;
	}

	printf("\nSize of list is %u and it should be 10, the new head's val "
		   "attribute is %i and it should be 10\n", list_size(head_ptr), head->val);

	printf("\nNow let's perform some operations on a new list that's originally empty...\n");

	node** smallList = malloc(sizeof(node*));
	*smallList = NULL;
	reverse_list(smallList);
	is_correct = is_correct && list_size(smallList) == 0 && *smallList == NULL;
	printf("Reversing an empty list. Size of list is %u and it should still be 0, the head is %p and "
			"it should be NULL\n", list_size(smallList), *smallList);

	append_node(smallList, 80);
	is_correct = is_correct && list_size(smallList) == 1 && (*smallList)->val == 80 && (*smallList)->next == NULL;
	printf("Appending a node with val 80 to the empty list. Size of list is %u and it should be 1, the head's "
		    "val and next attributes are %i and %p and they should be 80 and NULL\n", list_size(smallList),
		    (*smallList)->val, (*smallList)->next);

	reverse_list(smallList);
	is_correct = is_correct && list_size(smallList) == 1 && (*smallList)->val == 80 && (*smallList)->next == NULL;
	printf("Reversing the list. Size of list is %u and it should be 1, the head's "
		    "val and next attributes are %i and %p and they should be 80 and NULL\n", list_size(smallList),
		    (*smallList)->val, (*smallList)->next);

	if (is_correct) {
		printf("\n\n--------------TEST PASSED----------------");
	} else{
		printf("\n\n--------------TEST FAILED----------------");
	}

	return !is_correct;
}
