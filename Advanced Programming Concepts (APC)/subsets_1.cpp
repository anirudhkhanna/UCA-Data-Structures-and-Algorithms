/* Given an array of numbers.
   Find and print all subsets of the array.
*/

#include <iostream>
using namespace std;

long pow(int, unsigned int);

int sNo = 0; // subset serial number

void subsets(int *arr, int N) {
	long lim = pow(2, N); // subsets follow the pattern of bits in binary numbers from 0 to (2^n - 1)

	for(long a = 0; a < lim; a++) {
		// printing a set according to the ON bits in (a)

		cout << ++sNo << ". { ";
		for(int i = 0; i <= N; i++)
			if((a >> i) & 1)
				cout << arr[i] << " ";
		cout << "} \n";
	}
}

int main() {
	int N;
	cout << "Enter size of the array: ";
	cin >> N;

	int arr[N];

	cout << "Enter array elements to show all subsets: \n";
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	cout << "\n";
	subsets(arr, N);
	cout << "\n";
	return 0;
}

long pow(int x, unsigned int y) {
	if(y == 0) return 1;

	long temp = pow(x, y/2);
	if(y%2 == 0) return temp * temp;
	else return x * temp * temp;
}
