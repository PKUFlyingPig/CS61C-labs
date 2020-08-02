
#ifndef COMPUTE_DOTP_H
#define COMPUTE_DOTP_H

#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libbmp/libbmp.h"

#define REPEAT 100
#define BUF_SIZE 8192

char *compute_dotp(int);
char *image_proc(const char*);

#endif