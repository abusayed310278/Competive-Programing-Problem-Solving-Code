#include<bits/stdc++.h>
using namespace std;

/*int fact(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++)ans *= i;

	return ans;
}
void ncr(int n, int r) {

	cout<< fact(n) / (fact(r) * fact(n - r));
}*/


/*void ncr(int n, int r) {

	int ans = 1;
	for (int i = n; i >= (n - r + 1); i--)ans *= i;

	for (int i = 2; i <= r; i++)ans /= i;

	cout << ans;
}*/


/*int ncr(int n, int r) {

	if (n < r)return 0;
	if (n == 1)return 1;
	if (r == 1)return n;
	if (r == 0)return 1;


	return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
*/

/*int ncr(int n, int r) {

	int m=1e9+7;

	int dp[n + 1][r + 1];
	for (int i = 0; i <= n; i++) {

		dp[i][0] = 1;
		for (int j = 1; j <= min(i, r); j++) {

			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] )%m;
		}
	}
	return dp[n][r];
}*/

/*int ncr(int n, int r) {

	

	int dp[r + 1] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {

		for (int j = min(i, r); j > 0; j--) {

			dp[j] = (dp[j - 1] + dp[j] );
		}
	}
	return dp[r];
}*/




int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n, r; cin >> n >> r;
	cout << ncr(n, r);

	return 0;
}