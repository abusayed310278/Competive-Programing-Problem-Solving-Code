#include<bits/stdc++.h>
using namespace std;

void stocks(vector<int>&arr){

	// int mini=arr[0],profit=0;
	int mini=INT_MAX,profit=0;
	for(int i=1; i<arr.size(); i++){
		// int cost=arr[i]-mini;
		mini=min(mini,arr[i]);
		profit=max(profit,arr[i]-mini);
		// mini=min(mini,arr[i]);
	}
	cout<<profit<<endl;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	vector<int>arr{7,1,5,3,6,4};
	stocks(arr);
	return 0;
}