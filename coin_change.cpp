#include<bits/stdc++.h>
using namespace std;

 int change(vector<int>& coins, int amount)
 {      

	//int cur=coins.size()-1;
	//vector<int>coinsGiven;
	int i=0;
	//find the coins returnd by the greedy strategy

	for(int cur=coins.size()-1;cur>=0;cur--){
		while(amount >0 && cur >=0)
		{
			while(cur >=0 && coins[cur] >amount)cur--;
				
				amount-=coins[cur];
				//coinsGiven.push_back(coins[cur]);

				
			
		}
		if(amount==0)++i;
	}
	/*
		for(int i=0;i<coinsGiven.size();i++)
			cout<<coinsGiven[i]<<" ";
		cout<<endl;

	*/
	return i?i:0;
 	   
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