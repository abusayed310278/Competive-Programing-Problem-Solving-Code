#include<bits/stdc++.h>
using namespace std;

class Solution
{
	int V,E,w;
	list<pair<int,int>>*l;
public:

	Solution(int v,int e){
		this->V=v;
		this->E=e;
		l=new list<pair<int,int>>[V];
	}

	/*int tarjanAlgo()
	{

	}*/

	void addEdge(int x,int y,int w)
	{
		l[x].push_back(make_pair(y,w));
		l[y].push_back(make_pair(x,w));
	}

	void print()
	{	
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			//auto nbrs=l[i];
			for(auto nbr:l[i]){
				cout<<"("<<nbr.first<<" "<<nbr.second<<")"<<",";
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
		int x,y,w;cin>>x>>y>>w;
		ob.addEdge(x,y,w);
	}

	ob.print();

	return 0;
}

/*

4 5
0 1 10
0 2 30
0 3 50
1 2 20
2 3 40


*/