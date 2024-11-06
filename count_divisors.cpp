#include<bits/stdc++.h>
using namespace std;

void countDiv(int n) {

	// if (n % 2 != 0)cout << 2 << " ";

	int cnt = 0;
	for (int i = 1; i <= n; i++) {

		if (n % i == 0)cnt++;
	}

	cout << cnt;

}

void countDivs(int n) {

	// if (n % 2 != 0)cout << 2 << " ";

	int cnt = 2;//assuming n>1
	for (int i = 2; i * i <= n; i++) {

		if (n % i == 0) {
			if (n % i == i)cnt++; else cnt += 2;
		}
	}

	cout << cnt;

}

//O(sqrt(n))
void cntDivs(int n) {

	int res = 1;
	for (int i = 2; i * i <= n; i++) {

		int cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		res *= (cnt + 1);
	}


	if (n >= 2)res *= 2;

	cout << res;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);


	/*	int n; cin >> n;
		countDiv(n);*/

	int n; cin >> n;
	countDivs(n);

	return 0;
}


