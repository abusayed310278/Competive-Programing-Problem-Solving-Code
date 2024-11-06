#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
bool vis[N];
int level[N];

void dfs(int u){ 
		
	  cout<<u<<" ";
  	  // cout<<" :level "<<level[u]<<endl;
	  
	  // if(vis[u])return;
	  vis[u]=true;
	  // level[u]=0;	  			
	  for(auto child:g[u])
	  {
	  	// cout<<"par"<<u<<" "<<"child"<<" "<<child<<endl;
	  	level[child]=level[u]+1;
		if(vis[child])continue;
		dfs(child);
		
	  }

}

int main(){


	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	int n;cin>>n;

	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);

	}
	memset(vis,false,sizeof(vis));
	memset(level,0,sizeof(level));
	dfs(1);
	cout<<endl;

	for(int i=1;i<=n;i++){
		cout<<level[i]<<" ";
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