#include<bits/stdc++.h>

using namespace std;

const int N = 10;

vector<int> gr[N];
int memo[N][1<<N];
int n, m;

//top down approach 

bool dp(int cur, int mask) {

	if (mask == (1<<n)-1) {
		return true;
	}
	if (memo[cur][mask]!=-1) {
		return memo[cur][mask];
	}

	bool ans = false;
	for (auto x : gr[cur]) {
		//not in the set means not visited that node
		if (!((mask>>x)&1)) {
			ans |= dp(x,mask |(1<<x));
		}
	}

	return memo[cur][mask] = ans;

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	memset(memo,-1,sizeof(memo));

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	bool hamiltonian_path = false;

	for (int i = 0; i < n; i++) {
		hamiltonian_path |= dp(i, 1<<i);
	}

	cout << hamiltonian_path;

	return 0;
}