#include<bits/stdc++.h>
using namespace std;

/*void modInv(int a, int m) {


	for (int x = 1; x < m; x++) {
		if ((a * x) % m == 1){

			cout << x <<endl;
			return;
		}
	}
	cout << "does not exists";
}*/




int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int a, m; cin >> a >> m;
	modInv(a, m);

	return 0;
}