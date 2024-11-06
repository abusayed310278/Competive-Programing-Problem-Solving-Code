#include<bits/stdc++.h>
using namespace std;


//find out connected component for undirected graph
template<typename T>

class Graph{
	int n;
	map<T,list<T>>l;
public:
	Graph(int n){
		this->n=n;
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}


	void dfsHelper(T src,map<T,bool>& visited){
		visited[src]=true;
		cout<<src<<" ";
		for(auto nbr:l[src]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
	}

	void dfs(){
		map<T,bool>visited;
		for(auto p:l){
			T node=p.first;
			visited[node]=false;
		}

		int cnt=0;
		for(auto p:l){
			T node=p.first;
			if(!visited[node]){
				cout<<"component: "<<cnt<<"-->";
				dfsHelper(node,visited);
				cnt++;
				cout<<endl;
			}

		}
		cout<<"total component: 
		"<<cnt<<endl;
	}


};

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;

	Graph<int>g(n);
	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}
	g.dfs();

	return 0;
}