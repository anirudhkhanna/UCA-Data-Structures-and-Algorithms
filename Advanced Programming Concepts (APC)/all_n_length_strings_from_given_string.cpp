/* Find all possible N-length strings that can be formed using the letters from a given string.
   
   Eg. String = ALGO, N = 2
       Result = AA LA GA OA AL LL GL OL AG LG GG OG AO LO GO OO
*/

#include <iostream>
#include <cstring>
using namespace std;

void allPossibleStringsOfSizeN(char str[], char buf[], int N) {
	if(N <= 0)
		cout << buf << " ";
	else
		for(int i = 0; i < strlen(str); i++) {
			buf[N - 1] = str[i];
			allPossibleStringsOfSizeN(str, buf, N - 1);
		}
}

int main() {
	int N;
	char str[100];
	cout << "\nEnter a string: ";
	cin >> str;
	cout << "\nEnter a number: ";
	cin >> N;

	cout << "\nAll possible strings of length " << N << ": \n";
	char buf[N + 1];
	buf[N] = '\0';
	allPossibleStringsOfSizeN(str, buf, N);
	cout << "\n\n";

	return 0;
}