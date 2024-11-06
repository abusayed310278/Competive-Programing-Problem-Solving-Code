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




const int m = 1e9 + 7;

string k;
int d;

int dp[10001][2][101];
int f(int i, int last, int mod) {

	if (i == k.size()) {
		return (mod == 0);
	}
	int &ans = dp[i][last][mod];

	if (ans != -1)return ans;
	ans = 0;

	int till = last ? (k[i] - '0') : 9;
	for (int digits = 0; digits <= till; digits++) {
		ans += f(i + 1, last && (digits == till), (mod + digits) % d);
		ans %= m;
	}

	return dp[i][last][mod] = ans;

}


void solve() {

	memset(dp, -1, sizeof(dp));
	cin >> k >> d;

	cout << (f(0, 1, 0) - 1 + m) % m << endl;
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