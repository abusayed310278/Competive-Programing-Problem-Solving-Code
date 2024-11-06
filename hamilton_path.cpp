#include<bits/stdc++.h>

using namespace std;

const int N = 10;

vector<int> gr[N];

map<pair<int, set<int>>, bool> mp;
int n, m;

bool dp(int cur, set<int> St) {

	if (St.size() == n) {
		return true;
	}
	if (mp.count({cur, St})) {
		return mp[ {cur, St}];
	}

	bool ans = false;
	for (auto x : gr[cur]) {
		//not in the set means not visited that node
		if (St.find(x) == St.end()) {

			set<int> temp = St;
			temp.insert(x);

			ans |= dp(x, temp);
		}
	}

	return mp[ {cur, St}] = ans;

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	bool hamiltonian_path = false;

	for (int i = 0; i < n; i++) {
		set<int> St;
		St.insert(i);
		hamiltonian_path |= dp(i, St);
	}

	cout << hamiltonian_path;

	return 0;
}