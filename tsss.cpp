#include<bits/stdc++.h>
#define n 8
using namespace std;

int g[n][n];

stack<int>q;
static int visited[n]={0};

void input(){
	ifstream fp;
	fp.open("input.txt");
	
	int i,j;
    
	for(i=1;i<=n;i++){
	   for(j=1;j<=n;j++){
	      fp>>g[i][j];       	
	   }
	}
   
   fp.close();	

}

void dfs(int u){
	
   int v;
   if(visited[u]==0){
	 visited[u]=1;	
	for(v=1;v<=n;v++){
	   	
	    if(g[u][v]==1 && visited[v]==0) 
		dfs(v);

	}
   }	
   q.push(u);


}

void ts(){
	
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
	
	input();
	ts();


	return 0;
}