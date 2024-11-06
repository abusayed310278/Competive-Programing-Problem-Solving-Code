#include<bits/stdc++.h>
using namespace std;


//for sum and point update find : pepcoding

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	int q; cin >> q;
	int a[n];
	int m;
	m = sqrt(n) + 1;

	int b[m];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i / m] &= a[i];
	}

	while (q--) {
		int l, r, ans = 0;

		int s; cin >> s;
		if (s == 0) {
			cin >> l >> r;
			for (int i = l; i <= r;) {
				if (i % m == 0 and i + m - 1 <= r) {
					ans +=  b[i / m];
					i += m;
				} else {
					ans += a[i];
					i++;
				}
			}
			cout << ans << endl;
		} else {
			int idx, val; cin >> idx >> val;
			a[idx] += val;
			b[idx / m] += val;
		}
	}


	return 0;
}


/*

5 5
1 5 2 3 4
0 2 5
1 1 5 6
0 2 2
1 2 5 3
0 1 3


*/