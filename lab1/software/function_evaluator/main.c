#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>


#define CASE 4

#if(CASE==1)
	#define step 5
	#define N 52
#endif

#if(CASE==2)
	#define step 1/8.0f
	#define N 2041
#endif

#if(CASE==3)
	#define step 1/256.0
	#define N 65091
#endif

#if(CASE==4)
	#define N 2323
	#define step 0
	#define RANDSEED 334
	#define MAXVAL 1000
#endif


// Generates the vector x and stores it in the memory
void generateVector(float x[N])
{
	int i;
	x[0] = 0;
	for (i=1; i<N; i++) {
		x[i] = x[i-1] + step;
	}
}
#if(CASE==4)
void generateRandomVector(float x[N])
{
	int i;
	srand(RANDSEED);
	for (i = 0; i < N; i++) {
		x[i] = ((float) rand()/ (float) RAND_MAX) * MAXVAL;
	}
}
#endif

float sumVector(float x[], int M)
{
	float sum = 0;
	int i;
	for (i = 0; i < M; i++) {
	  sum += 0.5 * x[i] + x[i]*x[i]*x[i]*cos((x[i]-128.0f)/128.0f);
	}
	return sum;
}

int main()
	{
	printf("Task 4, Test Case %d!\n", CASE);
	// Define input vector
	float x[N];
	// Returned result
	float y = 0;

#if(CASE == 4)
		generateRandomVector(x);
#else
		generateVector(x);
#endif
	clock_t exec_t1, exec_t2;// The following is used for timing

	unsigned long acc_time = 0;

	int iterations = 1;
	for (int i = 0; i < iterations; i++) {
		exec_t1 = times(NULL); // get system time before starting the process

		y = sumVector(x, N);

		exec_t2 = times(NULL); // get system time after finishing the process
		acc_time += exec_t2-exec_t1;
		printf("T1: %lums\n", exec_t1);
		printf("T2: %lums\n", exec_t2);

		printf("Time for execution (in milliseconds): %lums\n", exec_t2 - exec_t1);
	}
	acc_time /= iterations;

	printf("Average time for %d execution(s) (in milliseconds): %lums\n", iterations, acc_time);
	y = y/1024.0;
	printf("Result of calculation: %d\n", ((int)y));
	return 0;
}
