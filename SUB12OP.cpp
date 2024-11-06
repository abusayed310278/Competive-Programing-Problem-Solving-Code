#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define int long long
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

	for (int i = n; i >= 2; i--) {

		if (a[i] > 0) {
			int k = a[i] / 2;
			a[i] -= 2 * k;
			a[i - 1] -= k;
		}
	}

	for (int i = n; i >= 2; i--) {

		if (a[i] > 0 and a[i - 1] > 0) {

			a[i] -= 2;
			a[i - 1] -= 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += abs(a[i]);
	}

	cout << ans << endl;

}

int32_t main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}