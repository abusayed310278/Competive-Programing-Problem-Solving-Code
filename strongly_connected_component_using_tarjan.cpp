#include<bits/stdc++.h>
using namespace std;


//using tarjan algorithms
class Solution
{
	int V,E;
	list<int>*l;
	bool *visited;
	int *low;
	int *dfssum;
	int *onStack;
	stack<int>q;
	int num=1;
	int scc=0;
public:

	Solution(int v,int e){
		this->V=v;
		this->E=e;
		l=new list<int>[V];
		visited=new bool[V]{false};
		low=new int[V]{-1};
		dfssum=new int[V]{-1};
		onStack=new int[V];
		
	}

	//dfs 

	void tarjanAlgo(int src)
	{
		low[src]=dfssum[src]=num++;
		visited[src]=onStack[src]=true;
		q.push(src);

		for(auto nbr:l[src]){

			if(!visited[nbr]){
				tarjanAlgo(nbr);
				if(onStack[nbr]==true)low[src]=min(low[nbr],low[src]);
			
			}else if(visited[nbr] && onStack[nbr]){
				low[src]=min(low[src],dfssum[nbr]);
				
			}
		}

		 int v;
	     if(low[src]==low[src]){
	        scc++;
	        cout<<"scc#:"<<scc<<" ";
	        while(1)
	        {
	            v=q.top();
	            q.pop(),onStack[v]=false;
	            cout<<v<<" ";
	            if(src==v)break;
	        }
	        cout<<endl;
	     } 


	}

	//driected graph for strongly connected component
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
	}

	void print()
	{	
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(auto nbr:l[i]){
				cout<<nbr<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int v,e;cin>>v>>e;
	
	Solution ob(v,e);

	while(e--){
		int x,y;cin>>x>>y;
		ob.addEdge(x,y);
	}

	ob.tarjanAlgo(0);
	//ob.print();

	return 0;
}

/*

4 5
0 1
0 3
1 2
2 0
2 3

*/