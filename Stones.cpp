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

void solve() {

	int n, k; cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; i++)cin >> a[i];

	int dp[k + 1];
	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		
		dp[i] = 0;

		for (int j = 0; j < n; j++) {

			if (i - a[j] >= 0 and dp[i - a[j]] == 0) {
				dp[i] = 1; break;
			}

		}
	}

	cout << (dp[k] ? "First" : "Second") << endl;

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