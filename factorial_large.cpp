#include<bits/stdc++.h>
using namespace std;


void f(int n) {
	
	vector<int>ans;
	ans.push_back(1);
	for (int x = 2; x <= n; x++) {
		int car = 0;
		for (int i = 0; i < ans.size(); i++) {
			int val = ans[i] * x + car;
			ans[i] = val % 10;
			car = val / 10;
		}
		while (car != 0) {
			ans.push_back(car % 10);
			car /= 10;
		}
	}
	reverse(ans.begin(),ans.end());

	for (auto x : ans) {
		cout << x;
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	int n; cin >> n;

	f(n);
	return 0;
}