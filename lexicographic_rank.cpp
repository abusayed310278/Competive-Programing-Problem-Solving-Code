#include<bits/stdc++.h>
using namespace std;

const int CHAR = 256;

/*
=>let,all characters are distinct.
*/

int fact(int &n) {

	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}

	return res;
}

int lexRank(string &str) {
	int n = str.length();

	int count[CHAR] = {0};
	for (int i = 0; i < n; i++) {
		count[str[i]]++;
	}

	for (int i = 1; i < CHAR; i++) {
		count[i] += count[i - 1];
	}

	int res = 1;
	int mul = fact(n);

	for (int i = 0; i < n - 1; i++) {
		mul /= (n - i);
		res += count[str[i] - 1] * mul;
		for (int j = str[i]; j < CHAR; j++) {
			count[j]--;
		}
	}
	return res;

}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string str; cin >> str;
	cout << lexRank(str);

	return 0;
}

/*

bac
cba
dcba
string


*/