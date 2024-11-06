#include<bits/stdc++.h>
using namespace std;

//using djkastra algorithms
class Node{
public:
	int x,y,w;
	Node(int x,int y,int dist){
		this->x=x;
		this->y=y;
		this->w=w;
	}
};
class Compare{
public:
	bool operator()(const Node &a,const Node &b){
		return a.w<=b.w;
	}
};

class Graph{
	int n;
public:
	Graph(int n){
		this->n=n;
	}


	int shortest_path(vector<vector<int>> grid)
	{

		int m=grid.size();
		int n=grid[0].size();
		int i=0,j=0;

		//2d vector to denote of each cell
		vector<vector<int>>dist(m+1,vector<int>(n+1,INT_MAX));
		dist[i][j]=grid[0][0];
		set<Node,Compare>s;
		s.insert(Node(0,0,dist[0][0]));

		int dx[]={0,0,1,-1};
		int dy[]={1,-1,0,0};

		while(!s.empty()){
			auto it=s.begin();
			int cx=it->x;
			int cy=it->y;
			int cd=it->w;
			s.erase(it);

			for(int k=0;k<4;k++)
			{
				int nx=cx+dx[k];
				int ny=cy+dy[k];

				if(nx>=0 and nx<m and ny<n and cd+grid[nx][ny] <dist[nx][ny])
				{
					//remove the old node if it exist
					Node temp(nx,ny,dist[nx][ny]);
					if(s.find(temp)!=s.end())s.erase(s.find(temp));
				}

				//insert the new node in the set
				int nd=grid[nx][ny]+cd;
				dist[nx][ny]=nd;
				s.insert(Node(nx,ny,nd));

			}
		}

		return dist[m-1][n-1];

	}

};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;

	Graph g(n);

	//vector<vector<int>>grid(n,vector<int>(n,0));
	//vector<int>grid[n];
	vector<vector<int>>grid={
		{31,100,65,12,18},
		{10,13,47,157,6},
		{100,113, 174, 11, 33},
		{88 ,124, 41, 20, 140},
		{99 ,32, 111 ,41 ,20}

	};

	//grid.clear();
	/*for (int i = 0; i < n; i++)
    {
    	vector<int>v1;
        for (int j = 0; j < n; j++)
        {	int x;cin>>x;
        	v1.push_back(x);    
        }   
        grid.push_back(v1);
        v1.clear();
    }*/

	/*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {	int x;cin>>x;
        	grid[i][j]=x;
        }   
        
    }*/

    cout<<g.shortest_path(grid);

    /*for(auto p:grid){
    	for(auto x:p){
    		cout<<x<<" ";
    	}
    	cout<<endl;
    }*/

	/*for(int i=0;i<n;i++){
		for(int j=0;j<grid[i].size();j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}*/

	return 0;
}

/*

5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20


*/