#include<bits/stdc++.h>
using namespace std;

/*
Naive pattern searching improve by gfg
=>improve Naive algorithm for distinct
*/

// Tc: O(n)
void patternSearch(string txt,string p) {

	int n = txt.length();
	int m = p.length();
	int j;

	for (int i = 0; i <= n - m;) {

		for (j = 0; j < m; j++) {
			if (txt[i + j] !=  p[j]){
				break;
			}
		}
		// cout<<j<<" "<<i<<endl;

		if (j == m)
			cout << i << " ";
		if(j==0)
			i++;
		else
			i=i+j;

	}
	
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string txt;
	string p;
	cin >> txt >> p;
	patternSearch(txt, p);

	return 0;
}

/*

abcabcd
abcd

abceabefabcd
abcd


*/