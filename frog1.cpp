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

vi h;
const int N = 1e5 + 5;
int dp[N];

int f(int i) {

	if (i == 0)return 0;
	if (dp[i] != -1)return dp[i];

	int cost = INT_MAX;

	cost = abs(h[i] - h[i - 1]) + f(i - 1);


	if (i > 1)
		cost = min(cost, abs(h[i] - h[i - 2]) + f(i - 2));

	return dp[i] = cost;
}




void solve() {

	int n; cin >> n;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << f(n - 1) << endl;



}

void tabular() {


	int n; cin >> n;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vi dp(n, 0);
	int cost = INT_MAX;


	for (int i = 1; i <= n - 1; i++) {

		int a = abs(h[i] - h[i - 1]) + dp[i - 1];
		int b = INT_MAX;
		if (i > 1)b = abs(h[i] - h[i - 2]) + dp[i - 2];


		dp[i] = min(a, b);


	}



	cout << dp[n - 1] << endl;
}

//space optimization
void sco() {


	int n; cin >> n;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int prei = 0;
	int pre2i = 0;


	for (int i = 1; i <= n - 1; i++) {

		int a = abs(h[i] - h[i - 1]) + prei;
		int b = INT_MAX;
		if (i > 1)b = abs(h[i] - h[i - 2]) + pre2i;


		int curi = min(a, b);
		pre2i = prei;
		prei = curi;

	}



	cout << prei << endl;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) {
		// solve();
		// tabular();
		sco();

	}

	return 0;
}