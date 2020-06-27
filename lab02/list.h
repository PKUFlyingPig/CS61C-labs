#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

void append_node(node** head_ptr, int new_data);
void reverse_list(node** head_ptr);
