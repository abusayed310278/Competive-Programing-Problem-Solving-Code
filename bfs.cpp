#include<bits/stdc++.h>
using namespace std; 

class Graph{
	int n;
	list<int>*l;
public:
	Graph(int n){
		this->n=n;
		l=new list<int>[n];
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void printAdjList(){
		for(int i=0;i<n;i++){
			cout<<i<<"->";
			for(auto node:l[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int source)
	{
		queue<int>q;
		bool *visited=new bool[n]{0};
		
		q.push(source);
		visited[source]=true;

		while(!q.empty()){
			
			int f=q.front();
			cout<<f<<" ";
			q.pop();

			for(auto nbr:l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
		}
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;cin>>n;
	Graph g(n);

	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	//g.printAdjList();
	g.bfs(1);
	return 0;
}

/*

7
0 1
1 2
3 5
5 6
4 5
0 4
3 4

*/