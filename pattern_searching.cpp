#include<bits/stdc++.h>
using namespace std;

/*
Naive pattern searching by gfg
*/

// Tc: O((n-m+1)*m)
void patternSearch(char *txt,char *p) {

	int n = strlen(txt);
	int m = strlen(p);
	int j;

	for (int i = 0; i <= n - m; i++) {

		for (j = 0; j < m; j++) {
			if (txt[i + j] !=  p[j]){
				break;
			}
		}
		// cout<<j<<" "<<i<<endl;

		if (j == m)
			cout << i << " ";

	}
	
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	char txt[]="aaaaa";
	char p[]="aaa";
	patternSearch(txt, p);

	return 0;
}

/*
abababcd
ab
*/