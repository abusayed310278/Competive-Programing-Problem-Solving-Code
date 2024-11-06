#include<bits/stdc++.h>
using namespace std;


/*
=>is s2 is subsequence of s1
Tc:O(n+m)
Sc:O(1)


*/
bool isSubsequence(string &s1, string &s2) {

	int n = s1.length(), m = s2.length();

	if (n < m)return false;

	int j = 0;
	for (int i = 0; i < n && j < m; i++) {
		if (s1[i] == s2[j]) {
			j++;
		}
	}
	if (j == m) {
		return true;
	}
	return false;
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1, s2; cin >> s1 >> s2;
	cout << isSubsequence(s1, s2);
	return 0;
}

/*
abcd
da
abcd
ad

*/