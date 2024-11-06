#include<bits/stdc++.h>
using namespace std;

 int change(vector<int>& coins, int m)
 {      

	int way=0;
	//find the coins returnd by the greedy strategy

	for(int cur=0;cur<=coins.size()-1;cur++){
		
		while(m-coins[cur] < m)m-=coins[cur];

		(m-coins[cur] > m)cur++;


		if(m==0)++way;
	}
	
	return way?way:0;
 	   
 }

int main()
{
	freopen("in.txt","r",stdin);	
	freopen("out.txt","w",stdout);

 	vector<int>coins;
 	int t;cin>>t;
 	while(t--){
 		int m,n;cin>>m>>n;
 		for(int i=0;i<n;i++)
 		{
 			int x;cin>>x;
	 		coins.push_back(x);
 		}
 		cout<<change(coins,m)<<endl;
 	}
	return 0;
}