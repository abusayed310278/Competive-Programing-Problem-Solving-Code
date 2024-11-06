#include<bits/stdc++.h>
using namespace std;

void smallestPrimeFactors(int n) {

	if (n <= 1)return;

	int mini = INT_MAX;
	for (int i = 2; i * i <= n; i++) {

		while (n % i == 0) {
			mini = min(mini, i);
			n /= i;
		}
	}
	if (n > 1)mini = min(mini, n);

	cout << mini;
}

//tc: O(nlog(logn))
void leastPrimeFactors(int n) {
	vector<int>leastprime(n + 1, 0);
	cout << 1 << " ";

	for (int i = 2; i <= n; i++) {

		if (leastprime[i] == 0) {
			cout << i << " ";
			for (int j = i * i; j <= n; j += i) {
				if (leastprime[j] == 0)leastprime[j] = i;
			}
		} else {
			cout << leastprime[i] << " ";
		}
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);



	/*	int n;cin>>n;
		smallestPrimeFactors(n);*/

	int n; cin >> n;
	leastPrimeFactors(n);

	return 0;
}


