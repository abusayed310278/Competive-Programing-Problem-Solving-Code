#include<bits/stdc++.h>
using namespace std;



int MaximumSum(vector<int>&a) {
	//Code Here
	int maxi = 0, cur = 0;
	for (int i = 0; i < a.size(); i++) {

		cur += a[i];
		if (cur > maxi)maxi = cur;
		if (cur < 0)cur = 0;
	}

	return maxi;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>a;
	int n; cin >> n;

	while (n--) {
		int x; cin >> x;
		a.push_back(x);
	}

	cout << MaximumSum(a);

	return 0;
}