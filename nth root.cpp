#include<bits/stdc++.h>
using namespace std;

double eps = 1e-7;


void sqrtCalBs(int x) {

	double lo = 1, hi = x, mid;
	while (hi - lo > eps) {

		mid = (lo + hi) / 2;
		if (mid*mid < x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	//O(p*log(n*(10^decimal)))
	// cout << setprecision(10) << lo << endl << hi << endl; //cout<<hi<<endl;
	// cout << pow(x, 1.0 / 2) << endl;

	cout<<lo<<endl;

}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int x, n; cin >> x;
	sqrtCalBs(x);

	return 0;
}