#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

/*

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9


*/

int wt[105], val[105];
long long dp[105][100005];

const int mod = 1e9 + 7;

long long knapsack(int i, int w) {

	if (w == 0)return 0;
	if (i < 0)return 0;
	if (dp[i][w] != -1)return dp[i][w];

	long long op1 = knapsack(i - 1, w);

	long long op2 = 0;
	long long ans = INT_MIN;

	if (w - wt[i] >= 0)
		op2 = val[i] + knapsack(i - 1, w - wt[i]);

	ans = max({ans, op1, op2});



	return dp[i][w] = ans;

}

void solve() {

	int n, w; cin >> n >> w;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}



	cout << knapsack(n - 1, w) << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}