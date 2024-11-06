#include<bits/stdc++.h>
using namespace std;

//from pepcoding videos : 2*x*x-12*x+7
double f(double x) {

	return 2 * x * x - 12 * x + 7;
}


double findMin(double l, double r) {

	while (r - l > 0.0000001) { // 1e-6

		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		double f1 = f(m1);
		double f2 = f(m2);

		if (f1 > f2) {
			l = m1;
		} else if (f1 < f2) {
			r = m2;
		} else {
			l = m1; r = m2;
		}

	}

	double ans = round(f(l));

	return ans;
}



int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	double l, r; cin >> l >> r;
	cout << findMin(l, r);

	return 0;
}

/*

Finding Min/Max value of a Unimodal Function using Ternary Search:
https://www.hackerearth.com/practice/algorithms/searching/ternary-search/practice-problems/algorithm/solve-with-ternary-search/


*/