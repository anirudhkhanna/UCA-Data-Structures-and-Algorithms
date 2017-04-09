/* Find all possible permutations of a given string.
   
   Eg. String = ABC
       Result = ABC ACB BAC BCA CBA CAB
   
   We can solve this problem by repeated swapping and backtracking.
   Complexity: O(n * n!)
*/

#include <iostream>
#include <cstring>
using namespace std;

void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void allPermutations(char str[], int l, int r) {
	if(l == r)
		cout << str << " ";
	else
		for(int i = l; i <= r; i++) {
			swap(str + l, str + i); // swap the characters at l and i
			allPermutations(str, l + 1, r);
			swap(str + l, str + i); // backtrack: swap back to the original positions
		}
}

int main() {
	char str[100], N;
	cout << "\nEnter a string: ";
	cin >> str;

	cout << "\nAll possible strings: \n";
	N = strlen(str);
	allPermutations(str, 0, N - 1);
	cout << "\n\n";

	return 0;
}