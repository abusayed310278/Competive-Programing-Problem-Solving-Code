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
#define ld long double

using namespace std;

const int N = 3001;
ld p[N];
int n;

ld dp[N][N];

const int mod = 1e9 + 7;

ld f(int i, int h, int t) {

	if (i == n)return 1.00;
	ld &ans = dp[i][h];
	if (dp[i][h] != -1.00)return ans;
	ans = 0.0;


	if (h)ans += f(i + 1, h - 1, t) * p[i];
	if (t)ans += f(i + 1, h, t - 1) * (1.00 - p[i]);

	return ans;
}

void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1.00;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	ld ans = 0;
	for (int i = (n / 2 + 1); i <= n; i++)ans += f(0, i, n - i);

	cout << setprecision(10) << fixed;
	cout << ans << endl;

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