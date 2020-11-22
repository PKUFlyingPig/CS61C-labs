#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL) return 0;
    node *slow, *fast;
    slow = fast = head;
    while(1) {
    	fast = fast->next;
    	if (fast == NULL) return 0;
    	fast = fast->next;
    	if (fast == NULL) return 0;
    	slow = slow->next;
    	if (fast == slow) {
    		return 1;
    	} 
    }
    return 0;
}