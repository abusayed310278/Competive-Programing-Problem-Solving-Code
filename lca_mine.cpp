#include<bits/stdc++.h>
using namespace std;

const int N=100;
int dep[N],Par[N];

vector<int>gr[N];

//O(n)
void dfs(int cur,int par)
{
	Par[cur]=par;
	dep[cur]=dep[par]+1;
	for(auto x:gr[cur])
	{
		if(x!=par)dfs(x,cur);
	}
}

//Tc:O(n) ,for 1 LCA query
int LCA(int u,int v)
{
	if(u==v)return u;

	if(dep[u] <dep[v])swap(u,v);

	int diff=dep[u]-dep[v];

	while(diff--)u=Par[u];

	while(u!=v){
		u=Par[u];
		v=Par[v];
	}

	return u;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1,-1);
	cout<<LCA(9,12)<<endl; //O(n)
	cout<<LCA(10,8)<<endl;
	cout<<LCA(9,11)<<endl;

	return 0;
}

/*

11
1 2
1 3
2 4
2 5
2 6
4 10
5 8
8 9
8 11
3 7
7 12


*/