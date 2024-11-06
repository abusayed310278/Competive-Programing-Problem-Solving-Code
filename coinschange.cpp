#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> coins = {1, 2, 5, 10};
	// vector<int> coins = {1, 3, 4};

	int changeRemaining = 9;
	int currentCoin = (int) coins.size() - 1;
	vector<int> coinsGiven;

	// Find the coins returned by the greedy strategy
	while(changeRemaining > 0 && currentCoin >= 0) {
		while(currentCoin >= 0 && coins[currentCoin] > changeRemaining)
			currentCoin--;
		changeRemaining -= coins[currentCoin];
		// possible change: changeRemaining -= coins[currentCoin] * (changeRemaining / coins[currentCoin);
		// the next line has to be then turned into a loop if the change is implemented
		coinsGiven.push_back(coins[currentCoin]);
	}

	// Print coins returned as change
	for (wchar_t i = 0; i < coinsGiven.size(); i++)
		cout << coinsGiven[i] << ' ';
	return 0;
}
