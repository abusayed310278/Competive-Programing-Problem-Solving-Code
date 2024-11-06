#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int t; cin >> t;
	while (t--) {

		int l, r; cin >> l >> r;
		if (2 * l > r)
			cout << r << endl;
		else
			cout << -1 << endl;
	}



	return 0;
}


