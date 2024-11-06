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
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	int primsMst()
	{
		
		int key[n];
		bool mSet[n];
		memset(key,INT_MAX,sizeof(key));
		memset(mSet,false,sizeof(mSet));

		key[0]=0;
		int res=0;

		for(int count=0;count<n;count++){
			int u=-1;
			for(int i=0;i<n;i++){
				if(!mSet[i] && u==-1 || key[i] <key[u])
					u=i;
			}
			mSet[u]=true;
			res+=key[u];
			

			for(int i=0;i<n;i++){
				
				if(g[u][i]!=0 && !mSet[i])
					key[i]=min(key[i],g[u][i]);
			}

		}
		return res;

	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int n;cin>>n;
	Graph ob(n);

	while(n--){
		int x,y,w;cin>>x>>y>>w;
		ob.addEdge(x,y,w);	
	}

	/*g.addEdge(adj,0,1);
	g.addEdge(adj,0,2);
	g.addEdge(adj,1,2);
	g.addEdge(adj,1,3);*/

	cout<<ob.primsMst();

	return 0;
}