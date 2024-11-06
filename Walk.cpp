#include<bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;



/*

suppose n<=10^15

*/

const int mod = 1e9 + 7;
const int sz = 51;

struct Mat {

	int m[sz][sz];

	Mat() {
		memset(m, 0, sizeof(m));
	}

	void identity() {
		for (int i = 0; i < sz; i++) {
			m[i][i] = 1;
		}
	}

	Mat operator*(Mat a) {
		Mat res;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					res.m[i][j] += m[i][k] * a.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}

		return res;
	}


};

void solve() {

	int n, k; cin >> n >> k;

	Mat a, res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a.m[i][j];
		}
	}



	res.identity();

	while (k) {
		if (k & 1LL)res = res * a;
		a = a * a;
		k /= 2;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += res.m[i][j];
			ans %= mod;
		}
	}

	cout << ans << endl;

}

int32_t main()
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