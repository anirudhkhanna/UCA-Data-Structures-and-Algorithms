/* Given a sorted array of numbers and a sum value.
   Determine which subsets of the array add up to the given sum value.
*/

#include <iostream>
using namespace std;

void printSolution(int *arr, bool *included, int lim) {
	cout << "Subset found: { ";
	for(int i = 0; i <= lim; i++) {
		if(included[i])
			cout << arr[i] << " ";
	}
	cout << "} \n";
}

void sumOfSubsets(int *arr, bool *included, int N, int SumVal, int S, int i) {
	cout << "\n sumOfSubsets ( " << S << ", arr[" << i << "]=" << arr[i] << " ) \t";

	included[i] = true; // include this number

	if(S + arr[i] == SumVal) // print the subset (the included numbers), if adding this number to our intermediate sum gives the required sum value
		printSolution(arr, included, i);

	else
		if((i + 1 < N) && (S + arr[i] <= SumVal)) // add this element in the intermediate sum and recursively call for the next element
			sumOfSubsets(arr, included, N, SumVal, S + arr[i], i + 1);

	if((i + 1 < N) && (S + arr[i + 1] <= SumVal)) { // also, skip adding this element and recursively call for the next element
		included[i] = false;
		sumOfSubsets(arr, included, N, SumVal, S, i + 1);
	}
}

int main() {
	int N, SumVal;
	cout << "Enter size of the array: ";
	cin >> N;

	int arr[N];
	bool included[N];

	cout << "Enter array elements: \n";
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		included[i] = false;
	}

	cout << "Enter a value to find the subsets that add up to it: ";
	cin >> SumVal;

	// call with array of numbers, included flags array, size, sum value, intermediate sum, current index
	sumOfSubsets(arr, included, N, SumVal, 0, 0);

	cout << "\n\n";
	return 0;
}
