#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int w[105], val[105];
long long dp[105][100005];


//knapsack atcoder question
long long f(int i, int v) {

	if (v == 0)return 0;
	if (i < 0)return 1e15;
	if (dp[i][v] != -1)return dp[i][v];

	long long ans = f(i - 1, v);


	if (v - val[i] >= 0) {

		ans = min(ans, w[i] + f(i - 1, v - val[i]));
		
	}


	return dp[i][v] = ans;
}

int main()
{
	int n, wt; cin >> n >> wt;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> val[i];
	}

	memset(dp, -1, sizeof(dp));
	int max_val = 1e5;
	for (int i = max_val; i >= 0; i--) {
		if (f(n - 1, i) <= wt) {
			cout << i << endl;
			break;
		}
	}


	return 0;
}