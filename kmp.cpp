#include<bits/stdc++.h>
using namespace std;

/*void fillLps(string str, lps[]) {

	int n = str.length(), len = 0;

	while (i < n) {
		if (str[i] == str[len]) { len++, lps[i] = len, i++; }

		else {
			if (len == 0)lps[i] =, i++;
			else {
				len = lps[len - 1];
			}
		}
	}
}*/

//Tc:O(n),Sc:O(n)
//alisha code 1st way
void KMPCaLL(string pat, string txt) {

	vector<int>lps(pat.size(), 0);
	//pat= aabaaabcaa
	//	   0123456789
	//lps calculatrion
	for (int i = 1; i < pat.size(); i++) {

		int j = lps[i - 1];
		while (j > 0 && pat[i] != pat[j]) {
			j = lps[j - 1];
		}
		if (pat[i] == pat[j])j++;
		lps[i] = j;
	}

	int n = txt.length();
	int m = pat.length();
	int i = 0, j = 0;
	vector<int>ans;

	//kmp
	while (i < n) {

		if (pat[j] == txt[i]) {i++; j++;}

		if (j == m) { ans.push_back(i - (m - 1)); j = lps[j - 1];}

		else if (pat[j] != txt[i]) {
			if (j == 0)i++;
			j = lps[j - 1];
		}
	}


	//print ans

	for (auto x : ans) {
		cout << x << " ";
	}
}


//Tc:O(n),Sc:O(n)
//alisha code 2nd way
/*void KMPCaLL(string pat, string txt) {

	int n = txt.length();
	int m = pat.length();
	string total = pat + "#" + txt;
	vector<int>lps(total.size(), 0);

	//lps calculatrion
	for (int i = 1; i < total.size(); i++) {

		int j = lps[i - 1];
		while (j > 0 && total[i] != total[j]) {
			j = lps[j - 1];
		}
		if (total[i] == total[j])j++;
		lps[i] = j;
	}

	vector<int>ans;

	for (int i = 0; i < total.size(); i++) {
		if (lps[i] == m) {
			ans.push_back(i - m - (m - 1));
		}
	}

	for (auto x : ans) {
		cout << x << " ";
	}
}*/

/*void KMP(string pat, string txt) {


	int N = txt.length();
	int M = pat.length();
	int lps[M];
	fillLps(pat, lps);

	int i = 0, j = 0;

	while (i < N) {

		if (pat[j] == txt[i])i++, j++;

		if (j == m) {cout << i - j << " "; j = lps[j - 1];}

		else if (i < N && pat[j] != txt[i]) {
			if (j == 0)i++;
			else
				j = lps[j - 1];
		}
	}


}
*/
int main()
{

	freopen("inputf.in", "r", stdin);
	// freopen("outputf.in", "w", stdout);

	string txt="abcabcd";
	string pat="abcd";
	// cin >> pat >> txt;
	// KMPCal(pat, txt);
	KMPCaLL(pat, txt);

	return 0;
}

/*
aaaab
aaa




*/