#include<bits/stdc++.h>
using namespace std; 

//backedge find code by preetk narang
class Graph{
	int n;
	list<int>*l;
public:
	Graph(int n){
		this->n=n;
		l=new list<int>[n];
	}
	void addEdge(int i,int j,bool undir=false){
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
	bool dfsHelper(int node,vector<bool>& visited,vector<bool>& stack){
		visited[node]=true;
		stack[node]=true;// here this stack name actually a normal array or vector

		//do some work at node ,return true if backedge is found here itself
		for(auto nbr:l[node]){
			if(stack[nbr]==true)return true;
			else if(visited[nbr]==false){
				bool nbrFoundACycle=dfsHelper(nbr,visited,stack);
				if(nbrFoundACycle)return true;
			}
		}
		//going back
		stack[node]=false;
		return false;	
	}

	bool contains_cycle(){
		vector<bool>visited(n,false);
		vector<bool>stack(n,false);
		for(int i=0;i<n;i++)
			if(dfsHelper(i,visited,stack))return true;
		return false;
	}
	
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;cin>>n;
	Graph g(n);

	while(n--){
		int x,y;cin>>x>>y;
		g.addEdge(x,y);
	}

	//g.printAdjList();
	cout<<g.contains_cycle();
	return 0;
}

/*

3
0 1
1 2
2 0

*/