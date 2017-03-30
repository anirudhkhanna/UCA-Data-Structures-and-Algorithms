/* Given an array of numbers.
   Find and print all subsets of the array.
*/

#include <iostream>
using namespace std;

int sNo = 0; // subset serial number

void printSolution(int *arr, bool *included, int lim) {
	cout << "Subset " << ++sNo << " = { ";
	for(int i = 0; i <= lim; i++) {
		if(included[i])
			cout << arr[i] << " ";
	}
	cout << "} \n";
}

void subsets(int *arr, bool *included, int N, int i) {

	if(i >= N) // base case: array index out of bounds
		return;

	included[i] = true; // include this number

	printSolution(arr, included, i); // print the current subset (the included numbers)

	subsets(arr, included, N, i + 1); // keep this element included and recursively call for the next element

	included[i] = false; // don't include this element and recursively call for the next element
	subsets(arr, included, N, i + 1);
}

int main() {
	int N;
	cout << "Enter size of the array: ";
	cin >> N;

	int arr[N];
	bool included[N];

	cout << "Enter array elements to show all subsets: \n";
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		included[i] = false;
	}

	cout << "\n";
	subsets(arr, included, N, 0); // call with array of numbers, included flags array, size, current index
	cout << "\n";
	return 0;
}
