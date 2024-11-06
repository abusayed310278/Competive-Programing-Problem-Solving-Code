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

	int a[4];

	for (int i = 0; i < 4; i++)cin >> a[i];

	if (a[1] + a[2] + a[3] <= a[0])cout << 1 << endl;
	else if (a[1] + a[2] <= a[0] or a[2] + a[3] <= a[0])cout << 2 << endl;

	else

		cout << 3  << endl;

}

int main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}