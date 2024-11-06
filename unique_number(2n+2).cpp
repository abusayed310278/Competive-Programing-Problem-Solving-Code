#include<bits/stdc++.h>
using namespace std;

#define bitsize 10
/*
	unique number,given 2n+2 numbers where every number comes twice expect one number.
	find out that unique number.

	Tc:O(n); Sc:O(1)
*/

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>val{3, 5, 6, 1, 5, 6, 3, 8};
	int ans = 0, res1 = 0, res2 = 0;
	
	for (int i = 0; i < val.size(); i++) {
		ans = ans ^ val[i];
	}

	ans = ans & (~(ans - 1));
	for (int i = 0; i < val.size(); i++) {

		if ((ans & val[i]) != 0)
			res1 ^= val[i];
		else
			res2 ^= val[i];
	}
	cout << res1 << " " << res2 << endl;
	return 0;
}