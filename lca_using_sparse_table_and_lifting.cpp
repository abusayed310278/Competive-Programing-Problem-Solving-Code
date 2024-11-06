#include<bits/stdc++.h>
using namespace std;

//optimization of Binary lifting Amal Paul

const int N=1e5,M=20;
int dep[N],Par[N][M];

vector<int>gr[N];



//O(N*M)
void dfs(int cur,int par)
{
	Par[cur][0]=par;

	dep[cur]=dep[par]+1;

	for(int j=1;j<M;j++){
		Par[cur][j]=Par[Par[cur][j-1]][j-1];
	}


	for(auto x:gr[cur])
	{
		if(x!=par)dfs(x,cur);
	}
}

//Tc:O(M) ,WHERE M=logN
int LCA(int u,int v)
{
	if(u==v)return u;

	if(dep[u] <dep[v])swap(u,v);

	int diff=dep[u]-dep[v];

	for(int j=M-1;j>=0;j--){
		if((diff>>j)&1){
			u=Par[u][j];
		}
	}


	for(int j=M-1;j>=0;j--){
		if(Par[u][j]!=Par[v][j]){
			u=Par[u][j];
			v=Par[v][j];

		}
	}
	//return Par[v][0];
	return Par[u][0];
}

int lengthofUtoV(int u,int v)
{
	int lca=LCA(u,v);

	return dep[u]+dep[v]-2*dep[lca];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1,0);
	cout<<LCA(9,12)<<endl; //O(n)
	cout<<LCA(10,8)<<endl;
	cout<<LCA(9,11)<<endl;
	cout<<"length="<<lengthofUtoV(9,12)<<endl;

	/*for(int i=1;i<=n;i++){
		cout<<i<<"->";
		for(int j=0;j<4;j++){
			cout<<Par[i][j]<<" ";
		}
		cout<<endl;
	}*/

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