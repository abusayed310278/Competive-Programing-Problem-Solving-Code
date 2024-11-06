#include<bits/stdc++.h>
using namespace std;

/*int power(int x, int n) {

	if (n == 0)return 1;

	int temp = power(x, n / 2);
	temp = temp * temp;

	if (n % 2 == 0)
		return temp;
	else
		return x * temp;
}*/

int power(int x, int n) {

	if (n == 0)return 1;

	int temp = power(x, n / 2);
	temp = temp * temp;

	if (n % 2 == 0)
		return temp;
	else
		return x * temp;
}


int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int x, n; cin >> x >> n;
	cout << power(x, n);

	return 0;
}

/*



*/