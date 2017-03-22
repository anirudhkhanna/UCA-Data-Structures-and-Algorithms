/* Given n tasks each with start time and end time.
   We have to schedule them on machines such that minimum number of machines are used.
   Scheduling is non-preemptive - a task must be completed once it is initiated.
   No two tasks should overlap on a machine - a machine can run only one task at a time.

   (We will use greedy approach.)
*/

#include <stdio.h>

typedef struct job {
	int jNo;
	int start;
	int end;
	int executedByMachineNo;
} job;

int compareWithStartTime(const void *a, const void *b) {
	return (((job*)a) -> start - ((job*)b) -> start);
}

int compareWithJobNo(const void *a, const void *b) {
	return (((job*)a) -> jNo - ((job*)b) -> jNo);
}

int main() {
	int N, i, j, maxMachineCount = 0;
	printf("\nEnter the number of jobs: ");
	scanf("%d", &N);

	job jobs[N]; // Array of jobs
	int machines[N]; // Array of machines. Max up to N machines can be needed.
					 // Will store the end time of the task it is executing, if any. So, we will know when a particular machine will be free.
	for(i = 0; i < N; i++)
		machines[i] = 0;

	printf("\nEnter %d jobs' start and end times respectively: \n", N);
	for(i = 0; i < N; i++) {
		jobs[i].jNo = i + 1;
		scanf("%d %d", &jobs[i].start, &jobs[i].end);
	}

	// Sort the jobs acc to start time for greedily assigning the machines
	qsort(jobs, N, sizeof(job), compareWithStartTime); // qSort(arrayName, noOfElements, sizeOfOneElement, comparatorFunction); | Can sort anything - ints, chars, structures

	// Display sorted jobs
	printf("\nGiven jobs sorted acc to start time: \n");
	printf("JNo \tStart \tEnd \n");
	for(i = 0; i < N; i++)
		printf("%d \t%d \t%d \n", jobs[i].jNo, jobs[i].start, jobs[i].end);

	// Assign the machines
	for(i = 0; i < N; i++) {
		int machineFound = 0;
		for(j = 0; j < N && !machineFound; j++) {
			if(machines[j] <= jobs[i].start) { // This machine will be available at the start of a job's execution
				machineFound = 1;
				machines[j] = jobs[i].end;
				jobs[i].executedByMachineNo = j + 1;

				if(j > maxMachineCount)
					maxMachineCount = j;
			}
		}
	}

	// Sort the jobs back acc to job number for display
	qsort(jobs, N, sizeof(job), compareWithJobNo); // qSort(arrayName, noOfElements, sizeOfOneElement, comparatorFunction); | Can sort anything - ints, chars, structures

	// Display results
	printf("\n********************");
	printf("\nJob execution stats: \n");
	printf("******************** \n");
	printf("JNo \tStart \tEnd \tExecuted By Machine No\n");
	for(i = 0; i < N; i++)
		printf("%d \t%d \t%d \t%d \n", jobs[i].jNo, jobs[i].start, jobs[i].end, jobs[i].executedByMachineNo);

	printf("\nTotal machines needed: %d \n", maxMachineCount + 1);
	return 0;
}