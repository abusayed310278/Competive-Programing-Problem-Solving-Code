#include<bits/stdc++.h>
using namespace std; 

class Graph{
	int n;
	unordered_map<string,list<pair<string,int>>>l;
public:
	Graph(int n){
		this->n=n;
	}
	void addEdge(string i,string j,int w,bool undir=true){
		l[i].push_back({j,w});
		if(undir){
			l[j].push_back({i,w});
		}
	}

	void printAdjList(){
		for(auto p:l){
			string city=p.first;
			cout<<city<<"->";
			list<pair<string,int>>nbrs=p.second;

			for(auto nbr:nbrs){
				string dest=nbr.first;
				int w=nbr.second;
				cout<<dest<<"->"<<w<<",";
			}
			cout<<endl;

		}
	}
	
	
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;
	Graph g(n);

	while(n--){
		string x,y;int w;cin>>x>>y>>w;
		g.addEdge(x,y,w);
	}

	g.printAdjList();
	
	return 0;
}

/*

5
A B 20
A C 10
A D 50
C D 4
B D 30	

*/