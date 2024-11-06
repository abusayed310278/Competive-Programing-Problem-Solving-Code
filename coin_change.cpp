#include<bits/stdc++.h>
using namespace std;

void coinchange(vector<int>& coins) {

	int cur_coin = (int)coins.size() - 1;
	vector<int>ans;
	int changeRemaning = 9;

	while (changeRemaning > 0 && cur_coin >= 0 ) {
		while (cur_coin >= 0 && coins[cur_coin] > changeRemaning) 
			cur_coin--;
		
		changeRemaning -= coins[cur_coin];
		ans.push_back(coins[cur_coin]);

	}

	for (wchar_t i=0;i<ans.size();i++) {
		cout << ans[i] << " ";
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<int>coins;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		coins.push_back(x);
	}

	coinchange(coins);
}