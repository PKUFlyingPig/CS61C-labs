#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10000000
#define REPEAT     100


void v_add_naive(double* x, double* y, double* z) {
	#pragma omp parallel
	{
		for(int i=0; i<ARRAY_SIZE; i++)
			z[i] = x[i] + y[i];
	}
}

// Edit this function (Method 1) 
void v_add_optimized_adjacent(double* x, double* y, double* z) {
     #pragma omp parallel
	{
		for(int i=0; i<ARRAY_SIZE; i++)
			z[i] = x[i] + y[i];
	}
}

// Edit this function (Method 2) 
void v_add_optimized_chunks(double* x, double* y, double* z) {
          #pragma omp parallel
	{
		for(int i=0; i<ARRAY_SIZE; i++)
			z[i] = x[i] + y[i];
	}
}

double* gen_array(int n) {
	double* array = (double*) malloc(n*sizeof(double));
	for(int i=0; i<n; i++)
		array[i] = drand48();
	return array;
}

// Double check if it is correct
int verify(double* x, double* y, void(*funct)(double *x, double *y, double *z)) {
	double *z_v_add = (double*) malloc(ARRAY_SIZE*sizeof(double));
	double *z_oracle = (double*) malloc(ARRAY_SIZE*sizeof(double));
	(*funct)(x, y, z_v_add);
	for(int i=0; i<ARRAY_SIZE; i++)
		z_oracle[i] = x[i] + y[i];
	for(int i=0; i<ARRAY_SIZE; i++)
		if(z_oracle[i] != z_v_add[i])
			return 0;	
	return 1;
}


int main() {
	// Generate input vectors and destination vector
	double *x = gen_array(ARRAY_SIZE);
	double *y = gen_array(ARRAY_SIZE);
	double *z = (double*) malloc(ARRAY_SIZE*sizeof(double));

	// Test framework that sweeps the number of threads and times each run
	double start_time, run_time;
	int num_threads = omp_get_max_threads();	


	for(int i=1; i<=num_threads; i++) {
		omp_set_num_threads(i);		
	  start_time = omp_get_wtime();
		for(int j=0; j<REPEAT; j++)
			v_add_optimized_adjacent(x,y,z);
		run_time = omp_get_wtime() - start_time;
    if(!verify(x,y, v_add_optimized_adjacent)){
      printf("v_add optimized adjacent does not match oracle\n");
      return -1; 
    }
    printf("Optimized adjacent: %d thread(s) took %f seconds\n",i,run_time);
  }


	for(int i=1; i<=num_threads; i++) {
		omp_set_num_threads(i);		
	  start_time = omp_get_wtime();
		for(int j=0; j<REPEAT; j++)
			v_add_optimized_chunks(x,y,z);
		run_time = omp_get_wtime() - start_time;
    if(!verify(x,y, v_add_optimized_chunks)){
      printf("v_add optimized chunks does not match oracle\n");
      return -1; 
    }
    printf("Optimized chunks: %d thread(s) took %f seconds\n",i,run_time);
  }

	for(int i=1; i<=num_threads; i++) {
		omp_set_num_threads(i);		
		start_time = omp_get_wtime();
		for(int j=0; j<REPEAT; j++)
			v_add_naive(x,y,z);
		run_time = omp_get_wtime() - start_time;
  	printf("Naive: %d thread(s) took %f seconds\n",i,run_time);
  }
  return 0;
}
 

