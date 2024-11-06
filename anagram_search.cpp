#include<bits/stdc++.h>
using namespace std;

//Tc:theta(n)
bool stringRotation(string &s1, string &s2) {

	if (s1.length() != s2.length())return false;

	return ((s1 + s2).find(s2) != string::npos);
}

bool areSame(int a, int b) {
	return (a == b) ? true : false;
}

bool isPresent(string &txt, string &pat) {

	int ct[256] = {0}, cp[256] = {0};
	for (int i = 0; i < pat.length(); i++) {
		ct[txt[i]]++;
		cp[pat[i]]++;
	}

	for (int i = pat.length(); i < txt.length(); i++) {
		if (areSame(ct, cp)) {
			return true;
		}
		ct[txt[i]]++;
		ct[txt[i - pat.length()]]--;
	}
	return false;
}


int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s1, s2;
	cin >> s1 >> s2;
	// cout<<stringRotation(s1,s2);
	cout << isPresent(s1, s2);



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