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

int f(int ind) {

	if (ind <= 1)return 1;
	// if (ind == 1)return 1;


	return f(ind - 1) + f(ind - 2);

}

void solve() {

	int n; cin >> n;

	cout << f(n - 1) << endl;
}

int main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}