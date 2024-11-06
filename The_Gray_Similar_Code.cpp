#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int a[N];

int main()
{
	/*freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
*/
	int n; cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {

			cin >> a[i];

			answer ^= a[i];

	}


	if(answer==0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}


/*

5
1 0 2 3 7


*/