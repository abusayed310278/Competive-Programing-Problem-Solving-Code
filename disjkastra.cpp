#include<bits/stdc++.h>

using namespace std;



class Graph{
	int n;
	list<pair<int,int>>*g;
public:
	Graph(int n){
		this->n=n;
		g=new list<pair<int,int>>[n];
	}
	void addEdge(int u,int v,int w){
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}

	int dijkastra(int src,int dest)
	{
		vector<int>dist(n,INT_MAX);
		set<pair<int,int>>s;

		dist[src]=0;
		s.insert({0,src}); //weight,nodeNumber

			while(!s.empty())
			{
				auto it=s.begin();
				int distTillNow=it->first;
				int node=it->second;
				s.erase(it);

				for(auto nbrPair: g[node]){
					int currentEdgeWeight=nbrPair.first;
					int nbr=nbrPair.second; //vertex

					if(distTillNow+currentEdgeWeight <dist[nbr]){
						auto f=s.find({dist[nbr],nbr});
						if(f!=s.end()){
							s.erase(f);
						}
						dist[nbr]=distTillNow+currentEdgeWeight;
						s.insert({dist[nbr],nbr});
					}
				}

			}

			for(int i=0;i<n-1;i++){
				cout<<"Node i "<<i<<" Dist "<<dist[i]<<endl;
			}

		
		return dist[dest];
	}
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;cin>>n;
	Graph ob(n);

	while(n--){
		int x,y,w;cin>>x>>w>>y;
		ob.addEdge(x,y,w);	
	}

	cout<<ob.dijkastra(0,4);

	return 0;
}

/*

6
0 1 1 
0 4 2 
0 7 3
1 1 2
2 2 3
3 3 4
x w y


*/
