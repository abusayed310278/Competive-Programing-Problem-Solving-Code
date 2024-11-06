#include<bits/stdc++.h>
#define int long long 
using namespace std;



int computeHash(string &s) {

	int pr = 1;
	int mod = 1e9 + 7;
	int hash = 0;

	for (int i = 0; i < s.size(); i++) {
		hash = (hash + ((s[i] - 'a' + 1) * pr) % mod) % mod;
		pr = (pr * 31) % mod;
	}

	return hash;
}

int32_t main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s; cin >> s;
	cout<<s;

	cout << computeHash(s);
	return 0;
}