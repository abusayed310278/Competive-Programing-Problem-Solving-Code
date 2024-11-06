#include<bits/stdc++.h>
using namespace std;

const int N= 1e7+5;

vector<int>visited(N);
vector<int>gr[N];
stack<int>q;
class Solution{
public:
	int n;
	
	Solution(int n){
		this->n=n;
		
	}
	
	void ts();	
	void dfs(int u);
	/*
	*/
	//vector<int> input();
	void print();
	
};

/*vector<int> Solution:: input()
{
		#ifndef tss
			freopen("in.txt","r",stdin);
			//freopen("out.txt","w",stdout);

		#endif	
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			gr[i].push_back(y);
		}
		//print(gr);
		return gr;
}	*/

void Solution:: print(){

	for(int i=0;i<n;i++){
		
		for(auto x:gr[i])
			cout<<i<<"->"<<x<<endl;
	}
}

void Solution:: dfs(int u){
	
    
	if(visited[u]==0){
		 visited[u]=1;	
		for(int v=1;v<=n;v++){
		   	
		    if(gr[u][v] && visited[v]==0) 
			dfs(v);

		}
   }	
   q.push(u);
}

	
void Solution:: ts(){
		
	for(int i=1;i<=n;i++){
	    if(visited[i]==0)
		dfs(i);
	}
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
}

int main()
{
		#ifndef tss
			freopen("in.txt","r",stdin);
			//freopen("out.txt","w",stdout);

		#endif	

		int n;cin>>n;
		vector<int>gr[n];
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			gr[x].push_back(y);
		}
	/*for(int i=0;i<n;i++){
		cout<<v[i]<<endl;
	}*/

	Solution ob(n);
	ob.ts();
	ob.print();
	return 0;
}