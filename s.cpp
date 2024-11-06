#include<bits/stdc++.h>
using namespace std;
#define inf 1e5+10


int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n;
	cin >> n; int ans = 0;

	while (n != 0) {

		int sum = 0;
		while (n != 0) {
			sum += n % 10;
			n /= 10;
		}
		n = sum;
		if (n < 10) {
			ans = n;
			break;
		}
	}
	cout << ans << endl;


	return 0;
}


/*

6 7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1


*/