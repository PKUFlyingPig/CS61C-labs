#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

int next_head(uint16_t *reg) {
	int x = 0;
	x ^= ((*reg)&1);
	x ^= (((*reg)>>2)&1);
	x ^= (((*reg)>>3)&1);
	x ^= (((*reg)>>5)&1);
	return x;
}
void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
	int head = next_head(reg);
	(*reg) >>= 1;
	(*reg) |= (head << 15);
}

