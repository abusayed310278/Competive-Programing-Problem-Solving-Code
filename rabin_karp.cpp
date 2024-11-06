#include<bits/stdc++.h>
using namespace std;

/*
Naive pattern searching improve by gfg
=>improve Naive algorithm for distinct
*/

const int q = 1e9 + 10;
const int d = 5;

// Tc: O(n-m+1)
void RabinKarp(string txt, string pat) {

	int m, n;
	n = txt.length();
	m = pat.length();

	//
	int h = 1;
	////here,q is large prime number
	for (int i = 1; i <= m - 1; i++) { h = (h * d) % q; }

	//compute p and t respectively from pat and txt
	int p = 0, t = 0;
	for (int i = 0; i < m; i++)
	{
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}

	for (int i = 0; i <= n - m; i++)
	{
		//check for spurious hit
		if (p == t)
		{
			bool flag = true;
			for (int j = 0; j < m; j++)
			{
				if (txt[i + j] != pat[j]) { flag = false; break;  }

			}
			if (flag == true) { cout << i << " "; }
		}

		//compute Ti+1 using Ti
		if (i < n - m)
		{
			t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;

			if (t < 0) { t = t + q; }
		}
	}

}

int main()
{

	freopen("inputf.in", "r", stdin);
	// freopen("outputf.in", "w", stdout);

	string txt;
	string pat;
	cin >> txt >> pat;
	RabinKarp(txt, pat);

	return 0;
}

/*

abcabcd
abcd

abceabefabcd
abcd


*/