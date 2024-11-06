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



int maxi = 100 * 200 + 10;

void solve() {

	int n; cin >> n;
	vi r(n), b(n);
	for (int i = 0; i < n; i++)cin >> r[i];
	for (int i = 0; i < n; i++)cin >> b[i];


	vi dp(maxi, -1);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = maxi - 1; j >= 0; j--) {

			if (j + r[i] <= maxi){
				dp[j + r[i]] = max(dp[j + r[i]], dp[j]);
			}

			if (dp[j] >= 0){
				dp[j] += b[i];
			}

		}
	}

	int ans = 0;
	for (int i = 0; i < maxi; i++) {
		ans = max(ans, min(i, dp[i]));
	}

	cout << ans << endl;

}

int main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}