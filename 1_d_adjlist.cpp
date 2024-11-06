#include<bits/stdc++.h>
using namespace std;

class Solution
{
	int V,E,w;
	vector<pair<int,int>>*l;
public:

	Solution(int v,int e){
		this->V=v;
		this->E=e;
		l=new vector<pair<int,int>>[V+1];
	}

	/*int tarjanAlgo()
	{

	}*/

	void addEdge(int x,int y,int w)
	{
		l[x].push_back(make_pair(y,w));
		//l[y].push_back(make_pair(x,w));
	}

	void print()
	{	
		for(int i=1;i<=V;i++){
			cout<<i<<"->";
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
1 2 10
1 3 20
1 4 30
2 3 40
4 3 50


*/