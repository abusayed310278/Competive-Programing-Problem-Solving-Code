#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string name;
	list<string>nbrs;
	Node(string name){
		this->name=name;
	}
};

class Graph{
	//all nodes
	//hashmap(string,node*)
	unordered_map<string,*Node>m;
public:
	Graph(vector<string>cities){
		for(auto city:cities){
			m[city]=new Node(city);
		}
	}
	void addEdge(string x,string y,bool undir=false){
		m[x]->nbrs.push_back(y);

		if(undir){
			m[y]->nbrs.push_back(x);
		}
	}
	void printAdjList(){
		for(auto cityPair:m){
			auto city=cityPair.first;
			Node *node=cityPair.second;

			for(auto nbr:node->nbrs){
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}

};

int main()
{
	vector<string>cities={"delhi","london","paris","new york"};
	Graph g(cities);

	g.addEdge("delhi","london");
	g.addEdge("new york","london");
	g.addEdge("delhi","paris");
	g.addEdge("paris","new york");

	g.printAdjList();
	return 0;
}