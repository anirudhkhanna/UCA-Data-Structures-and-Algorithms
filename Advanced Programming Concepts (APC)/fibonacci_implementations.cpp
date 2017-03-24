#include <iostream>
#include <map>
using namespace std;

map<int, long> fibmap; // for memoization

/* O(n) time and O(1) space */
long fibIteration(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	int i;
	long a = 0, b = 1, sum;
	for(i = 3; i <= n; i++) {
		sum = a + b;
		a = b;
		b = sum;
	}

	return b;
}

/* O(2 ^ n) [precisely, O(phi ^ n) ~ O(1.6 ^ n)] time and O(n) space in the stack */
long fibRecursion(int n) {
	if(n == 1) return 0;
	else if(n == 2) return 1;
	else return fibRecursion(n - 1) + fibRecursion(n - 2);
}

/* ~ O(n) time and O(n) space */
long fibMemoization(int n) {
	if(n == 1) return 0;
	else if(n == 2) return 1;
	else if(fibmap.find(n) != fibmap.end()) return fibmap[n];
	else return fibmap[n] = fibMemoization(n - 1) + fibMemoization(n - 2);
}

int main() {
	int n;

	cout << "\n\tFibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...\n";

	cout << "\n\tfibMemoization(1): \t" << fibMemoization(1);
	cout << "\n\tfibIteration(1): \t"   << fibIteration(1);
	cout << "\n\tfibRecursion(1): \t"   << fibRecursion(1);
	cout << "\n";
	cout << "\n\tfibMemoization(11): \t" << fibMemoization(11);
	cout << "\n\tfibIteration(11): \t"   << fibIteration(11);
	cout << "\n\tfibRecursion(11): \t"   << fibRecursion(11);
	cout << "\n";
	cout << "\n\tfibMemoization(27): \t" << fibMemoization(27);
	cout << "\n\tfibIteration(27): \t"   << fibIteration(27);
	cout << "\n\tfibRecursion(27): \t"   << fibRecursion(27);
	cout << "\n";
	cout << "\n\tfibMemoization(42): \t" << fibMemoization(42);
	cout << "\n\tfibIteration(42): \t"   << fibIteration(42);
	cout << "\n\tfibRecursion(42): \t"   << fibRecursion(42);

	cout << "\n\n";
	return 0;
}