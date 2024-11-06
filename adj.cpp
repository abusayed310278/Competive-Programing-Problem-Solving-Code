#include<bits/stdc++.h>
using namespace std;

class Graph{
	int n;
	unordered_map<int,int>m;
public:
	Graph(int n){
		this->n=n;
	}
	void addEdge(int x,int y,bool undir=true){
		//m[x]=y;
		m.insert({x,y});
	}

	void printAdjList(){
		for(auto p:m){
			cout<<p.first<<" "<<p.second;
			cout<<endl;
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

	g.printAdjList();
	return 0;
}

/*

4
0 1
0 2
1 3
2 3

*/