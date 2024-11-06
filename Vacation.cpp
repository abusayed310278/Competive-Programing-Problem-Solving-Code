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
const int N = 1e5 + 5;
vvi a;
int dp[N][4];

int f(int ind, int last) {

	if (ind == 0) {
		int maxi = 0;
		for (int i = 0; i <= 2; i++)maxi = max(maxi, a[0][i]);

		return maxi;
	}

	if (dp[ind][last] != -1)return dp[ind][last];

	int maxi = 0;
	for (int i = 0; i <= 2; i++) {
		if (i != last) {
			int cur = a[ind][i] + f(ind - 1, i);
			maxi = max(maxi, cur);
		}
	}

	return dp[ind][last] = maxi;

}


void solve() {

	int n; cin >> n;
	vi v;
	for (int i = 1; i <= n; i++) {
		int x, y, z; cin >> x >> y >> z;
		v = {x, y, z};
		a.push_back(v);
	}

	memset(dp, -1, sizeof(dp));

	cout << f(n - 1, -1) << endl;



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