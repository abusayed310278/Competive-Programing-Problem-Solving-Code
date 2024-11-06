#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
bool vis[N];

bool dfsHelper(int vertex,int par)
{
	vis[vertex]=true;
	for(auto child:g[vertex])
	{
		if(!vis[child] &&	dfsHelper(child,vertex)){
			return true;
		}
		
		else if(child!=par){
			return true;
		}
	}
	return false;

}


bool dag(int vertex)
{
		
	for(int child:g[vertex]){
		if(!vis[child] &&	dfsHelper(child,-1)){
			return true;
		}
	}	
	return false;		
	
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
	
	cout<<dag(1)<<endl;
	
	

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