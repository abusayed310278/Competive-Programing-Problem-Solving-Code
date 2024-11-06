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

//binary exponentiation: O(log(n))
void bpow(ll a, ll b) {

	ll res = 1;
	while (b) {
		if (b & 1)res *= a; res %= mod;
		a *= 1LL * a; a %= mod;

		b >>= 1; //b/=2;
	}
	cout << res << endl;

}

//binary multiplication
void bmul(int a, int b) {

	int res = 0;
	while (b) {
		if (b & 1)res += a;
		a = 2 * a;
		b /= 2;
	}

	cout << res << endl;

}

void solve() {
	int a, b; cin >> a >> b;
	// bpow(a, b);
	bmul(a, b);
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