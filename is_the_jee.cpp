#include<bits/stdc++.h>
using namespace std;

//from pepcoding videos : (x * x + b * x + c) / sin(x)
double f(double x, double b, double c) {

	return (x * x + b * x + c) / sin(x);
}


double findMin(double l, double r) {

	double b, c; cin >> b >> c;
	while (r - l > 0.0000001) { // 1e-6

		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		double f1 = f(m1, b, c);
		double f2 = f(m2, b, c);

		if (f1 > f2) {
			l = m1;
		} else if (f1 < f2) {
			r = m2;
		} else {
			l = m1; r = m2;
		}

	}

	// double ans = round(f(l,b,c));
	double ans = f(l, b, c);

	return ans;
}



int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	double pi = 2 * acos(0.0);
	double l = 0, r = pi;

	cout << findMin(l, r);

	return 0;
}

/*

Finding Min/Max value of a Unimodal Function using Ternary Search:
https://www.codechef.com/problems/ICM2003

*/