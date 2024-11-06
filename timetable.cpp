#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>>& sub) {

	int n = (int)sub.size();
	sort(sub.begin(), sub.end());

	int maxsub = 1, curtime = sub[0].first;
	for (int i = 0; i < n; i++) {
		if (curtime <= sub[i].second) {
			maxsub++;
			curtime = sub[i].first;
		}
	}
	return maxsub;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n;
	vector<pair<int, int>>sub;
	while (cin >> n) {

		if (n == 0) {cout << 0; continue;}

		for(int i=0;i<n;i++){ cin>>sub[i].second>>sub[i].first; }
	}
	
	solve(sub);
}