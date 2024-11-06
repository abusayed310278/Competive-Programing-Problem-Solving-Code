#include<bits/stdc++.h>
using namespace std;



int nineDivisors(int n) {
	//Code Here

	int ans = 0;
	for (int i = 9; i <= n; i++) {

		int x = 1, cnt = 0;
		while (i > 0) {
			if(x>i)continue;
			if (i % x == 0)cnt++;
			i /= x;
			x++;
		}
		if (cnt == 9)ans++;
	}
	return ans;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	cout << nineDivisors(n);

	return 0;
}