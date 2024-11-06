#include<bits/stdc++.h>
using namespace std;

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string str = "abc";
	int n = str.size();
	for (int i = 0; i < (1 << n); i++) {

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				cout << str[j];
			}
		}
		cout<<endl;
	}

	return 0;
}