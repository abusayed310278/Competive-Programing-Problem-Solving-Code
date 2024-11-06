#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
int d[N],h[N];
bool vis[N];
void dfs(int u,int par=0){ 
		
   	  			
  for(auto child:g[u])
  {
	if(child==par)continue;
  	d[child]=d[u]+1;
	dfs(child,u);
	h[u]=max(h[u],h[child]+1);
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
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" "<<h[i]<<endl;
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