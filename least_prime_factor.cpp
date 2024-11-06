#include<bits/stdc++.h>
using namespace std;

//tc: O(nlog(logn))
void leastPrimeFactors(int n) {

	vector<int>leastprime(n + 1, 0);
	leastprime[1] = 1;

	for (int i = 2; i <= n; i++) {

		if (leastprime[i] == 0) {
			leastprime[i] = i;
			for (int j = i * i; j <= n; j += i) {
				if (leastprime[j] == 0)leastprime[j] = i;
			}
		}
	}

	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		ans.push_back(leastprime[i]);
		cout << leastprime[i] << " ";
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	int n; cin >> n;
	leastPrimeFactors(n);

	return 0;
}


