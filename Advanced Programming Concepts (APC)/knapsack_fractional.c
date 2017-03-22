/* The knapsack problem or rucksack problem is a problem in combinatorial optimization.
   Given a knapsack size limit and a set of items, each with a weight and a profit value,
   determine the items to put in a collection (or knapsack) such that
   the total weight is less than or equal to the given knapsack limit and
   the total profit (or value) is as large as possible.
   Fractional knapsack: We can take an item in fractional amount too, between 0 to 1.
   
   It can be solved by greedy approach.
*/

#include <stdio.h>

typedef struct item
{
	int itemNo;
	int value;
	int weight;
} item;

int compareValuePerUnitWeightDescending(const void *a, const void *b) {
	float valPerWt1 = ((item*)a) -> value / ((item*)a) -> weight;
	float valPerWt2 = ((item*)b) -> value / ((item*)b) -> weight;

	return (valPerWt2 - valPerWt1);
}

int compareItemNoAscending(const void *a, const void *b) {
	return ((item*)a) -> itemNo - ((item*)b) -> itemNo;
}

int main() {
	int knapsackSize, N, i;
	float totalValue = 0.0;
	printf("\nEnter the knapsack size: ");
	scanf("%d", &knapsackSize);
	printf("\nEnter the number of items: ");
	scanf("%d", &N);

	item items[N]; // Array of items
	float amountsTaken[N]; // Array of fractional amount taken of each item (between 0 to 1)
	for(i = 0; i < N; i++)
		amountsTaken[i] = 0.0;

	printf("\nEnter %d items' values and weights respectively: \n", N);
	for(i = 0; i < N; i++) {
		items[i].itemNo = i;
		scanf("%d %d", &items[i].value, &items[i].weight);
	}

	// Sort the items in decreasing order of value per unit weight
	qsort(items, N, sizeof(item), compareValuePerUnitWeightDescending); // qSort(arrayName, noOfElements, sizeOfOneElement, comparatorFunction); | Can sort anything - ints, chars, structures

	// Display the reverse sorted items
	printf("\nGiven items sorted in descending order of value per unit weight: \n");
	printf("ItemNo \tValue \tWeight \tValue/Weight \n");
	for(i = 0; i < N; i++)
		printf("%d \t%d \t%d \t%f \n", items[i].itemNo + 1, items[i].value, items[i].weight, (float) items[i].value / items[i].weight);

	// Putting the items in the knapsack greedily (max value per unit weight first)
	int capacity = knapsackSize;
	for(i = 0; i < N; i++) {
		if(items[i].weight > capacity)
			break;

		amountsTaken[items[i].itemNo] = 1;
		capacity = capacity - items[i].weight;
	}

	if(capacity > 0 && i < N) { // Put the next remaining item (if any) in fractional amount (if possible)
		float fractionalAmount = (float) capacity / items[i].weight;
		amountsTaken[items[i].itemNo] = fractionalAmount;
		capacity = capacity - fractionalAmount;
	}

	// Sort the items back according to item number for displaying results
	qsort(items, N, sizeof(item), compareItemNoAscending); // qSort(arrayName, noOfElements, sizeOfOneElement, comparatorFunction); | Can sort anything - ints, chars, structures

	totalValue = 0.0;
	printf("\nAmounts taken: \n");
	printf("itemNo \tAmount taken \n");
	for(i = 0; i < N; i++) {
		printf("%d \t%f \n", items[i].itemNo + 1, amountsTaken[i]);
		totalValue += amountsTaken[i] * items[i].value;
	}
	printf("\nTotal value accumulated: %f \n", totalValue);
	return 0;
}