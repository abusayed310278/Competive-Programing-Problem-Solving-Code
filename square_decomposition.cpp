#include<bits/stdc++.h>
using namespace std;


//sum using by square decomposition
int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	int m = sqrt(n) + 1;

	int a[n], b[m];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i / m] += a[i];
	}

	int q; cin >> q;
	
	while (q--) {
		int l, r, ans = 0;
		cin >> l >> r;

		for (int i = l; i <= r;) {

			if (i % m == 0 and i + m - 1 <= r) {
				ans += b[i / m];
				i += m;
			} else {
				ans += a[i];
				i++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

/*

10
5 2 4 9 1 8 3 10 6 7 
3
0 4
2 6
3 9



*/