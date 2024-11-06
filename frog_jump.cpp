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

int f(int ind, vi &heights) {

	if (ind == 0)return 0;

	int left = abs(heights[ind] - heights[ind - 1]) + f(ind - 1, heights);
	int right = INT_MAX;

	if (ind > 1)
		right = abs(heights[ind] - heights[ind - 2]) + f(ind - 2, heights);


	return min(left, right);

}

void solve() {

	int n; cin >> n;
	vi heights(n);
	for (int i = 0; i < n; i++)cin >> heights[i];

	cout << f(n - 1, heights) << endl;


}

int main()
{


	int t = 1; cin >> t;
	while (t--) {
		solve();

	}

	return 0;
}