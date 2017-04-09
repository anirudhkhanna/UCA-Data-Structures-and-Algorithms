/* Coin Change Problem:
   Given a set of coin denominations and a total amount, find out in how many ways the change for that amount can be made using the denominations given.
   
   Example: Amount = 5
            Coins[] = {1, 2, 3}
            
            Number of ways = 5
            {1, 1, 1, 1, 1}, {1, 1, 1, 2}, {1, 2, 2}, {1, 1, 3}, {2, 3}
   
   Dynamic Programming Approach:
   Cre­ate a solu­tion matrix, ways[coins+1][amount+1].
   Now the problem can be solved in a bottom-up manner using this matrix.
   
   Base cases:
   If the amount is 0, number of ways to make the change is 1 (empty set of coins).
   If the number of coins is 0, number of ways is 0.
   
   Rest of the cases:
   For every coin, we have the option to either include it in the solu­tion or to exclude it.
   If the coin's value is less than or equal to the amount needed, then we will find the ways by includ­ing that coin and exclud­ing that coin.
   If the coin's value is greater than the amount, then we will not con­sider that coin.
   
   Complexity:
   O(nm) i.e. O(number of coins * amount)
*/

#include <iostream>
using namespace std;

int countWays(int coins[], int N, int Total, int i) {
	int ways[N + 1][Total + 1]; // (number of coins + 1) x (total amount + 1) matrix for storing values in bottom-up manner

	// when number of coins is 0, number of ways is also 0
	for(int j = 1; j < Total + 1; j++)
		ways[0][j] = 0;

	// when amount is 0, number of ways is just 1 (empty set)
	for(int i = 0; i < N + 1; i++)
		ways[i][0] = 1;

	// for the rest of the cases
	for(int i = 1; i < N + 1; i++)
		for(int j = 1; j < Total + 1; j++) {

			int coinvalue = coins[i - 1];

			// check if the coin's value is within the amount needed
			if(coinvalue <= j)
				ways[i][j] = ways[i][j - coinvalue] + ways[i - 1][j]; // including the coin and reducing the amount by the coin's value + not including the coin

			// otherwise the coin's value is larger than needed
			else
				ways[i][j] = ways[i - 1][j]; // copying the number of ways from the top (the coin is not included)
		}

	return ways[N][Total]; // return the number of ways for N coins and Total amount
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