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



const int mod = 1e9 + 7;

void solve() {

	int n; cin >> n;
	vi a(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];

	vvi dp(n + 1, vi (7, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {

		int c = 0, x = a[i];

		while (x) {
			c++;
			x /= 10;
		}

		int num = pow(10, c);

		for (int j = 0; j < 7; j++) {

			dp[i][(num * j + a[i]) % 7] = (dp[i][(num * j + a[i]) % 7] + dp[i - 1][j]) % mod;
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;

		}
	}

	cout << (dp[n][0] - 1 + mod) % mod << endl;

}

int main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}