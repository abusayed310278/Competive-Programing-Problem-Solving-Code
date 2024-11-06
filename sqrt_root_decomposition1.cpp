#include<bits/stdc++.h>
using namespace std;


//for min find : pepcoding

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	int a[n];
	int m;
	m = sqrt(n) + 1;

	int b[m];
	memset(b, INT_MAX, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i / m] = min(a[i], b[i / m]);
	}

	int q; cin >> q;
	while (q--) {
		int l, r, ans = INT_MAX; cin >> l >> r;

		for (int i = l; i <= r;) {
			if (i % m == 0 and i + m - 1 <= r) {
				ans = min(ans, b[i / m]);
				i += m;
			} else {
				ans = min(ans, a[i]);
				i++;
			}
		}
		cout << ans << endl;
	}


	return 0;
}



/*

4
2 4 3 1
4
1 2
1 3 
2 2
0 1



*/