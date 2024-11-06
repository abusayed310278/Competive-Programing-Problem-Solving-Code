#include<bits/stdc++.h>
using namespace std;


//O(n)
void divisiors(int n) {

	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)ans.push_back(i);
	}

	for (auto &x : ans) {
		cout << x << " ";
	}
}

//O(sqrt(n))
void Divisiors(int n) {

	vector<int>ans;
	for (int i = 1; i * i <= n; i++) {

		if (n % i == 0) {
			ans.push_back(i);

			if (i != n / i)ans.push_back(n / i);
		}
	}

	sort(ans.begin(), ans.end());
	for (auto &x : ans) {
		cout << x << " ";
	}
}

//more efficient
void DivisiorsMoreEfficient(int n) {

	int i;
	for (i = 1; i * i <= n; i++) {

		if (n % i == 0) {
			cout << i << " ";
		}
	}

	for (; i >= 1; i--) {
		if (n % i == 0)cout << n / i << " ";
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	/*	int n; cin >> n;
		divisiors(n);*/

	/*	int n; cin >> n;
		Divisiors(n);*/

	int n; cin >> n;
	DivisiorsMoreEfficient(n);

	return 0;
}


