#include<bits/stdc++.h>
using namespace std;

//Tc:O(n)
const int CHAR = 256;
bool anagramCheck(string &s1, string &s2) {

	if (s1.length() != s2.length())return false;

	int count[CHAR] = {0};
	for (int i = 0; i < s1.length(); i++) {
		count[s1[i]]++;
		count[s2[i]]--;
	}

	for (int i = 0; i < CHAR; i++) {
		if (count[i] != 0) {
			return false;
		}
	}
	return true;
}

//Naive approach,Tc: O((n-m+1)*m)
bool anagramCheckCall(string &txt, string &pat, int i) {

	if (s1.length() != s2.length())return false;

	int count[CHAR] = {0};
	for (int j = 0; j < s1.length(); j++) {
		count[pat[j]]++;
		count[txt[i+j]]--;
	}

	for (int j = 0; j < CHAR; j++) {
		if (count[j] != 0) {
			return false;
		}
	}
	return true;
}

//Tc: O((n-m+1)*m) ,Naive approach 
bool isPresent(string s1, stirng s2) {

	int n = s1.length();
	int m = s2.length();

	for (int i = 0; i <= n - m; i++) {
		if (anagramCheckCall(s1, s2, i)) {
			return true;
		}
	}
	return false;
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1, s2;
	cin >> s1 >> s2;
	// cout<<anagramCheck(s1,s2);
	cout << isPresent(s1, s2);

	return 0;
}

/*

listen
silent

aab
bab


*/