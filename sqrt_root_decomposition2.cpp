#include<bits/stdc++.h>
using namespace std;


//for sum and point update find : pepcoding

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	int a[n];
	int m;
	m = sqrt(n) + 1;

	int b[m];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i / m] += a[i];
	}

	int q; cin >> q;
	while (q--) {
		int l, r, ans = 0;

		char s; cin >> s;
		if (s == 'f') {
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

5
1 5 3 9 -2
3
f 0 4
u 2 3
f 0 4

*/