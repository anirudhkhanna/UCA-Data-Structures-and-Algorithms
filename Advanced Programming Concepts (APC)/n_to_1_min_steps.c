/* Minimum no of steps to convert a number N to 1 by using only three operations: 
   N - 1
   N / 2
   N / 3

   Example: 10
   Checking: 10 -> 5 -> 4 -> 2 -> 1 (Steps: 4)
             10 -> 9 -> 3 -> 1      (Steps: 3)
   Result: 3 steps
*/

#include <stdio.h>
#include <string.h>

int minof3(int, int, int);
int minof2(int, int);

int operate(int N) {
	if(N == 1)
		return 0;

	else {
		if(N % 3 == 0 && N % 2 == 0)            // All operations possible
			return 1 + minof3(
							operate(N / 3), 
							operate(N / 2), 
							operate(N - 1)
						);

		else if(N % 3 != 0 && N % 2 == 0)       // N/3 not possible
			return 1 + minof2(
							operate(N / 2), 
							operate(N - 1)
						);

		else if(N % 3 == 0 && N % 2 != 0)       // N/2 not possible
			return 1 + minof2(
							operate(N / 3), 
							operate(N - 1)
						);

		else                                    // N/3 and N/2 not possible. Only N-1 possible
			return 1 + operate(N - 1);
	}
}

int getMinSteps(int N) {
	return operate(N);
}

int main() {
	int N, steps;

	printf("\nMinimum no of steps to convert a number N to 1 by using only the operations \nN-1, N/2 and N/3 \n\n");
	printf("Enter a number: \n");
	scanf("%d", &N);

	steps = getMinSteps(N);

	printf("Min steps = %d \n", steps);
	return 0;
}

int minof3(int a, int b, int c) {
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int minof2(int a, int b) {
	return (a < b) ? a : b;
}
