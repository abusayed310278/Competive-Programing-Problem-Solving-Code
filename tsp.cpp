#include<bits/stdc++.h>
using namespace std;

int n=4;
vector<vector<int>>dp(1<<n,vector<int>(n,-1));

//Tc:O(2^n*n*n)
int tsp(vector<vector<int>>dist, int setOfCities, int city, int n) {

	if (setOfCities == (1 << n) - 1) {
		return dist[city][0];
	}

	if(dp[setOfCities][city]!=-1){
		dp[setOfCities][city];
	}

	int ans = INT_MAX;

	for (int choice = 0; choice < n; choice++) {
		if ((setOfCities & (1 << choice)) == 0) {
			int subprob = dist[city][choice] + tsp(dist, setOfCities | (1 << choice), choice, n);
			ans = min(ans, subprob);
		}
	}
	// dp[setOfCities][city]=ans;
	return dp[setOfCities][city]=ans;
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	vector<vector<int>>dist = {
		{0, 20, 42, 25},
		{20, 0, 30, 34},
		{42, 30, 0, 10,},
		{25, 34, 10, 0}

	};

	cout << tsp(dist, 1, 0, 4) << endl;

	return 0;
}