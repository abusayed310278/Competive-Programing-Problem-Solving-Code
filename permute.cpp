#include<bits/stdc++.h>
using namespace std;


void permute(string &s, int l, int r) {

	if (l == r) {
		cout << s << endl;
	} else {

		for (int i = l; i <= r; i++) {

			swap(s[i], s[l]);
			permute(s, l + 1, r);
			swap(s[i], s[l]);
		}

	}


}

void perm(string &s, int i = 0) {

	if (i == s.length() - 1){ cout << s << endl; return; }

	for (int j = i; j < s.length(); j++) {
		swap(s[i], s[j]);
		perm(s, i + 1);
		swap(s[i], s[j]);
	}

}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string n; cin >> n;
	// permute(n,0,n.size()-1);
	perm(n);

	return 0;
}