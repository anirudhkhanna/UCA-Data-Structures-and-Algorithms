/* From an unsorted array of numbers, find a pair whose sum is equal to a given value.
   
   Eg: [6, 1, 3, 4], Sum = 9
       Pair = (6, 3)
       [6, 1, 3, 4], Sum = 8
       Pair not found
*/

#include <iostream>
#include <set>
using namespace std;

set<int> complements;

int main() {
	int N, Sum, i, a, b, comp, found;
	cout << "Enter the size of array: \n";
	cin >> N;
	int arr[N];
	cout << "Enter array: \n";
	for(i = 0; i < N; i++)
		cin >> arr[i];
	cout << "Enter a sum value to find corresponding pair from the array: \n";
	cin >> Sum;

	found = 0;
	for(i = 0; i < N; i++) {
		// Check if the number is in the set (then it must be the complement of some previous number)
		if(complements.find(arr[i]) != complements.end()) {
			a = Sum - arr[i];
			b = arr[i];
			found = 1;
			break;
		}
		// Otherwise, insert its complement to the set (so that it may be found later if it occurs in the array)
		else {
			comp = Sum - arr[i];
			complements.insert(comp);
		}
	}

	if(!found)
		cout << "\nPair not found. \n\n";
	else
		cout << "\nPair = (" << a <<", " << b << ") \n\n";

	return 0;
}
