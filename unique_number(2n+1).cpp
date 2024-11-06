#include<bits/stdc++.h>
using namespace std;

#define bitsize 10
/*
	unique number,given 2n+1 numbers where every number comes twice expect one number.
	find out that unique number.

	Tc:O(n); Sc:O(1)
*/

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>val{3, 5, 6, 1, 5, 6, 3};
	int ans = 0;
	for (int i = 0; i < val.size(); i++) {

		ans = ans ^ val[i];
	}
	cout << ans << endl;
	return 0;
}