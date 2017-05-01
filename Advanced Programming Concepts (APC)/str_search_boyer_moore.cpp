/* Boyer-Moore String Search Algorithm (Using Bad Character Heuristic)

   Given a text of length N and a pattern of length M, find the occurrences of the pattern in the text.

   Boyer-Moore Algorithm:
   Boyer-Moore algorithm starts matching from the last character of the pattern and slides the pattern if a match is not found.
   The algorithm requires preprocessing the pattern first. This can be done in two ways:
   1. Bad Character Heuristic
   2. Good Suffix Heuristic

   Preprocessing is done so that the pattern can be shifted by more than one location at a time.
   If the whole pattern is matched, then the index position is shown.
   If a mismatch occurs, shift position towards right with the help of the bad character array.

   Bad character heuristics array is filled as:
   Except the last one, for any character ch (at index i) in the pattern, badchar[ch] = (length - i - 1) = (M - i - 1)
   For the last character, if it is already defined (i.e. if it occurred previously also), then no change. Otherwise, badchar[ch] = length = M
   For the characters not occurring in the pattern, badchar[ch] = length = M

   The idea is that whenever a character doesn't match, we slide the pattern in such a way that the bad character is aligned with the last occurrence of it in pattern.
   We preprocessed the pattern to store the sliding required to reach the last occurrence of every character.
   If the character is not present at all in the current window, then it may result in a shift by M characters. Therefore, bad character heuristic takes O(N/M) time in best case.

   Note: Bad character and good suffix heuristics can be used individually as well as combined. The pattern is then shifted by the larger of the two distances given by bad character and good suffix heuristics.

   Example:
   text = "fineandgood"
   pattern = "dgood"

   Construct badchar heuristic for the pattern.
   Length of pattern = M = 5
   Char      Index      Heuristic value      Badchar [d g o *] where * represents all other characters
   d         0          5 - 0 - 1 = 4        [4 _ _ 5]
   g         1          5 - 1 - 1 = 3        [4 3 _ 5]
   o         2          5 - 2 - 1 = 2        [4 3 2 5]
   o         3          5 - 3 - 1 = 1        [4 3 1 5]
   d         4          5 (M)                [4 3 1 5] (although d was last character, it's not changed to length M as it was already defined)

   As a result, badchar[]: [d g o *]
                         = [4 3 1 5]

   Now the pattern is to be matched.
   f i n e a n d g o o d
   d g o o d              (mismatch, therefore slide the pattern by badchar['a'] i.e. badchar[*] = 5)

   f i n e a n d g o o d
             d g o o d    (mismatch, therefore slide the pattern by badchar['o'] = 1)

   f i n e a n d g o o d
               d g o o d  (match)

   Time Complexity:
   O(N) to O(N.M)
   O(N/M) in best case, if the alphabet is large. This is because often a shift of upto M characters is possible.
*/

#include <iostream>
#include <cstring>
using namespace std;

#define ASCII_LEN 256

void setBadCharHeuristic(char pattern[], int M, int badchar[]) {
	// initialize
	for(int i = 0; i < 256; i++)
		badchar[i] = M;

	// for all characters in the pattern except last one (if last character also occurs previously, then only it will overwrite M)
	for(int i = 0; i <= M - 2; i++)
		badchar[(int) pattern[i]] = M - i - 1;
}

void boyerMooreSearch(char text[], char pattern[]) {
	int N = strlen(text);
	int M = strlen(pattern);
	int badchar[ASCII_LEN];

	// set bad character heuristic
	setBadCharHeuristic(pattern, M, badchar);

	// search the pattern (shifts occur according to badchar[])
	int pos = M - 1;
	while(pos < N) {

		// start matching the pattern backwards
		int i, j;
		for(i = pos, j = M - 1; j >= 0; j--, i--)
			if(text[i] != pattern[j])
				break;

		if(j < 0) { // pattern matched completely
			cout << "\nPattern occurs at index: " << pos - (M - 1);
			pos += badchar[text[pos]];
		}
		else { // mismatch occurred
			pos += badchar[text[pos]];
		}
	}
}

int main() {
	char text[100], pattern[100];
	cout << "\nEnter a text and a pattern to be searched: \n\n";
	cin >> text >> pattern;

	boyerMooreSearch(text, pattern);

	cout << "\n\n";
	return 0;
}