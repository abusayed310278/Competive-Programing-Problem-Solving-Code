#include<bits/stdc++.h>

using namespace std;
const int N=1e7+5;

vector<int>gr[N];
int n;
stack<int>q;
int visited[N];

/*
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

}*/

void dfs(int u){

   //vector<int>::iterator v;
   if(visited[u]==0){
	 visited[u]=1;
	for(auto v:gr[u]){

	    if(visited[v]==0)
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
	#ifndef ts
		freopen("inp.txt","r",stdin);
		freopen("outp.txt","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);

	}

	ts();


	return 0;
}
