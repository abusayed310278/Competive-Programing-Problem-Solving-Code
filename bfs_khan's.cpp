#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];

bool toposort(int u,int n)
{
	queue<int>q;
	vector<int>in(n,0);
	in[u]++;

	for(auto x:g[u]){
		in[x]++;
	}



}


int main(){


	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	int n;cin>>n;

	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);

	}
	

	return 0;
}

/*

13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

*/