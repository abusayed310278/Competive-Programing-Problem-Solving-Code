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
	vi p(n + 5);
	for (int i = 0; i < n; i++)cin >> p[i];

	vi left(n + 5, 1), right(n + 5, 1);

	for (int i = 1; i <= n; i++) {
		if (p[i] < p[i - 1])
			left[i] += left[i - 1];

		if (p[n - 1 - i] < p[n - i])
			right[n - 1 - i] += right[n - i];


	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += left[i] * right[i];
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