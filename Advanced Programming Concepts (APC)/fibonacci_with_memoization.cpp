#include <iostream>
#include <map>
using namespace std;

map<int, long> fibmap;

long fib(int n) {
	if(n == 1)
		return 0;

	else if(n == 2)
		return 1;

	else if(fibmap.find(n) != fibmap.end()) {
		cout << "\n\t-> Found in map: fib(" << n << ") = " << fibmap[n];
		return fibmap[n];
	}

	else {
		fibmap[n] = fib(n - 1) + fib(n - 2);
		return fibmap[n];
	}
}

int main() {
	int n;

	cout << "\n\tFibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...\n";
	while(1) {
		cout << "\n\tEnter n to find the nth Fibonacci number: ";
		cin >> n;
		if(n <= 0)
			continue;
		else {
			fibmap.clear();
			cout << "\n\n\tnth Fibonacci number: " << fib(n) << " \n";
		}
	}

	return 0;
}