#include<bits/stdc++.h>
using namespace std;

double eps = 1e-7;

double multiply(double mid, int n) {
	double ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= mid;
	}
	return ans;
}

void sqrtCalBs(int x, int n) {

	double lo = 1, hi = x, mid;
	while (hi - lo > eps) {

		mid = (lo + hi) / 2;
		if (multiply(mid, n) < x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	//O(p*log(n*(10^decimal)))
	cout << setprecision(10) << lo << endl << hi << endl; //cout<<hi<<endl;
	cout << pow(x, 1.0 / n) << endl;

}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int x, n; cin >> x >> n;
	sqrtCalBs(x, n);

	return 0;
}