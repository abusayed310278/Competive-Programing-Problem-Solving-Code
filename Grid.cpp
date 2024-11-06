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

vector<vector<int>>dp;
vector<vector<char>>m;

int f(int i, int j) {

	if (i >= 0 and j >= 0 and m[i][j] == '#')return 0;
	if (i == 0 and j == 0)return 1;
	if (i < 0 || j < 0)return 0;

	if (dp[i][j] != -1)return dp[i][j];

	int left = f(i - 1, j);
	int right = f(i, j - 1);

	return dp[i][j] = (left + right) % mod;

}


void solve() {

	int n, mm; cin >> n >> mm;
	m.resize(n, vector<char>(mm));
	dp.resize(n, vector<int>(mm, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < mm; j++) {
			cin >> m[i][j];
		}
	}

	cout << f(n - 1, mm - 1) << endl;

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