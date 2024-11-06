#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n){

	visited[i][j]=true;
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};

	int cs=1;
	//4 way dfs call
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny]==1 and !visited[nx][ny]){
			int subcomponent=dfs(grid,visited,nx,ny,m,n);
			cs+=subcomponent;
		}
	}
	return cs;
}

int largest_island(vector<vector<int>>grid)
{
	int m=grid.size();
	int n=grid[0].size();
	int largest=0;
	vector<vector<int>>visited(m,vector<int>(n,0));

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j] and grid[i][j]==1){
				int size=dfs(grid,visited,i,j,m,n);
				if(size>largest)
					largest=size;
			}
		}
	}
	return largest;
}

int main()
{

	vector<vector<int>>grid={
		{1,0,0,1,0},
		{1,0,1,0,0},
		{0,0,1,0,1},
		{1,0,1,1,1},
		{1,0,1,1,0}
	};

	cout<<largest_island(grid)<<endl;

	return 0;
}