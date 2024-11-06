#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back

using namespace std;

using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;



const int mod = 1e9 + 7;

void solve() {

	int n; cin >> n;
	vvc g(n, vc(n));
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> g[i][j];

	vvi dp1(n, vi(n)), dp2(n, vi(n));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp1[i][j] = (g[i][j] != '#');
			if (i != n - 1 and !dp1[i + 1][j])dp1[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			dp2[i][j] = (g[i][j] != '#');
			if (j != n - 1 and !dp2[i][j + 1])dp2[i][j] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (dp1[i][j] and dp2[i][j])ans++;

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