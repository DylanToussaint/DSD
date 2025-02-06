#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>

#define step 1/8.0
#define N    2041

void generateVector(float x[N]){
	int i;
	x[0] = 0;
	for(i = 1; i<N; i++){
		x[i] = x[i-1] + step;
	}
}

float sumVector(float x[], int M){
	int i;
	float y = 0.0;

	for(i = 0; i<=M; i++){
		y += x[i]*(1+x[i]*x[i]);
	}
	return y;
}

int main(){
	printf("Beginning Task 2! \n");

	float x[N];

	float y;

	generateVector(x);

	clock_t exec_t1, exec_t2;

	exec_t1 = times(NULL);

	y = sumVector(x, N);

	exec_t2 = times(NULL);

	y=y/1024.0;

	printf("Result: %d \n", (int)y);
	printf("Elapsed Time: %d", exec_t2 - exec_t1);

	return 0;
}
