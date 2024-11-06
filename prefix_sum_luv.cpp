#include<bits/stdc++.h>
using namespace std;
/*
a array,Q query and in each query given L and R print sum of array elements
from index L to R(L,R inclusive)
Constraints:
1<=N<=10^5
1<=a[i]<=10^5
1<=Q<=10^5
1<=L,R<=N

*/

const int N = 1e5 + 10;
int a[N];
int pf[N];

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pf[i] = pf[i - 1] + a[i];
	}

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << pf[r] - pf[l - 1] << endl;

	}



	return 0;
}

/*
6
3 6 2 8 9 2
4
2 3
4 6
1 5
3 6

*/