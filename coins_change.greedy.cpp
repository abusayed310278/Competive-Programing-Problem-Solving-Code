#include<bits/stdc++.h>
using namespace std;


int main()
{
	vector<int>coins={1,2,5,10};
	int amount=9;

	int curCoin=coins.size()-1;
	vector<int>coinsGiven;

	//find the coins returnd by the greedy strategy

	while(amount >0 && curCoin >=0)
	{
		while(curCoin >=0 && coins[curCoin] >amount)curCoin--;
			
			amountt-=coins[curCoin];
			coinsGiven.push_back(coins[curCoin]);
		
	}


	for(int i=0;i<coinsGiven.size();i++)
		cout<<coinsGiven[i]<<" ";
	cout<<endl;

	return 0;
}