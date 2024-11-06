#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int

using namespace std;

const int maxbit = 20;


vector<int>parent;
vector<int>jump;
vector<bool>occupied;
vector<vector<int>>table;

void build(int n) {

	table[0] = parent;

	for (int i = 1; i <= maxbit; i++) {
		for (int j = 1; j <= n; j++) {
			
			table[i][j] = table[i - 1][ table[i-1][j] ];
		}
	}

}

int f(int c) {

	int u = jump[c];
	if (occupied[u]) {
		return 0;
	}

	int ans = 1;

	/*//brute force
	while (true) {

		int p = parent[cur];
		if (occupied[p] == false) {

			jmp++;
			cur = p;
		} else {
			break;
		}
	}*/

	for (int i = maxbit - 1; i >= 0; i--) {

		int p = table[i][u];

		if (occupied[p] == false) {

			ans += (1 << i);
			u = p;

		} else {

			
		}
	}

	occupied[u] = true;
	return ans;
}

int main()
{

	
	int n; cin >> n;
	parent.resize(n + 1);
	for (int i = 1; i <=n; i++) {

		cin >> parent[i];
	}

	jump.resize(n + 1);
	for (int i = 1; i <=n; i++) {

		cin >> jump[i];
	}

	occupied.resize(n + 1, false);
	occupied[0] = true;

	table.resize(maxbit + 1, vector<int>(n + 1));
	build(n);

	for (int i = 1; i <= n; i++) {
		int jmp = f(i);
		cout << jmp << endl;
	}

	return 0;
}