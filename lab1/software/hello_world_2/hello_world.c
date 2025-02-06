#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>
// Test case 1
//#define step 5
//#define N 52

//// Test case 2
//#define step 1/8.0f
//#define N 2041

////Test case 3
#define step 1/256.0
#define N 65091
//#define N 40081

// Generates the vector x and stores it in the memory
void generateVector(float x[N])
{
	int i;
	x[0] = 0;
	for (i=1; i<N; i++) {
		x[i] = x[i-1] + step;
	}
}

float sumVector(float x[], int M)
{
	float sum = 0;
	int i;
	for (i = 0; i < M; i++) {
	  sum += x[i] + x[i]*x[i]*x[i];
	}
	return sum;
}

int main()
	{
	printf("Task 2!\n");
	// Define input vector
	float x[N];
	// Returned result
	float y = 0;

	generateVector(x);// The following is used for timing
	clock_t exec_t1, exec_t2;

	unsigned long acc_time = 0;

	for (int i = 0; i < 10; i++) {
		exec_t1 = times(NULL); // get system time before starting the process

		y = sumVector(x, N);

		exec_t2 = times(NULL); // get system time after finishing the process
		acc_time += exec_t2-exec_t1;
		printf("T1: %lums\n", exec_t1);
		printf("T2: %lums\n", exec_t2);

		printf("Time for execution (in milliseconds): %lums\n", exec_t2 - exec_t1);
	}
	acc_time /= 10;

	printf("Average time for execution (in milliseconds): %lums\n", acc_time);
	y = y/1024.0;
	printf("Result of calculation: %d\n", ((int)y));
	return 0;
}
