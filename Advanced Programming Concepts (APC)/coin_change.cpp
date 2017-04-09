/* Coin Change Problem:
   Given a set of coin denominations and a total amount, find out in how many ways the change for that amount can be made using the denominations given.
   
   Example: Amount = 5
            Coins[] = {1, 2, 3}
            
            Number of ways = 5
            {1, 1, 1, 1, 1}, {1, 1, 1, 2}, {1, 2, 2}, {1, 1, 3}, {2, 3}
   
   Recursive Approach:
   For every coin, we have the option to either include it in the solu­tion or to exclude it.
   When a coin is included, the amount should be decreased by the coin's value. When it is excluded, we should try the same for the next coin, with the same amount.
   
   Complexity:
   O(2^n) (This can be reduced by Dynamic Programming)
*/

#include <iostream>
using namespace std;

int countWays(int coins[], int N, int Total, int i) {
	if(Total == 0)
		return 1;

	if(Total < 0)
		return 0;

	if(i == N && Total != 0)
		return 0;

	return countWays(coins, N, (Total - coins[i]), i) + countWays(coins, N, Total, (i + 1));
}

int main() {
	int Total, N, *coins;
	cout << "\nEnter total amount: ";
	cin >> Total;
	cout << "\nEnter number of coin denominations: ";
	cin >> N;
	coins = new int[N];
	cout << "\nEnter the value of each type of coin: \n";
	for(int i = 0; i < N; i++)
		cin >> coins[i];

	int ways = countWays(coins, N, Total, 0);
	cout << "\nTotal number of ways to make the amount = " << ways << "\n\n";
	return 0;
}