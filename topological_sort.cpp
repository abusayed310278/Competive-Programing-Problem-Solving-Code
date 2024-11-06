#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int n;	
	Solution(int n){
		this->n=n;
	}
	vector<int>visited(n)={false};
	

	/*for(int i=0;i<n;i++){
		
		for(auto v:gr[i])
			cout<<i<<"->"<<v<<endl;
	}*/	


	
};	

Solution::void dfs(int u){
	
    	int v;
	if(visited[u]==0){
		 visited[u]=1;	
		for(v=1;v<=n;v++){
		   	
		    if(g[v] && visited[v]==0) 
			dfs(v);

		}
   }	
   q.push(u);
}

Solution::void input(int n)
{
		#ifndef tss
			freopen("in.txt","r",stdin);
			//freopen("out.txt","w",stdout);

		#endif
		vector<int>gr[n];	
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			gr[x].push_back(y);
		}
}		


Solution::void ts(){
	
	int i,j;	
	for(i=1;i<=n;i++){
	    if(visited[i]==0)
		dfs(i);
	}
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	

}

int main(){
	int n;
	Solution ob;
	cin>>n;
	ob.n=n;
	ob.input();
	ob.ts();


	return 0;
}