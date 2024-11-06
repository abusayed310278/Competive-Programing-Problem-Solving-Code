#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;


const int mod = 1e9 + 7;
const int N = 1e5 + 10;
vi h(N);
int dp[N];
int k;

int f(int i) {

	if (i == 0)return 0;
	if (dp[i] != -1)return dp[i];

	int cost = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if (i - j >= 0)
			cost = min(cost, f(i - j) + abs(h[i] - h[i - j]));
	}

	return dp[i] = cost;

}

void solve() {

	int n; cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	h.clear();

	for (int i = 0; i < n; i++)cin >> h[i];


	cout << f(n-1) << endl;

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