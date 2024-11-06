#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	map<int,bool>visited;
	map<int,list<int>>adj;

	void addEdge(int x,int y){
		adj[x].push_back(y);
	}

	void print(){
		for(auto p:adj){
			cout<<p.first<<"->";
			auto it=adj.begin();
			cout<<*it;
		}
	}



};


int main()
{
	Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
 

	return 0;
}

