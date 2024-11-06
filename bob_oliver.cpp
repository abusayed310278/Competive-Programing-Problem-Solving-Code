#include<bits/stdc++.h>
using namespace std;

vector<int>in, out;
int timer;

void Resize(int n) {
	in.resize(n + 1);
	out.resize(n + 1);
}

void dfs(int u, int par, vector<int>g[]) {
	in[u] = timer++;
	for (auto nbr : g[u]) {
		if (nbr != par)dfs(nbr, u, g);
	}
	out[u]=timer++;
}

bool check(int x, int y) {

	return in[x] > in[y] and out[x] < out[y];
}

int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	Resize(n);
	timer = 1;

	vector<int>g[n + 1];

	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0, g);

	int q; cin >> q;
	while (q--) {

		int type, x, y; cin >> type >> x >> y;
		if(!check(y,x) and !check(x,y)){ cout<<"NO"<<endl; continue;}
		if(type==0){
			if(check(y,x)){cout<<"YES"<<endl;}else {cout<<"NO"<<endl;}
		}
		else if(type==1){
			if(check(x,y)){cout<<"YES"<<endl;}else {cout<<"NO"<<endl;}
		}

	}



	return 0;
}


/*

9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1


*/