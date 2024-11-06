#include<bits/stdc++.h>
using namespace std;

// longest substring with distinct characters

bool areDistinct(string &str, int i, int j) {

	vector<bool>visited(256);
	for (int k = i; k <= j; k++) {
		if (visited[str[i]] == true) {
			return false;
		}
		visited[str[i]] = true;
	}
	return true;

}

//Naive approach: O(n^3)
int LSWDC(string &str) {

	int n = str.length(), res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (areDistinct(str, i, j)) {
				res = max(res, j - i + 1);
			}
		}
	}
	return res;
}

// Tc: O(n^2)
int LongestDistinct(string &str) {
	int n = str.length();
	int res = 0;
	vector<bool>visited(256);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (visited[j] == true) {
				break;
			} else {
				res = max(res, j - i + 1);
				visited[j] = true;
			}
		}
	}
	return res;
}

int longestDist(string &str) {

	int n = str.length(), res = 0;
	vector<int>prev(256, -1);
	int i = 0;

	for (int j = 0; j < n; j++) {
		i = max(i, prev[str[j]] + 1);
		int maxEnd = j - i + 1;
		res = max(res, maxEnd);
		prev[str[j]] = j;
	}
	return res;
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1;
	cin >> s1;
	// cout << LSWDC(s1);
	cout << LongestDistinct(s1);

	return 0;
}

/*

abcd
cdab

abaaa
baaaa

abab
abba

*/